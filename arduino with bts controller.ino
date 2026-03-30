// ============================================================
//  2-Wheel Soccer Bot  |  FlySky FS-i6  |  BTS7960 x2
//  FIXED — both channels read simultaneously (no missed pulses)
//
//  WHY THE FIX: pulseIn() reads one channel at a time and blocks
//  for up to 25ms per channel. By the time CH2 finishes, the
//  CH4 pulse has already passed → CH4 always returns centre →
//  steering never works. This version reads both at the same
//  time using a loop that watches both pins together.
//
//  Wiring - Receiver:
//    CH2 signal → A0
//    CH4 signal → A1
//    Receiver GND → Arduino GND
//    Receiver 5V  → Arduino 5V
//
//  Wiring - Left motor BTS7960:
//    RPWM → pin 5,  LPWM → pin 6
//    R_EN → pin 7,  L_EN → pin 8
//
//  Wiring - Right motor BTS7960:
//    RPWM → pin 9,  LPWM → pin 10
//    R_EN → pin 11, L_EN → pin 12
//
//  Wiring - Power (11.1V LiPo):
//    Battery + → Buck converter → 5V → Arduino 5V
//    Battery + → BTS7960 B+ (both drivers, direct)
//    All GNDs joined together
// ============================================================

// ── Receiver pins ────────────────────────────────────────────
#define CH2_PIN  A0       // forward / backward
#define CH4_PIN  A1       // left / right

// ── Left motor ───────────────────────────────────────────────
#define L_RPWM   5
#define L_LPWM   6
#define L_R_EN   7
#define L_L_EN   8

// ── Right motor ──────────────────────────────────────────────
#define R_RPWM   9
#define R_LPWM   10
#define R_R_EN   11
#define R_L_EN   12

// ── Confirmed calibrated values ──────────────────────────────
const int CH2_MIN    =  997;
const int CH2_CENTER = 1496;
const int CH2_MAX    = 1988;

const int CH4_MIN    =  997;
const int CH4_CENTER = 1496;
const int CH4_MAX    = 1988;

// ── Tuning ───────────────────────────────────────────────────
const int DEADBAND  =  40;
const int MAX_SPEED = 255;
const unsigned long TIMEOUT = 25000; // 25ms timeout in microseconds

// ── Read BOTH channels at the same time ─────────────────────
// Waits for both pins to go HIGH, then measures both pulse
// widths together — neither channel misses the other's pulse.
void readChannels(int &ch2, int &ch4) {
  unsigned long ch2Start = 0, ch4Start = 0;
  unsigned long ch2Pulse = 0, ch4Pulse = 0;
  bool ch2Done = false, ch4Done = false;
  bool ch2High = false, ch4High = false;

  unsigned long startWait = micros();

  // Wait for both pulses and measure them simultaneously
  while ((!ch2Done || !ch4Done) && (micros() - startWait < TIMEOUT * 2)) {
    bool ch2State = digitalRead(CH2_PIN);
    bool ch4State = digitalRead(CH4_PIN);

    // CH2 rising edge
    if (ch2State && !ch2High) {
      ch2Start = micros();
      ch2High = true;
    }
    // CH2 falling edge
    if (!ch2State && ch2High && !ch2Done) {
      ch2Pulse = micros() - ch2Start;
      ch2Done = true;
    }

    // CH4 rising edge
    if (ch4State && !ch4High) {
      ch4Start = micros();
      ch4High = true;
    }
    // CH4 falling edge
    if (!ch4State && ch4High && !ch4Done) {
      ch4Pulse = micros() - ch4Start;
      ch4Done = true;
    }
  }

  // If a channel timed out return its centre value (failsafe)
  ch2 = ch2Done ? constrain((int)ch2Pulse, CH2_MIN, CH2_MAX) : CH2_CENTER;
  ch4 = ch4Done ? constrain((int)ch4Pulse, CH4_MIN, CH4_MAX) : CH4_CENTER;
}

// ── Convert raw PWM to signed speed (-255 … +255) ───────────
int pwmToSpeed(int raw, int minVal, int centre, int maxVal) {
  int offset = raw - centre;
  if (abs(offset) < DEADBAND) return 0;
  if (offset > 0)
    return map(offset, DEADBAND, maxVal - centre, 0, MAX_SPEED);
  else
    return map(offset, -(centre - minVal), -DEADBAND, -MAX_SPEED, 0);
}

// ── Drive one BTS7960 ────────────────────────────────────────
void driveMotor(int rpwm, int lpwm, int speed) {
  speed = constrain(speed, -MAX_SPEED, MAX_SPEED);
  if (speed > 0) {
    analogWrite(rpwm, speed);
    analogWrite(lpwm, 0);
  } else if (speed < 0) {
    analogWrite(rpwm, 0);
    analogWrite(lpwm, -speed);
  } else {
    analogWrite(rpwm, 0);
    analogWrite(lpwm, 0);
  }
}

// ════════════════════════════════════════════════════════════
void setup() {
  pinMode(CH2_PIN, INPUT);
  pinMode(CH4_PIN, INPUT);

  pinMode(L_RPWM, OUTPUT); pinMode(L_LPWM, OUTPUT);
  pinMode(L_R_EN, OUTPUT); pinMode(L_L_EN, OUTPUT);
  digitalWrite(L_R_EN, HIGH); digitalWrite(L_L_EN, HIGH);

  pinMode(R_RPWM, OUTPUT); pinMode(R_LPWM, OUTPUT);
  pinMode(R_R_EN, OUTPUT); pinMode(R_L_EN, OUTPUT);
  digitalWrite(R_R_EN, HIGH); digitalWrite(R_L_EN, HIGH);
}

// ════════════════════════════════════════════════════════════
void loop() {
  int ch2Raw, ch4Raw;
  readChannels(ch2Raw, ch4Raw);  // read both at the same time

  int throttle = pwmToSpeed(ch2Raw, CH2_MIN, CH2_CENTER, CH2_MAX);
  int steering = pwmToSpeed(ch4Raw, CH4_MIN, CH4_CENTER, CH4_MAX);

  int leftSpeed  = constrain(throttle + steering, -MAX_SPEED, MAX_SPEED);
  int rightSpeed = constrain(throttle - steering, -MAX_SPEED, MAX_SPEED);

  driveMotor(L_RPWM, L_LPWM, leftSpeed);
  driveMotor(R_RPWM, R_LPWM, rightSpeed);
}
