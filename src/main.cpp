#include <Arduino.h>

// put function declarations here:
int ledPin_1[]{23, 19, 18};
int ledPin_2[]{17, 16, 4};
int SwPin = 15;

void setup()
{
  // put your setup code here, to run once:
  pinMode(SwPin, INPUT);
  for (int i = 0; i < 3; i++)
  {
    pinMode(ledPin_1[i], OUTPUT);
  }
  for (int i = 0; i < 3; i++)
  {
    pinMode(ledPin_2[i], OUTPUT);
  }
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(ledPin_1[i], LOW);
  }
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(ledPin_2[i], LOW);
  }
}
int h = 0;
void loop()
{
  while (h == 0)
  {

    digitalWrite(ledPin_1[0], HIGH);
    digitalWrite(ledPin_1[1], LOW);
    digitalWrite(ledPin_1[2], LOW);

    digitalWrite(ledPin_2[0], LOW);
    digitalWrite(ledPin_2[1], LOW);
    digitalWrite(ledPin_2[2], HIGH);

    delay(1000);

    digitalWrite(ledPin_1[0], LOW);
    digitalWrite(ledPin_1[1], HIGH);
    digitalWrite(ledPin_1[2], LOW);

    digitalWrite(ledPin_2[0], LOW);
    digitalWrite(ledPin_2[1], HIGH);
    digitalWrite(ledPin_2[2], LOW);

    delay(1000);

    digitalWrite(ledPin_1[0], LOW);
    digitalWrite(ledPin_1[1], LOW);
    digitalWrite(ledPin_1[2], HIGH);

    digitalWrite(ledPin_2[0], HIGH);
    digitalWrite(ledPin_2[1], LOW);
    digitalWrite(ledPin_2[2], LOW);

    delay(1000);

    while (digitalRead(SwPin) == HIGH)
    {
      h = 1;
    }
  }
  while (h == 1)
  {
    digitalWrite(ledPin_1[0], LOW);
    digitalWrite(ledPin_1[1], LOW);
    digitalWrite(ledPin_1[2], LOW);

    digitalWrite(ledPin_2[0], LOW);
    digitalWrite(ledPin_2[1], LOW);
    digitalWrite(ledPin_2[2], LOW);
    delay(500);

    digitalWrite(ledPin_1[0], HIGH);
    digitalWrite(ledPin_1[1], HIGH);
    digitalWrite(ledPin_1[2], HIGH);

    digitalWrite(ledPin_2[0], HIGH);
    digitalWrite(ledPin_2[1], HIGH);
    digitalWrite(ledPin_2[2], HIGH);
    delay(500);

    while (digitalRead(SwPin) == HIGH)
    {
      h = 0;
    }
  }
}