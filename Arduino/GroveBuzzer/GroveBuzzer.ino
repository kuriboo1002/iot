#include "scores.cpp"
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

// ブザーを接続するピン 今回は D8 に接続
#define buzzerPin 8
#define pushButton 4
char* scoreName;
scores score(buzzerPin);
int i;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.print("hello, world!");
  
}
 
void loop() {

    int buttonState = digitalRead(pushButton);
    Serial.println(buttonState);

    if(buttonState != 1) return;

    Serial.println(score.getScoreName());
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(score.getScoreName());
    score.playSound();
    score.nextScoreNo();

}
