#define DATA 2
#define DIODES 20
#define SPEED_OF_CHANGE_TRYB2 1

#include <Adafruit_NeoPixel.h>



Adafruit_NeoPixel pixels = Adafruit_NeoPixel(DIODES, DATA, NEO_GRB + NEO_KHZ400);

uint32_t randomColor()
{
  switch(random(0,7))
  {
    case 0:
    return pixels.Color(255,0,0);
    break;

    case 1:
    return pixels.Color(0,255,0);
    break;

    case 2:
    return pixels.Color(0,0,255);
    break;

    case 3:
    return pixels.Color(255,255,0);
    break;

    case 4:
    return pixels.Color(255,0,255);
    break;

    case 5:
    return pixels.Color(0,255,255);
    break;

    case 6:
    return pixels.Color(255,255,255);
    break;
  }
}

void tryb1(int dly)
{
  pixels.setBrightness(20);
  for(int i=0; i < DIODES; i++)
 {
  pixels.setPixelColor(i, 255, 0, 0);
  pixels.show();
  delay(dly);
 }
 for(int i=0; i < DIODES; i++)
 {
  pixels.setPixelColor(i, 0, 255, 0);
  pixels.show();
  delay(dly);
 }
 for(int i=0; i < DIODES; i++)
 {
  pixels.setPixelColor(i, 0, 0, 255);
  pixels.show();
  delay(dly);
 }
}

void tryb2(int dly)
{
  pixels.setBrightness(20);
   
for(int j=0; j < 256;j++)
{
    for(int i=0; i < DIODES; i++)
   {
    pixels.setPixelColor(i, 255, j, 0);
    
   }
   delay(dly);
   pixels.show();
}

for(int j=0; j < 256;j++)
{
    for(int i=0; i < DIODES; i++)
   {
    pixels.setPixelColor(i, 255-j, 255, 0);
    
   }
   delay(dly);
   pixels.show();
}

for(int j=0; j < 256;j++)
{
    for(int i=0; i < DIODES; i++)
   {
    pixels.setPixelColor(i, 0, 255, j);
    
   }
   delay(dly);
   pixels.show();
}

for(int j=0; j < 256;j++)
{
    for(int i=0; i < DIODES; i++)
   {
    pixels.setPixelColor(i, 0, 255-j, 255);
    
   }
   delay(dly);
   pixels.show();
}

for(int j=0; j < 256;j++)
{
    for(int i=0; i < DIODES; i++)
   {
    pixels.setPixelColor(i, j, 0, 255);
    
   }
   delay(dly);
   pixels.show();
}

for(int j=0; j < 256;j++)
{
    for(int i=0; i < DIODES; i++)
   {
    pixels.setPixelColor(i, 255, 0, 255-j);
    
   }
   delay(dly);
   pixels.show();
}
  
}
void tryb3(int dly)
{
  pixels.setBrightness(20);
  static bool R_up=true;
  static bool G_up=true;
  static bool B_up=true;
  static int R=0;
  static int G=85;
  static int B=170;
  for(int i=0; i < DIODES; i++)
 {
  pixels.setPixelColor(i, R, G, B);
  pixels.show();
 
 if(R_up)
  R+=1;
  else
  R-=1;
  if(G_up)
  G+=1;
  else
  G-=1;
  if(B_up)
  B+=1;
  else
  B-=1;
  if(R>=255 || R<=0) R_up=!R_up;
 if(G>=255 || G<=0) G_up=!G_up;
 if(B>=255 || B<=0) B_up=!B_up;
  
  delay(dly);
 }
}

void tryb4(int dly)
{
  pixels.setBrightness(20);
  for(int i=0; i < DIODES; i++)
 {
  pixels.clear();
  pixels.setPixelColor(i, randomColor());
  pixels.show();
  delay(dly);
 }
}

void tryb5(int dly)
{
  pixels.setBrightness(20);

  uint32_t kolorek = randomColor();
  for(int i=0; i < DIODES; i+=2)
 {
  
  pixels.setPixelColor(i, kolorek);
  pixels.show();
  
 }
 pixels.clear();
 delay(dly);
 for(int i=1; i < DIODES; i+=2)
 {
  
  pixels.setPixelColor(i, kolorek);
  pixels.show();
  
 }
 delay(dly);
 pixels.clear();
}

void tryb6(int dly)
{
  pixels.setBrightness(20);

  uint32_t kolorek = randomColor();
 for(int i=0; i < 35; i++)
 {
  
  pixels.setBrightness(i);
  for(int i=0; i < DIODES; i++)
 {
  pixels.setPixelColor(i, kolorek);
 }
  pixels.show();
  delay(45);
 }
 delay(dly);
 for(int i=35; i > 0; i--)
 {
  
  pixels.setBrightness(i);
  for(int i=0; i < DIODES; i++)
 {
  pixels.setPixelColor(i, kolorek);
 }
  pixels.show();
  delay(45);

 }
 pixels.clear();
 delay(dly);
}

void setup() 
{
  Serial.begin(9600);
  pixels.begin();
  pixels.setBrightness(20);
}
void loop() 
{
  static int wybor=0;
  static long long timer= millis();
  if(millis()-timer<10000)
  {
    switch(wybor)
    {
    case 0:
      tryb1(50);
      Serial.println("tryb1");
    break;
    
    case 1:
      tryb2(5);
      Serial.println("tryb2");
    break;

    case 2:
    tryb3(30);
    Serial.println("tryb3");
    break;

    case 3:
    tryb4(100);
    Serial.println("tryb4");
    break;

    case 4:
    tryb5(450);
    Serial.println("tryb5");
    break;

    case 6:
    tryb6(300);
    Serial.println("tryb6");
    break;
    }
  }
  else 
  {
    timer=millis();
    wybor=random(0,7);
    
  }

  

  
}
