#include "pitches.h"
#include "arduino.h"

#define ScoreValues 4
#define MaxString 16
#define MaxLength 50

class scores
{
private:
    // ブザーを鳴らすピン
    int buzzerPin;
    // 曲番
    int scoreNo;

    // 音の配列
    int melody[ScoreValues][MaxLength]=
    {
        // 帝国のマーチ A メロ
        {NOTE_G3, NOTE_G3, NOTE_G3, NOTE_DS3, NOTE_AS3, NOTE_G3, NOTE_DS3, NOTE_AS3, NOTE_G3,NOTE_D4, NOTE_D4, NOTE_D4, NOTE_DS4, NOTE_AS3, NOTE_FS3, NOTE_DS3, NOTE_AS3, NOTE_G3,-1}
        ,{
  NOTE_C4, NOTE_C4,NOTE_G4, NOTE_G4, NOTE_A4,NOTE_A4, NOTE_G4, 
  NOTE_F4, NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4, 
  NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
  NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
  NOTE_C4, NOTE_C4,NOTE_G4, NOTE_G4, NOTE_A4,NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4,-1}
        ,{
 NOTE_E4, NOTE_E4,0,NOTE_E4,0, 
 NOTE_C4, NOTE_E4,0,NOTE_G4,0,0,0,NOTE_G3,-1}
        ,{
 NOTE_G4, NOTE_F4,0,NOTE_F4,NOTE_F4, 
 NOTE_E4,0,NOTE_D4,NOTE_C4,0,NOTE_G4,0,NOTE_C4,-1}
    };
    // ピッチ
    // 音の長さ 2, 4, 8 はそれぞれ 2分音符、4分音符、8分音符
    int noteDurations[ScoreValues][MaxLength]=
    {
        // 帝国のマーチ A メロ
        {4, 4, 4, 6, 8, 4, 6, 8, 2,4, 4, 4, 6, 8, 4, 6, 8, 2}
        ,{
  4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,
  4,4,4,4,4,4,2, 
  4,4,4,4,4,4,2}
        ,{8,8,8,8,8,8,8,8,8,8,8,8,8}
        ,{ 8,8,8,8,8,8,8,8,8,8,8,8,8,4}
    };
    // 曲名
    char scoreName[ScoreValues][MaxString]=
    {
        "Teikoku"
        ,"KiraKira"
        ,"Mario"
        ,"MarioDie"
    };

public:
    // コンストラクタによる初期化
    scores::scores(int BuzzerPin){
        buzzerPin = BuzzerPin;
        scoreNo = 0;
    }

    // 曲番を設定
    void setScoreNo(int argScoreNo)
    {
        scoreNo = argScoreNo - 1;
        
        if (scoreNo >= ScoreValues){
            scoreNo = ScoreValues - 1;
        }
        if (scoreNo < 0){
            scoreNo = 0;
        }

        return;
    }

    // 次の曲に変更する
    void nextScoreNo(){
        scoreNo++;
        if(scoreNo >= ScoreValues){
            scoreNo = 0;
        }

        return;
    }

    // 曲名を返す
    char* getScoreName(){
        return scoreName[scoreNo];
    }

    // 曲を鳴らす
    void playSound(){
        for (int thisNote = 0; melody[scoreNo][thisNote] != -1; thisNote++) {
            int noteDuration = 1000 / noteDurations[scoreNo][thisNote];
            tone(buzzerPin, melody[scoreNo][thisNote], noteDuration);
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);
            noTone(buzzerPin);
        }

        return;
    }
};
