#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define echoPin 2  
#define trigPin 3  
#define ledvPin 13
#define ledgPin 12
#define ledrPin 8
#define buzzerPin 6
#define OLED_RESET 4
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
long duration;  
int distance;   
void setup() {
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);   
  pinMode(ledvPin, OUTPUT);
  pinMode(ledgPin, OUTPUT);
  pinMode(ledrPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); 
}

void drawPercentbar(int x, int y, int width, int height, int progress) {
  progress = progress > 100 ? 100 : progress;
  progress = progress < 0 ? 0 : progress;
  float bar = ((float)(width - 4) / 100) * progress;
  display.drawRect(x, y, width, height, WHITE);
  display.fillRect(x + 2, y + 2, bar, height - 4, WHITE);
  if (height >= 15) {
    display.setCursor((width / 2) - 3, y + 5);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    if (progress >= 50)
      display.setTextColor(BLACK, WHITE);
  }
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  
  Serial.print("Distanta: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance < 450 && distance > 50) {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledvPin, HIGH);
    delay(200);
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledrPin, LOW);
    digitalWrite(ledgPin, LOW);
    digitalWrite(ledvPin, LOW);
    delay(800);
  } else if (distance < 50 && distance > 15) {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledgPin, HIGH);
    delay(200);
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledrPin, LOW);
    digitalWrite(ledgPin, LOW);
    digitalWrite(ledvPin, LOW);
    delay(400);
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledrPin, HIGH);
    delay(200);
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledrPin, LOW);
    digitalWrite(ledgPin, LOW);
    digitalWrite(ledvPin, LOW);
    delay(100);
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("SENZOR DE PROXIMITATE");
  display.setCursor(20, 15);
  display.print("Distanta: ");
  display.print(distance);
  display.print(" cm");
  drawPercentbar(0, 25, 128, 7, distance);
  display.display();
}