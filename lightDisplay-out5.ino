#include <avr/pgmspace.h>
 
#define CUBESIZE 4
#define PLANESIZE 16
#define PLANETIME 3333
#define TIMECONST 5
 
int LEDPin[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; 
int LEDPinCount = 16; 
int PlanePin[4] = {16,17,18,19}; 
int PlanePinCount = 4; 
 
int greens[51] = {13,4,13,4,8,6,9,4,4,6,3,9,13,6,9,4,8,13,3,13,3,9,12,4,7,13,13,13,8,6,13,6,7,7,4,11,8,7,12,6,3,3,12,7,9,9,13,4,7,13,6,};
int reds[51] = {12,3,12,3,4,13,7,3,3,13,10,7,12,13,7,3,9,12,9,12,10,7,8,3,9,12,12,12,4,13,12,13,9,9,3,9,12,8,8,9,10,9,8,8,3,3,12,3,9,12,13,};
int yellow[1] = {7};
int blue[1] = {7};
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
	 for(int i = 0; i <51; i++){ 
	 	 for(int j = 0; j < greens[i]; j++){
	 	 	 digitalWrite(LEDPin[j], HIGH); 
	 	 	 delay(500);
	 	 	 planesOff();}
	 }
}
 
void redLoop(){
	 planesOff();
	 digitalWrite(PlanePin[3], LOW); 
	 for(int i = 0; i <51; i++){ 
	 	 for(int j = 0; j < reds[i]; j++){
	 	 	 digitalWrite(LEDPin[j], HIGH); 
	 	 	 delay(500);
	 	 	 planesOff();}
	 }
}
 
void blueLoop(){
	 planesOff();
	 digitalWrite(PlanePin[1], LOW); 
	 for(int i = 0; i < 7; i++){ 
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