#include <SevSeg.h>
SevSeg sevseg;
int i=0;

double sensorV=0;
int sensorval=0;
const byte led7=7;
const byte sw=6;
const byte potPin=14;

void setup() {
  byte numDigits=1;
  pinMode(led7,OUTPUT);
  pinMode(sw,INPUT);
  byte digitPins[]={13};
  byte segmentPins[]={12,2,3,4,5,17,16,15};
  sevseg.begin(COMMON_CATHODE,numDigits,digitPins,segmentPins);
  Serial.begin(9600);

}

void loop() {
  sensorval=analogRead(potPin);
  Serial.print(sensorval);
  sensorV=sensorval*2.5/4095;
  Serial.println(sensorV);
  bool val=digitalRead(sw);
  if(val)
  {    
    digitalWrite(led7,HIGH);
    delay(500);
    digitalWrite(led7,LOW);
    delay(500);
    
    }
  else
    {
      static unsigned long timer=millis();
      if(millis()>=timer)
      {
         timer+=500;
         sevseg.setNumber(i);
          i=i+1;
         if(i==10)
          {
            i=0;
          }

      }
      sevseg.refreshDisplay();    
    }
}
