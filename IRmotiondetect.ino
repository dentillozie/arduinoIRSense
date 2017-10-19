//#include "Mouse.h"

// set pin numbers for switch, joystick axes, and LED:
const int switchPin = 2;      // switch to turn on and off mouse control
const int mouseButton = 3;    // input pin for the mouse pushButton
const int xAxis = A0;         // joystick X axis
const int yAxis = A1;         // joystick Y axis
const int ledPin = 13; 
// Mouse control LED
int PrevAnalog0;
int PrevAnalog1;
int PrevAnalog2;
int PrevAnalog3;
String way="none";

int sensitivity = 20; //the lower the more sensitive

bool triggered = false;


void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT);       // the switch pin
  pinMode(ledPin, OUTPUT);         // the LED pin
  // take control of the mouse:
  //Mouse.begin();
  PrevAnalog0 = analogRead(A0);
  PrevAnalog1 = analogRead(A1);
  PrevAnalog2 = analogRead(A2);
  PrevAnalog3 = analogRead(A3);
}

void loop() {
  //Serial.print("A0: ");
  //Serial.println(analogRead(A0));
  //Serial.print("A1: ");
  //Serial.println(analogRead(A1));
  //Serial.print("A2: ");
  //Serial.println(analogRead(A2));
  //Serial.print("A3: ");
  //Serial.println(analogRead(A3));
  delay(50);
  way="none";
  //trigger();
  checkWay();
  
}

String checkWay()
{
  if(analogRead(A0) < PrevAnalog0 - sensitivity)
  {
    triggered = true;
    int count = 0;
    while(count < 300)
    {
      if(analogRead(A3) < PrevAnalog3 - sensitivity  )
      {
        way="Left";
        Serial.println(way);
      }
      count++;
      delay(1);
    }
  }
  
  if(analogRead(A3) < PrevAnalog3 - sensitivity)
  {
    triggered = true;
    int count = 0;
    while(count < 300)
    {
      if(analogRead(A0) < PrevAnalog0 - sensitivity)
      {
        way="Right";
        Serial.println(way);
      }
      count++;
      delay(1);
    }
  }  
  
  PrevAnalog0 = analogRead(A0);
  PrevAnalog1 = analogRead(A1);
  PrevAnalog2 = analogRead(A2);
  PrevAnalog3 = analogRead(A3);
  return(way);
}


bool trigger(int analogPin)
{
  
}
