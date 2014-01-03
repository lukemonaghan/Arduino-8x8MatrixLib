/*

TextMatrix.ino
Luke Monaghan - 03/01/14
www.github.com/lukemonaghan

Sketch size = 10624 (with Letters.h)
Estimated ram use = 1287 (with Letters.h)

8x8 matrix letters binary sample code.
Display scrolling text using my Letter.h library, code is commented for educational use.

Fell free to use for educational use, any other forms of use must ask for permission first.

I am not responsible for any damage to any of your parts, code, wires, or animals.

*/

#include "Letters.h"

const char rowval = 8;//size of matrix
const char colval = 8;//size of matrix
// 8x8 matrix
const char rownum[rowval] = { 30,48,46,24,42,26,34,36 }; //Row Pins
const char colnum[colval] = { 44,50,40,52,28,38,32,22 }; //Column Pins


String text = "Hello World ";//string to display
char current1,current2;//current letters to show, left and right

int iTime,iTimeMax = 25;//needs to be an int
char iPosition;
char Pos;

//Scene to write to. Could be optimized through bitwise
Matrix8x8 Scene;

//Arduino Functions
void setup() {
	//setup our serial for input
	Serial.begin(9600);
	//setup the pins
	for (char thisPin = 0; thisPin < sizeof(colnum) / sizeof(char); thisPin++) {
		pinMode(	 colnum[thisPin], OUTPUT);
		pinMode(	 rownum[thisPin], OUTPUT);
		digitalWrite(colnum[thisPin], LOW	);
		digitalWrite(rownum[thisPin], HIGH	);
	}
	Serial.println("----Setup Finished----");
}
void loop() {
	iTime--;
	bool bFalse = false;
	while( Serial.available() > 0) {
		char val = Serial.read();
		text += val;
	}
	ClearScreen();
	UpdateMatrix();
	DrawScreen();
}

void UpdateMatrix(){
	//check if its time to update	
	if (iTime < 0){
		//it was, reset the timer.
		iTime = iTimeMax;
		//take away one position
		Pos--;
		//check if we are outside the colval(max view width)
		if (Pos < -colval + 1){
			//we are, reset to 0
			Pos = 0;
			//set our left letter, to the right(as if its scrolling)
			current2 = current1;
			//move one along our string
			iPosition++;
			//make sure we haven't gone past the end
			if (iPosition >= text.length()){
				//uh oh, we have, go back to the start
				iPosition = 0;
			}
			//set our current to the position in the string(as strings are lots of chars, we can use it as an array)
			current1 = text[iPosition];
		}
	}
	//Draw our letters
	drawLetter(Pos+colval,0,current1);
	drawLetter(Pos,0,current2);
}

//Clear all pixels on the "Scene"
void ClearScreen(){
	for(char j = 0; j < sizeof(colnum) / sizeof(char); j++) {
		for (char k = 0; k < sizeof(rownum) / sizeof(char); k++) {
			WritePixel(Scene,j,k,0);
		}
	}
}

//Draw a letter
void drawLetter(char x,char y,char c){
	//setup the chars values
	char iX = 0,iY = 0;
	//check we are inside the bounds, if not, fail out, no point drawing
	if (x <= -rowval || x >=  rowval || y <= -colval || y >=  colval  ){
		return;
	}
	//iterate through the pixels
	for(char j = y; j < y + rowval; j++) {
		for (char k = x; k < x + colval; k++) {
			//check if we are inside the viewport
			if (j <= colval && k <= rowval && j >= 0 && k >= 0){
				//find out if we need to display a pixel from the library with the given char
				char iLetter = GetPixel(c,iX,iY);
				//check if its value isnt 0
				 if (iLetter != 0){
				 	//yay we found a pixel, draw it
					WritePixel(Scene,j,k,iLetter);
				}
			}
			//move one
			iY++;
		}
		//reset Y and move one X
		iY = 0;
		iX++;
	}
}

//8x8 GRAPHICS DRIVER - NEEDS REVISION
char row(char i) {
	if(i == 0) {
		return rownum[0];
	} else if (i == 1) {
		return rownum[1];
	} else if (i == 2) {
		return rownum[2];
	} else if (i == 3) {
		return rownum[3];
	} else if (i == 4) {
		return rownum[4];
	} else if (i == 5) {
		return rownum[5];
	} else if (i == 6) {
		return rownum[6];
	} else if (i == 7) {
		return rownum[7];
	}
}
char col(char i) {
	if(i == 0) {
		return colnum[0];
	} else if (i == 1) {
		return colnum[1];
	} else if (i == 2) {
		return colnum[2];
	} else if (i == 3) {
		return colnum[3];
	} else if (i == 4) {
		return colnum[4];
	} else if (i == 5) {
		return colnum[5];
	} else if (i == 6) {
		return colnum[6];
	} else if (i == 7) {
		return colnum[7];
	}
}
void DrawScreen() {
	for(char j = 0; j < sizeof(rownum) / sizeof(char); j++) {
		// Turn the row on
		digitalWrite(row(j), LOW);
		for (char k = 0; k < sizeof(colnum) / sizeof(char); k++) {
			// draw some letter bits
			if(GetPixelMatrix(Scene,j,k) == 1) {
				digitalWrite(col(k), HIGH);
			}
			digitalWrite(col(k), LOW);
		}
		digitalWrite(row(j), HIGH);
	}
}
