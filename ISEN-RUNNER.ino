#include <ISEN.h>
#include <LabIsen-2009.h>
#include<ISL12026.h>
#include <MCP23X08.h>
// Include Arduinolibraries
#include <LiquidCrystal.h>
#define LED_VERTE 2
#define LED_ORANGE 9
int compteur_cactus = 16;
int debut=0;
int points = 0;
int bljump;

byte dino[8]={
      B00000,
      B00000,
      B00011,
      B00011,
      B10110,
      B11110,
      B11110,
      B01010,
};

byte dinojp[8]={
      B00000,
      B00000,
      B00011,
      B00011,
      B10110,
      B11110,
      B11111,
      B01000,
};

byte cactus[8]={
      B00100,
      B00101,
      B10101,
      B10101,
      B10101,
      B01111,
      B00100,
      B00100
};
ISENLiquidCrystal lcd;

void setup() {
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_VERTE, INPUT);
  lcd.createChar(2,dino);
  lcd.createChar(1,cactus);
  lcd.createChar(3,dinojp);
  lcd.begin(16,2);
  debut = 0;
  
}

void loop() {
  if (debut == 0){
    start();
    debut = 1; 
  }
  lcd.setCursor(0,1);
  lcd.write(2); 
  Saut();
  Cactus();
  delay(500);
  lcd.clear();
  if(16 == compteur_cactus){
    Game_Over();
    delay(500);
    lcd.clear();
  }
}
void Cactus(){
  compteur_points();
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.write(2);
  compteur_points();
  while(compteur_cactus != 0){
    lcd.setCursor(compteur_cactus,1);
    lcd.write(1);
    delay(500);
    compteur_cactus--;
    lcd.clear();
    bljump=1;
    Saut();
  }
  if(bljump==1){
    Game_Over();
    delay(500);
    debut=0;
    lcd.clear();
  }
  if(compteur_cactus == 0){
    compteur_cactus = 16;
  }
}
void Saut(){
  
  digitalWrite(LED_ORANGE,HIGH);
  if (digitalRead(LED_VERTE)==LOW) {
    bljump=0;
    lcd.setCursor(0,0);
    lcd.write(3);
    lcd.setCursor(compteur_cactus,1);
    lcd.write(1);
    delay(750);
    Cactus();
    lcd.setCursor(compteur_cactus,1);
    compteur_cactus++;
    lcd.write(1);
    lcd.clear();
    bljump=0;
    digitalWrite(LED_ORANGE,LOW);
  }
  if (digitalRead(LED_VERTE)==HIGH) {
    lcd.setCursor(0,1);
    lcd.write(2);
    compteur_points();
  }
}
void Game_Over(){
  lcd.clear();
  int compteur = 4;
  while(compteur != 0){
      lcd.setCursor(5,0);
      lcd.print("GAME");
      lcd.setCursor(5,1);
      lcd.print("OVER");
      compteur--;
      points = 0;
      delay(500);
  }
}  
void start(){
  lcd.clear();
  while(digitalRead(LED_VERTE) != LOW){
      lcd.setCursor(2,0);
      lcd.print("Press button");
      lcd.setCursor(3,1);
      lcd.print("to start !");
      delay(1000);
      lcd.clear();
      delay(500);
  }
}
void compteur_points(){
  lcd.setCursor(12,0);
  lcd.print(points);
  points++;
}
