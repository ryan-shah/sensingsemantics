#include <avr/pgmspace.h>
 
#define CUBESIZE 4
#define PLANESIZE 16
#define PLANETIME 3333
#define TIMECONST 5
 
int LEDPin[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; 
int LEDPinCount = 16; 
int PlanePin[4] = {16,17,18,19}; 
int PlanePinCount = 4; 
 
int greens[95] = {0,0,0,3,4,6,0,0,0,0,0,0,9,0,8,13,10,11,11,6,0,0,0,0,0,4,10,9,0,13,9,11,0,0,0,0,9,11,0,0,0,0,0,0,0,0,13,8,13,0,0,0,0,0,0,0,13,3,8,0,9,11,9,11,0,0,0,0,9,11,0,0,0,0,0,0,9,0,0,0,3,8,13,9,11,0,0,0,0,9,11,0,0,0,0,};
int reds[95] = {0,0,0,10,5,13,0,0,0,0,0,0,3,8,0,7,7,12,12,13,0,8,0,0,0,5,7,3,0,7,3,12,0,0,0,0,3,12,0,0,0,0,0,0,8,0,7,0,7,0,0,0,0,0,0,0,7,10,0,0,3,12,3,12,0,0,0,0,3,12,0,0,0,0,0,0,3,0,0,8,10,0,7,3,12,0,0,0,0,3,12,0,0,0,0,};
int yellow[1] = {7};
int blue[1] = {8};
void setup(){
	 int pin = 0;
	 for(pin; pin < PLANESIZE; pin++){
		 pinMode( LEDPin[pin], OUTPUT ); }
	 for(pin = 0; pin < CUBESIZE; pin++){
		 pinMode( PlanePin[pin], OUTPUT); }
}
 
void loop(){
	 greenLoop();
	 redLoop();
	 yellowLoop();
	 blueLoop();
	 delay(2000);
}
 
void greenLoop(){
	 planesOff();
	 digitalWrite(PlanePin[0], LOW); 
	 for(int i = 0; i <95; i++){ 
	 	 for(int j = 0; j < greens[i]; j++){
	 	 	 digitalWrite(LEDPin[j], HIGH); 
	 	 	 delay(500);
	 	 	 planesOff();}
	 }
}
 
void redLoop(){
	 planesOff();
	 digitalWrite(PlanePin[3], LOW); 
	 for(int i = 0; i <95; i++){ 
	 	 for(int j = 0; j < reds[i]; j++){
	 	 	 digitalWrite(LEDPin[j], HIGH); 
	 	 	 delay(500);
	 	 	 planesOff();}
	 }
}
 
void blueLoop(){
	 planesOff();
	 digitalWrite(PlanePin[1], LOW); 
	 for(int i = 0; i < 8; i++){ 
	 	 digitalWrite(LEDPin[i], HIGH);
	 	 delay(500);
	 	 planesOff();}
}
 
void yellowLoop(){
	 planesOff();
	 digitalWrite(PlanePin[2], LOW); 
	 for(int i = 0; i < 7; i++){ 
	 	 digitalWrite(LEDPin[i], HIGH);
	 	 delay(500);
	 	 planesOff();}
}
 
void planesOff(){
	 for(int thisPlane = 0; thisPlane < PlanePinCount; thisPlane++){
	 	 digitalWrite(PlanePin[thisPlane], HIGH); }
}