#include <TheThingsNetwork.h>
#include <TheThingsMessage.h>

// Set your AppEUI and AppKey
const char *appEui = "0202020202020202";
const char *appKey = "5B5C80343C7A88999B231AA9BA6B8871";

long instance1=0, timer;
double hrv =0, hr = 72, interval = 0;
int value = 0, count = 0, cpt = 0;  
bool flag = 0;
byte payload[1];

#define loraSerial Serial1
#define debugSerial Serial
#define shutdown_pin 10 
#define threshold 100 // to identify R peak
#define timer_value 10000 // 10 seconds timer to calculate hr
#define freqPlan TTN_FP_EU868

TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);
devicedata_t data = api_DeviceData_init_default;

void setup() {
  loraSerial.begin(57600);
  debugSerial.begin(9600);
  while (!debugSerial && millis() < 10000)
    ;
  debugSerial.println("-- STATUS");
  ttn.showStatus();
  debugSerial.println("-- JOIN");
  ttn.join(appEui, appKey);
  Serial.begin(9600);
  pinMode(8, INPUT); 
  pinMode(9, INPUT); 
}
void loop() {
  cpt = cpt + 1;
  if((digitalRead(8) == 1)||(digitalRead(9) == 1)){
    Serial.println("leads off!");
    digitalWrite(shutdown_pin, LOW); 
    instance1 = micros();
    timer = millis();
  }
  else {
    digitalWrite(shutdown_pin, HIGH); 
    value = analogRead(A1);
    value = map(value, 250, 400, 0, 100); 
    if((value > threshold) && (!flag)) {
      count++;  
      flag = 1;
      interval = micros() - instance1; 
      instance1 = micros(); 
    }
    else if((value < threshold)) {
      flag = 0;
    }
    if ((millis() - timer) > 10000) {
      hr = count*6;
      payload[0] = hr;
      Serial.println(payload[0]);
      ttn.sendBytes(payload, sizeof(payload));
      timer = millis();
      count = 0; 
    }
    hrv = hr/60 - interval/1000000;
    Serial.print(hr);
    Serial.print(",");
    Serial.print(hrv);
    Serial.print(",");
    Serial.println(value);
    delay(10);
  }
}