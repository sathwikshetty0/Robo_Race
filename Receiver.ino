#include <esp_now.h>
#include <WiFi.h>
#include <ESP32Servo.h>

#define SIGNAL_TIMEOUT 1000  // This is signal timeout in milli seconds. We will reset the data if no signal

unsigned long lastRecvTime = 0;

typedef struct PacketData
{
  byte lxAxisValue;
  byte lyAxisValue;  
  
}PacketData;
PacketData receiverData;

Servo servo;     
Servo esc;         

//Assign default input received values
void setInputDefaultValues()
{
  // The middle position for joystick. (254/2=127)
  receiverData.lxAxisValue = 127;
  receiverData.lyAxisValue = 127;   
}

void mapAndWriteValues()
{
  esc.write(map(receiverData.lxAxisValue, 0, 254, 0, 180));
  servo.write(map(receiverData.lyAxisValue, 0, 254, 0, 180));
}

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) 
{
  if (len == 0)
  {
    return;
  }
  memcpy(&receiverData, incomingData, sizeof(receiverData));

  String inputData ;
  inputData = inputData + "values " + receiverData.lxAxisValue + "  " + receiverData.lyAxisValue ;
  Serial.println(inputData);

  mapAndWriteValues();  
  lastRecvTime = millis(); 
}

void setUpPinModes()
{
  servo.attach(27, 1000, 2000);
  esc.attach(26, 1000, 2000);

  setInputDefaultValues();
  mapAndWriteValues();
}

void setup() 
{
  setUpPinModes();
 
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) 
  {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
}
 


void loop()
{
  //Check Signal lost.
  unsigned long now = millis();
  if ( now - lastRecvTime > SIGNAL_TIMEOUT ) 
  {
    setInputDefaultValues();
    mapAndWriteValues();  
  }
}