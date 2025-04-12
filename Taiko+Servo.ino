#include <Adafruit_GFX.h>       // include Adafruit graphics library
#include <Adafruit_ILI9341.h>   // include Adafruit ILI9341 TFT library
#include <Servo.h>

#include <Fonts/FreeMonoBold9pt7b.h>

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55                                                                                             
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


int melody[] = {  //325 - 49 = 276  //每個音符的發聲頻率

  // Super Mario Bros theme
  // Score available at https://musescore.com/user/2123/scores/2145
  // Theme by Koji Kondo
  
  REST,REST,REST,REST,NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5, //1
  NOTE_G5, REST, NOTE_G4,REST, 
  NOTE_C5, NOTE_G4, REST, NOTE_E4, // 3
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4,
  NOTE_C5, NOTE_G4, REST, NOTE_E4, // repeats from 3
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4,

  
  REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5,//7
  REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
  REST, NOTE_DS5, REST, NOTE_D5,
  NOTE_C5, REST,

  REST,NOTE_G5, NOTE_FS5,NOTE_F5, NOTE_DS5, NOTE_E5,//repeats from 7
  REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
  REST, NOTE_DS5, REST, NOTE_D5,
  NOTE_C5, REST,

  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,//11
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,

  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5,//13
  REST, 
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  NOTE_G5, REST, NOTE_G4, REST, 
  NOTE_C5, NOTE_G4, REST, NOTE_E4, // 19
  
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,

  NOTE_C5, NOTE_G4, REST, NOTE_E4, // repeats from 19
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,

  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,//23
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
  
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4, //26
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5,NOTE_D5,
  NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,

  NOTE_E5, NOTE_C5, NOTE_G4,REST, NOTE_GS4,//repeats from 23
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
  
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4, //26
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5,
  REST,

  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, //33
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_E5, REST,NOTE_E5, REST, NOTE_C5, NOTE_E5,
  NOTE_G5, REST, NOTE_G4, REST, 
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
  
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4, //40
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
  
  //game over sound
  NOTE_C5, NOTE_G4, NOTE_E4, //45
  NOTE_A4, NOTE_B4, NOTE_A4, NOTE_GS4, NOTE_AS4, NOTE_GS4,
  NOTE_G4, NOTE_D4, NOTE_E4,  

};

int rhythm[] = {  //每個音符的發聲時長  //八分音符:10 四分音符:20 二分音符:40 全音符:80 負點四分音符:25  
  30,30,30,30,10,10,10,10,10,10,10,20,20,10,20,30,10,20,30,20,20,10,20,15,
  15,15,20,10,10,10,20,10,10,30,30,10,20,30,20,20,10,20,15,15,
  15,20,10,10,10,20,10,10,30,20,10,10,10,20,10,10,10,10,10,10,
  10,10,10,20,20,10,30,40,40,20,10,10,10,20,10,10,10,10,10,10,
  10,10,10,20,20,10,30,40,40,10,20,10,10,10,20,10,20,10,40,10,
  20,10,10,10,10,10,80,10,20,10,10,10,20,10,20,10,40,10,10,10,
  10,10,10,20,20,20,20,20,30,10,20,30,20,20,10,20,15,15,15,20,
  10,10,10,20,10,10,30,30,10,20,30,20,20,10,20,15,15,15,20,10,
  10,10,20,10,10,30,10,20,10,20,20,10,20,10,40,15,15,15,15,15,
  15,10,20,10,40,10,20,10,20,20,10,20,10,40,10,20,10,15,15,15,
  10,20,10,40,10,20,10,20,20,10,20,10,40,15,15,15,15,15,15,10,
  20,10,40,10,20,10,20,20,10,20,10,40,10,20,10,15,15,15,10,20,
  10,40,10,20,10,10,10,10,10,80,10,20,10,10,10,20,10,20,10,40,
  10,10,10,10,10,10,20,20,20,20,20,10,20,10,20,20,10,20,10,40,
  15,15,15,15,15,15,10,20,10,40,10,20,10,20,20,10,20,10,40,10,
  20,10,15,15,15,10,20,10,40,30,30,20,15,15,15,15,15,15,10,10,
  60
};

#define TFT_CS    8      //LCD
#define TFT_RST   9      
#define TFT_DC    10     
#define buzzer    7      //蜂鳴器
#define strobePin 6      //七段顯示器
#define clockPin  5 
#define dataPin   4
#define servoPin  3      //伺服馬達
#define btn       2      //按鈕
#define LED       13     //控制板內建之LED

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
Servo servo;

#define BLACK 0X00         //太鼓的顏色
#define RED 0xF800
#define YELLOW 0xFFE0
#define GREEN 0x07E0
#define CYAN 0x07FF
#define BLUE 0X1F
#define MAGENTA 0xF81F
#define WHITE 0xFFFF

#define drumR   20     //鼓的半徑
#define wayClr  BLACK  //軌道顏色
#define wayXLoc 120    //軌道x座標
#define startYLoc 0    //新的鼓進入軌道時的初始y座標

int numVal[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; //七段顯示器上畫出數字0~9的參數值
int rainbow[7]={RED,YELLOW,GREEN,CYAN,BLUE,MAGENTA,WHITE};  //在IFI9341上顯示紅黃綠淺藍藍粉白的16進位色號
int rainDex = 0;    //依rainbow[]內容 透過變動rainDex數值(每次+1) 給予各鼓不同顏色
int noteNum = sizeof(melody) / sizeof(melody[0]) ; //整首音樂的音符總數(包含REST)
int RESTcnt = 0;  //計算樂譜中有多少個REST

/* preMve記錄上一次左移軌道上的鼓的時間點、preEnt記錄上一次音符進入軌道的時間點  */
unsigned long preMve = 0,preEnt = 0; 

/*singNote記錄現正撥放的音符(也就是最近一個從軌道盡頭消失的音符)
  entNote記錄當下軌道上最右邊的音符
  記錄音符的方式 是記錄他們在melody[]裡代表的index
  由此兩變數 可知軌道上的鼓為 melody[singNote+1] ~ melody[entNote]  */
int singNote = -1,entNote = 0;    

/*que[qSize] / qCLr[qSize] 為記錄當下軌道上的 鼓的y座標位置 及 鼓的顏色
  以各鼓的index % 20 即為對應的資訊 
  如 : (singNote+1) ~ (entNote) 為 137 ~ 142
  那麼  que[137%20] ~  que[142%20]  即為相對應資訊*/
const int qSize = 20;  //que[] 的大小
int que[qSize] = {0};  //記錄軌道上的鼓的y座標位置 以各鼓的index%20 即為對應的資訊  
int qClr[qSize] = {BLACK}; 

int gameover = 0;   //代表遊戲是否結束 當最後一個音符到達軌道盡頭(y座標為270)要消失時 即將gameover改為1
int gate = 0;      //代表 是否為玩家合法擊打按鈕的時刻 當軌道最左邊的鼓在y座標225 ~ y座標270 時 即為合法擊打時間 此時gate會為1  
int score = 0;      //記錄得分


void hitting();  //按鍵中斷的ISR
void send(byte);  
void sendCommand(byte);
void drawing(byte,byte); //在七段顯示器上畫出圖案 

void setup() {

  pinMode(strobePin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  digitalWrite(strobePin,HIGH);
  digitalWrite(clockPin,HIGH);
  sendCommand(0x40);
  sendCommand(0x88);

  for(int i=0;i<16;i++)
    drawing(0xc0+i,0x00);

  RESTcnt = 0;
  for(int i=0;i<noteNum;i++)
    if(melody[i]==REST)
      RESTcnt++;

  Serial.begin(9600);
  Serial.println(RESTcnt);
  Serial.println(noteNum);
  Serial.println(noteNum-RESTcnt);
  tft.begin();

  tft.fillScreen(MAGENTA);
  tft.setCursor(90, 305);  //設定文字游標點
  tft.setFont(&FreeMonoBold9pt7b);
  tft.print("CLICK!");  
  servo.attach(servoPin);
  servo.write(0);
  attachInterrupt(digitalPinToInterrupt(btn),hitting,RISING);
}

 
  while(!gameover)
  {
    if(millis()-preMve >= 45)
    {
      preMve = millis();
      
      if(que[(singNote+1)%20]==270)
      {
        tft.fillRoundRect(wayXLoc,que[(singNote+1)%20],drumR,drumR,drumR,wayClr);
        for(int i=0;i<8;i++)
            drawing(0xc1+2*i,0);
        que[(singNote+1)%20] = 0;
        gate = 0;
        singNote++;
        if(singNote==noteNum-1)
          gameover = 1;
      }
      //Serial.print("move : ");Serial.print(singNote+1);Serial.print(" , ");Serial.println(entNote);
      if(que[(singNote+1)%20] == 240)
      {
        if(singNote!=-1)
          noTone(buzzer);
        if(melody[singNote+1]!=REST)
        {
          gate = 1;
          for(int i=0;i<8;i++)
            drawing(0xc1+2*i,1);
        }
        tone(buzzer, melody[singNote+1], rhythm[singNote+1]*15*3/2*0.9 );
      }
      
    }
    if(millis()-preEnt >= rhythm[entNote]*15*3/2)
    {
      preEnt = millis();
      //Serial.print("enter : ");Serial.println(entNote+1);
      if(entNote+1 < noteNum)
      {
        entNote++;
        que[entNote%20] = startYLoc;
        if(melody[entNote] != REST)
        {
          qClr[entNote%20] = rainbow[rainDex];
          rainDex = (rainDex+1)%7;
          tft.fillRoundRect(wayXLoc,startYLoc,drumR,drumR,drumR,qClr[entNote%20]); 
        }
      }
    }  
  }
  tft.fillScreen(WHITE);
  tft.setRotation(3);
  tft.drawChar(30,80,score/100+'0',RED,WHITE,5);
  tft.drawChar(70,80,(score/10)%10+'0',RED,WHITE,5);
  tft.drawChar(110,80,score%10+'0',RED,WHITE,5);
  tft.drawChar(150,80,'/',RED,WHITE,5);
  tft.drawChar(190,80,(noteNum-RESTcnt)/100+'0',RED,WHITE,5);
  tft.drawChar(230,80,((noteNum-RESTcnt)/10)%10+'0',RED,WHITE,5);
  tft.drawChar(270,80,(noteNum-RESTcnt)%10+'0',RED,WHITE,5);  
  while(1);
}


void hitting()
{
  if(gate)
  {
    gate = 0;
    score++;
    drawing(0xce,numVal[score%10]);
    drawing(0xcc,numVal[(score/10)%10]);
    drawing(0xca,numVal[score/100]);
    servo.write(180*score/(noteNum-RESTcnt));
  }
  Serial.println("hit");
}

void drawing(byte seat,byte graph)
{
  digitalWrite(strobePin,LOW);
  send(seat);
  send(graph);
  digitalWrite(strobePin,HIGH);
}

void sendCommand(byte cmd)
{
  digitalWrite(strobePin,LOW);
  send(cmd);
  digitalWrite(strobePin,HIGH);
}

void send(byte data)
{
  for(int i=0;i<8;i++)
  {
    digitalWrite(clockPin,LOW);
    digitalWrite(dataPin,data & 1? HIGH : LOW );
    data >>= 1;
    digitalWrite(clockPin,HIGH);
  }
}
