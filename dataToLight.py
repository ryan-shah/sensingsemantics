import sys

def main():

	args = sys.argv
        if(len(args) != 2):
                print('usage: \"python dataToLight.py filename\"')
                return -1
	
	greens = []
	reds = []
	yellow = []
	blue = []

	txtData = open(args[1], 'r')
	
	counter = 0

	for row in txtData:
		if(counter != 0):	
			vals = row.split(',')
			greens.append( int((float(vals[0]) * 16) + .5))
			reds.append( int((float(vals[1]) * 16) + .5))
			counter += 1
		else:
			vals = row.split(',')
			blue.append( int((float(vals[0]) * 16) + .5))
			yellow.append( int((float(vals[1]) * 16) + .5))
			counter += 1
#	print(greens)
#	print(reds)
#	print(yellow)
#	print(blue)
	
	namer = args[1].split('.')
	lightFile = open('lightDisplay-' + str(namer[0]) + '.ino', 'w')
	
	lightFile.write("#include <avr/pgmspace.h>" + "\n \n" + "#define CUBESIZE 4" + "\n" + "#define PLANESIZE 16" + "\n" + "#define PLANETIME 3333" + "\n" + "#define TIMECONST 5" + "\n \n")
	lightFile.write("int LEDPin[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; \n")
	lightFile.write("int LEDPinCount = 16; \n")
	lightFile.write("int PlanePin[4] = {16,17,18,19}; \n")
	lightFile.write("int PlanePinCount = 4; \n \n")
	GR = "{"
	for val in greens:
		GR += str(greens[val]) + ","
	GR += "}"
	lightFile.write("int greens[" + str(len(greens)) + "] = " + GR + ";" + "\n")

	RD = "{"
        for val in reds:
                RD += str(reds[val]) + ","
        RD += "}"
        lightFile.write("int reds[" + str(len(reds)) + "] = " + RD + ";" + "\n")
	
	YE = "{" + str(yellow[0]) + "}"
        lightFile.write("int yellow[" + str(len(yellow)) + "] = " + YE + ";" + "\n")

	BL = "{" + str(blue[0]) + "}"
        lightFile.write("int blue[" + str(len(blue)) + "] = " + BL + ";" + "\n")

	lightFile.write("void setup(){" + "\n" + "\t int pin = 0;" + "\n" + "\t for(pin; pin < PLANESIZE; pin++){" + "\n" + "\t\t pinMode( LEDPin[pin], OUTPUT ); }" + "\n" + "\t for(pin = 0; pin < CUBESIZE; pin++){" + "\n" + "\t\t pinMode( PlanePin[pin], OUTPUT); }" + "\n" + "}" + "\n \n")
	
	lightFile.write("void loop(){" + "\n" + "\t greenLoop();" + "\n" + "\t redLoop();" + "\n" + "\t yellowLoop();" + "\n" + "\t blueLoop();" + "\n" + "\t delay(2000);" + "\n" + "}" + "\n \n")

	greenLoop = ""
	redLoop = ""
	yellowLoop = ""
	blueLoop = ""

	greenLoop += "\t digitalWrite(PlanePin[0], LOW); " + "\n"
	blueLoop += "\t digitalWrite(PlanePin[1], LOW); " + "\n"
	yellowLoop += "\t digitalWrite(PlanePin[2], LOW); " + "\n"
	redLoop += "\t digitalWrite(PlanePin[3], LOW); " + "\n"
	
	blueLoop += "\t for(int i = 0; i < " + str(blue[0]) + "; i++){ " + "\n" + "\t \t digitalWrite(LEDPin[i], HIGH);" + "\n" + "\t \t delay(500);" + "\n" + "\t \t planesOff();" + "}" + "\n"
	yellowLoop += "\t for(int i = 0; i < " + str(yellow[0]) + "; i++){ " + "\n" + "\t \t digitalWrite(LEDPin[i], HIGH);" + "\n" + "\t \t delay(500);" + "\n" + "\t \t planesOff();" + "}" + "\n"
	greenLoop += "\t for(int i = 0; i <" + str(len(greens)) + "; i++){ " + "\n" + "\t \t for(int j = 0; j < greens[i]; j++){" + "\n" + "\t \t \t digitalWrite(LEDPin[j], HIGH); " + "\n" + "\t \t \t delay(500);" + "\n" + "\t \t \t planesOff();" + "}" + "\n" + "\t }" + "\n"
	redLoop += "\t for(int i = 0; i <" + str(len(reds)) + "; i++){ " + "\n" + "\t \t for(int j = 0; j < reds[i]; j++){" + "\n" + "\t \t \t digitalWrite(LEDPin[j], HIGH); " + "\n" + "\t \t \t delay(500);" + "\n" + "\t \t \t planesOff();" + "}" + "\n" + "\t }" + "\n"

	lightFile.write("void greenLoop(){" + "\n" +  "\t planesOff();" + "\n" + greenLoop + "}" + "\n \n")
	lightFile.write("void redLoop(){" + "\n" +  "\t planesOff();" + "\n" + redLoop + "}" + "\n \n")
	lightFile.write("void blueLoop(){" + "\n" +  "\t planesOff();" + "\n" + blueLoop +  "}" + "\n \n")
	lightFile.write("void yellowLoop(){" + "\n" +  "\t planesOff();" + "\n" + yellowLoop +  "}" + "\n \n")

	lightFile.write("void planesOff(){" + "\n" + "\t for(int thisPlane = 0; thisPlane < PlanePinCount; thisPlane++){" + "\n" + "\t \t digitalWrite(PlanePin[thisPlane], HIGH); }" + "\n" + "}")

	lightFile.close()
main()
