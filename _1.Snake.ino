#include <Adafruit_SSD1306.h>

#define OLED_RESET 9
Adafruit_SSD1306 OLED(OLED_RESET);

const byte VRx = A1;
const byte VRy = A2;

#define WIGTH 128
#define HEIGHT 64
#define SMAX 100

byte length = 3; //蛇身長度

byte z = 0; //方向
short snake[2][SMAX]; //座標
short s = 0; //步驟
short s2 = 0;
short nowX = (WIGTH / 2) - 1; //現x座標
short nowY = (HEIGHT / 2) - 1; //現y座標

byte i;

byte eggX;
byte eggY;
short eg = 25;
bool gg = 1;
bool eaten = 1;

void wall();
bool endd();
void sOperate();
void keyboardControll();
void body();
void eggBorn(bool);
void run();
void writeWord(byte);

void setup() {
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  OLED.clearDisplay();
  OLED.setTextSize(1);
  OLED.setTextColor(WHITE);
  OLED.setCursor(0, 0);
  OLED.display();
  wall();
  writeWord(1);
  delay(1000);
  writeWord(0);
  OLED.drawPixel((WIGTH / 2) - 1, (HEIGHT / 2) - 1, WHITE);
  OLED.display();
  while(z == 0) {
      keyboardControll();
  }
  OLED.drawPixel((WIGTH / 2) - 1, (HEIGHT / 2) - 1, BLACK);
  OLED.display();
  eaten = 1;
  for(i = 0; i < 3; i++) {
      s++;
      run();
  }
  while( endd() ) {
    sOperate();
    run();
  }
  writeWord(0);
  writeWord(2);
  delay(500);
  writeWord(3);
}
void loop() {
}


void writeWord(byte num) {
  if(num == 0) {
    OLED.fillRect(1, 1, WIGTH - 2, HEIGHT - 2, BLACK);
    OLED.display();
  }
  if(num == 1) {
    OLED.setTextSize(2);
    OLED.setTextColor(WHITE);
    OLED.setCursor(21, 25);
    OLED.print("Welcome!");
    OLED.display();
  }
  if(num == 2) {
    OLED.setTextSize(2);
    OLED.setTextColor(WHITE);
    OLED.setCursor(23, 25);
    OLED.print("The End");
    OLED.display();
  }
  if(num == 3) {
    OLED.fillRect(22, 24, 84, 16, WHITE);
    OLED.setTextSize(2);
    OLED.setTextColor(BLACK);
    OLED.setCursor(23, 25);
    OLED.print("The End");
    OLED.display();
  }
}


void wall() {
    OLED.drawRect(0, 0, WIGTH, HEIGHT, WHITE);
    OLED.display();
}

bool endd() {
  for(i = s-1; i > s2; i--) {
      if(nowX == snake[0][i] && nowY == snake[1][i])
          return false;
  }
  return true;
}

void keyboardControll() {
    int YYY = analogRead(VRy);
    YYY = map(YYY, 0, 1023, 0, 3);
    switch(YYY) {
      case 0:
        if(z != 2)
            z = 4;
        break;
      case 2:
      case 3:
        if(z != 4)
            z = 2;
        break;
    }
    int XXX = analogRead(VRx);
    XXX = map(XXX, 0, 1023, 0, 3);
    switch(XXX) {
      case 0:
        if(z != 3)
            z = 1;
        break;
      case 2:
      case 3:
        if(z != 1)
            z = 3;
        break;
    }
}

void sOperate() {
    s2 = s - length + 1;
    if(s2 < 0)
        s2 += SMAX;
    s++;
    if(s >= SMAX)
        s -= SMAX;
}

void body() {
    keyboardControll();
    switch(z) {
      case 1:
        nowY += -1;
        break;
      case 3:
        nowY += 1;
        break;
      case 2:
        nowX += -1;
        break;
      case 4:
        nowX += 1;
        break;
  }
  if(nowX < 1)
     nowX = WIGTH - 2;
  if(nowX > WIGTH - 2)
     nowX = 1;
  if(nowY < 1)
     nowY = HEIGHT - 2;
  if(nowY > HEIGHT - 2)
     nowY = 1;
  snake[0][s] = nowX;
  snake[1][s] = nowY;
  OLED.drawPixel(nowX, nowY, WHITE);
  OLED.display();
    if(nowX == eggX && nowY == eggY) {
        length += 2;
        eg = 20;
        eaten = 1;
    }
    else {
        OLED.drawPixel(snake[0][s2], snake[1][s2], BLACK);
        OLED.display();
    }
}

void eggBorn(bool num) {
    if(num == 1 && eg <= 0) {
        do {
            eggX = random(1, WIGTH - 1);
            eggY = random(1, HEIGHT - 1);
            for(i = 0; i < length; i++) {
              byte jj = s - i;
              if(jj < 0)
                jj += SMAX;
                if(snake[0][jj] == eggX && snake[1][jj] == eggY)
                    gg = 0;
                else
                    gg = 1;
            }
        } while(gg == 0);
        OLED.drawPixel(eggX, eggY, WHITE);
        OLED.display();
        eaten = 0;
        eg = 20;
    }
    if(num == 1)
        eg--;
}

void run() {
    eggBorn(eaten);
    eg--;
    delayMicroseconds(1);
    body();
}
