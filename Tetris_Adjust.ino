#include <Adafruit_GFX.h>       
#include <Adafruit_ILI9341.h>   

#define TFT_CS    8      
#define TFT_RST   9      
#define TFT_DC    10     
#define XposPin   A0
#define buttonPin 2

#define CYAN 0x07FF
#define BLACK 0X00
#define bWid 20
#define bLen 60 
#define bFrm 2
#define rowGoal 12 

int xpos = 0;
int buttonpress = 0;

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

volatile int timeCount = 0;
volatile int puzz[3] = {0,1,6};    //紀錄正在落下積木的狀態 直or橫 
volatile int arr[18][14] = {0};    //記錄各個格子是否被占用 佔用:1~6(各代表不同圖形) 未佔:0 四周邊框:1
volatile int rowScore[18] = {0};   //每列有多少格子被佔用
byte graph[7][4] = {{0},{bFrm,bFrm,bWid-bFrm,bWid-2*bFrm},{0,bFrm,bWid,bWid-2*bFrm},{0,bFrm,bWid-bFrm,bWid-2*bFrm},
                    {bFrm,bFrm,bWid-2*bFrm,bWid-bFrm},{bFrm,0,bWid-2*bFrm,bWid},{bFrm,0,bWid-2*bFrm,bWid-bFrm}};  //積木中不同區段(1~6)格子的fillRect()參數

void Lmove();
void Rmove();
void setDown();
void del();     
void drawing();
void vanish(int);

void setup() {
  pinMode(XposPin,INPUT);
  pinMode(buttonPin,INPUT);
  digitalWrite(buttonPin,HIGH);
 
  tft.begin();

  for(int i=0;i<18;i++)
    arr[i][0] = arr[i][13] = 1;   //初始邊框為1
  for(int i=1;i<=12;i++)
    arr[0][i] = arr[17][i] = 1;   //初始邊框為1
  tft.fillScreen(BLACK);
  tft.fillRect(4*bWid+bFrm, bFrm, bLen-2*bFrm, bWid-2*bFrm, CYAN);
  Xpos = analogRead(xposPin);
  attachInterrupt(digitalPinToInterrupt(Xjoy),Lmove,RISING);
  attachInterrupt(digitalPinToInterrupt(Xjoy),Rmove,RISING);
  cli();
  TCCR0A = 0;
  TCCR0B = 0;
  TCCR0B |= B00000101;
  TIMSK0 |= B00000010;
  OCR0A = 255;
  TCNT0 = 0;
  sei();


}

void loop() {
  Xpos = map(Xpos,0,1023,0,180);
}

void buttonpress()
{
  buttonPress = digitalRead(buttonPin);
  if(buttonPress == LOW){
    
}


void Lmove()
{
  if(puzz[0])
  {
    if(arr[puzz[1]][puzz[2]-1] || arr[puzz[1]-1][puzz[2]-1] || arr[puzz[1]+1][puzz[2]-1])
      return ;
    del();                                                                    
    puzz[2]--;
    drawing();
  }
  else
  {
    if(arr[puzz[1]][puzz[2]-2])
      return ;
    del();
    puzz[2]--;
    drawing();
  }
}

void Rmove()
{
  if(puzz[0])
  {
    if(arr[puzz[1]][puzz[2]+1]||arr[puzz[1]-1][puzz[2]+1]||arr[puzz[1]+1][puzz[2]+1])
      return;
    del();
    puzz[2]++;
    drawing();
  }
  else
  {
    if(arr[puzz[1]][puzz[2]+2])
      return ;
    del();
    puzz[2]++;
    drawing();
  }
}

ISR(TIMER0_COMPA_vect){

  if(++timeCount == 49)
  {
    timeCount = 0;
    if(puzz[0])
    {
      if( arr[puzz[1]+2][puzz[2]] )
        setDown();
      else
      {
        del();
        if(!(arr[puzz[1]+1][puzz[2]-1] || arr[puzz[1]+1][puzz[2]+1]) )
        { puzz[0] = 0;  puzz[1]++; }  
        else
          puzz[1]++;
        drawing();
      }
    }
    else
    {
      if(arr[puzz[1]+1][puzz[2]] || arr[puzz[1]+1][puzz[2]-1] || arr[puzz[1]+1][puzz[2]+1] )
        setDown();
      else
      {
        del();
        if(!(arr[puzz[1]+1][puzz[2]] || arr[puzz[1]+2][puzz[2]]) )
        { puzz[0] = 1;  puzz[1]++;}  
        else
          puzz[1]++; 
        drawing();
      }
    }
  }
}

void setDown()
{
  if(puzz[0])
  {
    arr[puzz[1]-1][puzz[2]] = 4;
    arr[puzz[1]][puzz[2]] = 5;
    arr[puzz[1]+1][puzz[2]] = 6;
    rowScore[puzz[1]-1]++; rowScore[puzz[1]]++; rowScore[puzz[1]+1]++;
    for(int i=-1;i<=1;i++)
      if(rowScore[puzz[1]+i]==12) vanish(puzz[1]+i);
  }
  else
  {
    arr[puzz[1]][puzz[2]-1] = 1;
    arr[puzz[1]][puzz[2]] = 2;
    arr[puzz[1]][puzz[2]+1] = 3;
    rowScore[puzz[1]]+=3;
    if(rowScore[puzz[1]]==12) vanish(puzz[1]);
  }
  puzz[0] = 0;  puzz[1] = 1;  puzz[2] = 6;
  tft.fillRect(bWid*4+bFrm, bFrm, bLen-2*bFrm, bWid-2*bFrm, CYAN);
}

void del()
{
  if(puzz[0])
    tft.fillRect(bWid*(puzz[2]-1), bWid*(puzz[1]-2), bWid, bLen, BLACK);
  else
    tft.fillRect(bWid*(puzz[2]-2), bWid*(puzz[1]-1), bLen, bWid, BLACK);
}

void drawing()
{
  if(puzz[0])
    tft.fillRect(bWid*(puzz[2]-1)+bFrm, bWid*(puzz[1]-2)+bFrm, bWid-2*bFrm, bLen-2*bFrm, CYAN);
  else
    tft.fillRect(bWid*(puzz[2]-2)+bFrm, bWid*(puzz[1]-1)+bFrm, bLen-2*bFrm, bWid-2*bFrm, CYAN);
}

void vanish(int n)
{
  for(int i=n;i>1;i--)
  {
    for(int j=1;j<=12;j++)
      arr[i][j] = arr[i-1][j];
    rowScore[i] = rowScore[i-1];
  } 
  for(int j=1;j<=12;j++)
    arr[1][j] = 0;
  rowScore[1] = 0; 
  tft.fillRect(0,bWid*(n-1),240,bWid,BLACK);
  delay(200);
  tft.fillRect(0,0,240,bWid*(n-1),BLACK);
  for(int i=n;i>=2;i--)
    for(int j=1;j<=12;j++)
      tft.fillRect(bWid*(j-1)+graph[arr[i][j]][0],bWid*(i-1)+graph[arr[i][j]][1],graph[arr[i][j]][2],graph[arr[i][j]][3],CYAN);  
}
