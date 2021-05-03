#include <Arduino.h>

int A = 7;   //Defines all pins on the Arduino Uno board in order of connection.
int B = 6;
int C = 4;  // DOT is pin 5, not used in this example.
int D = 3;
int E = 2;
int F = 8;
int G = 9;

int pins[7] = {A, B, C, D, E, F, G};

// Used in displaying 0-9
int displays[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}, // 9
};

// starts 0 to 9 
void countUp(int displays[10][7]) {
  for (int i = 0; i < 10; i++) {
    Serial.println("");
    for (int j = 0; j < 7; j++) {
      Serial.print(displays[i][j]);
      if (displays[i][j]) {
        digitalWrite(pins[j], HIGH);
      } else {
        digitalWrite(pins[j], LOW);
      }
    }
    delay(500);
  }
}

// just a reverse of #countUp
void countDown(int displays[10][7]) {
  for (int i = 9; i > -1; i--) {
    Serial.println("");
    for (int j = 6; j > -1; j--) {
      Serial.print(displays[i][j]);
      if (displays[i][j]) {
        digitalWrite(pins[j], HIGH);
      } else {
        digitalWrite(pins[j], LOW);
      }
    }
    delay(500);
  }
}

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  countUp(displays);
}
 
