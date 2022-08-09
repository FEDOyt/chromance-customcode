#include <FastLED.h>
#define LED_PIN 10
#define NUM_LEDS 47

CRGB leds[NUM_LEDS];
int R = 0;
int G = 0;
int B = 0;
int len = 0;
int num = 0;
//num is number seperate led segments used in a squence
//len is lenght of a sequence (in leds)
//R G B are color values for the sequence
//pos is a 2d array where every row is a led segment and every column has only 2 value,
//first one is a number of starting led, and the second column has the direction (0 = forward, 1 = backwards)

void chase(int num, int len, int R, int G, int B, int pos[][2]) {
  
  //repeat for lenght of a sequence
  for (int i = 0; i<len; i++) {
    //repeat for every segment of leds
    for (int j = 0; j < num; j++){
      //determine if sequence is going "forward"
      if (pos[j][1] == 0) {
        leds[pos[j][0]+i] = CRGB(R, G, B);
        leds[pos[j][0]+i-2] = CRGB(0, 0, 0);
      } else {
        leds[pos[j][0]+len-i] = CRGB(R, G, B);
        leds[pos[j][0]+len-i+2] = CRGB(0, 0, 0);
      };
    };
    FastLED.show();
    delay(300);
  }
  FastLED.clear();
  FastLED.show();
  
};

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, LED_PIN, BRG>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  int pos[3][2] = {{0, 0},{14, 1},{19, 0}};
  chase(3, 5, 255, 255, 255,pos);
  int pos1[4][2] = {{5, 0},{9, 1},{25, 0},{29, 1}};
  chase(4, 5, 255, 255, 255,pos1);
  int pos2[2][2] = {{35, 0},{39, 1}};
  chase(2, 5, 255, 255, 255,pos2);

  int pos4[2][2] = {{34, 1},{40, 0}};
  chase(2, 5, 255, 255, 255,pos4);
  int pos5[4][2] = {{4, 1},{10, 0},{24, 1},{30, 0}};
  chase(4, 5, 255, 255, 255,pos5);
  int pos3[3][2] = {{-1, 1},{15, 0},{19, 1}};
  chase(3, 5, 255, 255, 255,pos3);
  //test pattern
  //int postest[9][2] = {{0, 0},{5, 0},{10, 0},{15, 0},{20, 0},{25, 0},{30, 0},{35, 0},{40, 0}};
  //chase(9, 5, 255, 255, 255,postest);

}
