#include <stdio.h>
#include <stdlib.h>

int const numOfSensors = 2;
int sensorPin[numOfSensors] = {A0, A1};
int sensorValues[numOfSensors];
int photodiodeMap[numOfSensors];

void setup(void)
{
  Serial.begin(9600);
  pinMode(sensorPin[0], INPUT);
  pinMode(sensorPin[1], INPUT);

  // initialize photodiode prev reading to 0
  for (int i = 0; i < numOfSensors; i++) {
    sensorValues[i] = 0;
    photodiodeMap[i] = sensorValues[i];
  }
}

void loop()
{
  // photodiode input extraction
  for (int i = 0; i < numOfSensors; i++) {
    sensorValues[i] = analogRead(sensorPin[i]);
    photodiodeMap[i] = sensorValues[i];
//    Serial.print(sensorValues[0]);
//    Serial.print(" ");
//    Serial.println(sensorValues[1]);
  }

  if(photodiodeMap[1]-photodiodeMap[0]<=1 && photodiodeMap[1]-photodiodeMap[0]>=-1){
    Serial.println("Dont move");
  } else if ((photodiodeMap[1]-photodiodeMap[0])>=1) {
    Serial.println("Move to 1");
  } else if ((photodiodeMap[0]-photodiodeMap[1])>=1) {
    Serial.println("Move to 0");
  }
}
