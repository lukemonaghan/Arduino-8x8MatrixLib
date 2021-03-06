/*

letters.h
Luke Monaghan - 03/01/14
www.github.com/lukemonaghan

Estimated Sketch size = 4252
Estimated ram use = 504

8x8 matrix letters binary library.
I have tried to make this as minimal as possible to preserve as much memory for arduino devices as possible.
It uses bitwise operations on chars(signed byte values) to store on off boolean switches, using the whole 8 bits with no waste.
Currently it supports A-Z,a-z and 0-9.

To search through the file search for @INFO tags, doing so will jump complete segments. saves scrolling.

Fell free to use for educational use, any other forms of use must ask for permission first.

I am not responsible for any damage to any of your parts, code, wires, or animals.

*/

//@INFO Matrix8x8 struct, used to define Matrix8x8 Bitwise chars

struct Matrix8x8 { char b0,b1,b2,b3,b4,b5,b6,b7; };

//@INFO Letters

Matrix8x8 char_Space = {0,0,0,0,0,0,0,0};

Matrix8x8 char_A = {24,24,36,60,66,66,-127,-127};
Matrix8x8 char_a = {0,0,60,66,66,66,66,63};

Matrix8x8 char_B = {124,66,66,66,124,66,66,124};
Matrix8x8 char_b = {64,64,64,124,66,66,66,124};

Matrix8x8 char_C = {30,32,32,32,32,32,32,30};
Matrix8x8 char_c = {0,0,0,56,64,64,64,56};

Matrix8x8 char_D = {124,66,66,66,66,66,66,124};
Matrix8x8 char_d = {2,2,2,62,66,66,66,62};

Matrix8x8 char_E = {-2,-128,-128,-16,-16,-128,-128,-2};
Matrix8x8 char_e = {0,24,36,66,126,64,32,24};

Matrix8x8 char_F = {126,64,64,64,120,64,64,64};
Matrix8x8 char_f = {0,28,32,32,56,32,32,32};

Matrix8x8 char_G = {62,64,64,64,78,66,66,62};
Matrix8x8 char_g = {0,28,36,36,28,4,4,56};

Matrix8x8 char_H = {66,66,66,126,126,66,66,66};
Matrix8x8 char_h = {32,32,32,56,36,36,36,36};

Matrix8x8 char_I = {126,24,24,24,24,24,24,126};
Matrix8x8 char_i = {8,28,8,0,8,8,8,8};

Matrix8x8 char_J = {126,4,4,4,4,4,8,48};
Matrix8x8 char_j = {8,0,8,8,8,8,8,48};

Matrix8x8 char_K = {68,72,80,96,96,80,72,68};
Matrix8x8 char_k = {64,64,72,80,96,96,80,72};

Matrix8x8 char_L = {64,64,64,64,64,64,64,126};
Matrix8x8 char_l = {24,8,8,8,8,8,8,60};

Matrix8x8 char_M = {-127,-61,-91,-103,-127,-127,-127,-127};
Matrix8x8 char_m = {0,0,0,-92,-38,-127,-127,-127};

Matrix8x8 char_N = {-127,-63,-95,-111,-119,-123,-125,-127};
Matrix8x8 char_n = {0,0,0,88,100,66,66,66};

Matrix8x8 char_O = {60,66,-127,-127,-127,-127,66,60};
Matrix8x8 char_o = {0,0,60,66,66,66,66,60};

Matrix8x8 char_P = {124,66,66,66,124,64,64,64};
Matrix8x8 char_p = {24,36,36,56,32,32,32,32};

Matrix8x8 char_Q = {60,66,-127,-127,-127,-127,66,61};
Matrix8x8 char_q = {24,36,36,28,4,4,4,2};

Matrix8x8 char_R = {120,68,68,68,120,68,68,68};
Matrix8x8 char_r = {0,0,0,28,34,32,32,32};

Matrix8x8 char_S = {62,64,64,64,62,2,2,124};
Matrix8x8 char_s = {0,60,64,64,60,2,2,60};

Matrix8x8 char_T = {-2,16,16,16,16,16,16,16};
Matrix8x8 char_t = {16,124,16,16,16,16,16,8};

Matrix8x8 char_U = {66,66,66,66,66,66,66,60};
Matrix8x8 char_u = {0,0,0,66,66,66,38,26};

Matrix8x8 char_V = {0,-127,-127,-127,66,66,36,24};
Matrix8x8 char_v = {0,0,0,0,68,68,40,16};

Matrix8x8 char_W = {-127,-127,-127,-127,-103,-103,90,36};
Matrix8x8 char_w = {0,0,0,0,-127,-127,90,36};

Matrix8x8 char_X = {-127,66,36,24,24,36,66,-127};
Matrix8x8 char_x = {0,0,0,66,36,24,36,66};

Matrix8x8 char_Y = {66,66,36,36,24,24,24,24};
Matrix8x8 char_y = {34,34,20,8,8,16,16,32};

Matrix8x8 char_Z = {-1,2,4,8,16,32,64,-1};
Matrix8x8 char_z = {0,0,-1,2,12,48,32,-1};

//@INFO Numbers

Matrix8x8 char_0 = {60,66,66,66,66,66,66,60};
Matrix8x8 char_1 = {8,24,40,8,8,8,8,60};
Matrix8x8 char_2 = {60,2,2,2,4,8,16,62};
Matrix8x8 char_3 = {60,2,2,30,30,2,2,60};
Matrix8x8 char_4 = {4,12,20,20,126,4,4,4};
Matrix8x8 char_5 = {126,64,64,64,124,2,2,124};
Matrix8x8 char_6 = {28,32,64,64,124,66,66,60};
Matrix8x8 char_7 = {126,2,2,4,4,8,8,16};
Matrix8x8 char_8 = {126,66,66,60,60,66,66,126};
Matrix8x8 char_9 = {60,66,66,66,126,2,2,124};

//@INFO Functions

//Get the binary value of the given index
char GetBinary(char iY){ //simpley returns a value that checks bit alignments
	switch(iY){
		case 0:		return -128; //Left Most
		case 1:		return 64;
		case 2:		return 32;
		case 3:		return 16;
		case 4:		return 8;
		case 5:		return 4;
		case 6:		return 2;
		case 7:		return 1;
		default:	return 0;	//Right Most
	}
}

//Checks if a pixel is at a given index, uses ternary opperators
char IsPixel(Matrix8x8 lLet, char iX, char iY){
	switch(iX){
		case 0:		return (lLet.b0 & GetBinary(iY)) ? 1 : 0;
		case 1:		return (lLet.b1 & GetBinary(iY)) ? 1 : 0;
		case 2:		return (lLet.b2 & GetBinary(iY)) ? 1 : 0;
		case 3:		return (lLet.b3 & GetBinary(iY)) ? 1 : 0;
		case 4:		return (lLet.b4 & GetBinary(iY)) ? 1 : 0;
		case 5:		return (lLet.b5 & GetBinary(iY)) ? 1 : 0;
		case 6:		return (lLet.b6 & GetBinary(iY)) ? 1 : 0;
		case 7:		return (lLet.b7 & GetBinary(iY)) ? 1 : 0;
	}
}
//@INFO check to find if we have a pixel from a given char, you need to add your own here!
char GetPixel(char c_Letter,char iX, char iY){
	switch(c_Letter){
		case 'A':	return IsPixel(char_A,iX,iY);
		case 'a':	return IsPixel(char_a,iX,iY);
		case 'B':	return IsPixel(char_B,iX,iY);
		case 'b':	return IsPixel(char_b,iX,iY);
		case 'C':	return IsPixel(char_C,iX,iY);
		case 'c':	return IsPixel(char_c,iX,iY);
		case 'D':	return IsPixel(char_D,iX,iY);
		case 'd':	return IsPixel(char_d,iX,iY);
		case 'E':	return IsPixel(char_E,iX,iY);
		case 'e':	return IsPixel(char_e,iX,iY);
		case 'F':	return IsPixel(char_F,iX,iY);
		case 'f':	return IsPixel(char_f,iX,iY);
		case 'G':	return IsPixel(char_G,iX,iY);
		case 'g':	return IsPixel(char_g,iX,iY);
		case 'H':	return IsPixel(char_H,iX,iY);
		case 'h':	return IsPixel(char_h,iX,iY);
		case 'I':	return IsPixel(char_I,iX,iY);
		case 'i':	return IsPixel(char_i,iX,iY);
		case 'J':	return IsPixel(char_J,iX,iY);
		case 'j':	return IsPixel(char_j,iX,iY);
		case 'K':	return IsPixel(char_K,iX,iY);
		case 'k':	return IsPixel(char_k,iX,iY);
		case 'L':	return IsPixel(char_L,iX,iY);
		case 'l':	return IsPixel(char_l,iX,iY);
		case 'M':	return IsPixel(char_M,iX,iY);
		case 'm':	return IsPixel(char_m,iX,iY);
		case 'N':	return IsPixel(char_N,iX,iY);
		case 'n':	return IsPixel(char_n,iX,iY);
		case 'O':	return IsPixel(char_O,iX,iY);
		case 'o':	return IsPixel(char_o,iX,iY);
		case 'P':	return IsPixel(char_P,iX,iY);
		case 'p':	return IsPixel(char_P,iX,iY);
		case 'Q':	return IsPixel(char_Q,iX,iY);
		case 'q':	return IsPixel(char_q,iX,iY);
		case 'R':	return IsPixel(char_R,iX,iY);
		case 'r':	return IsPixel(char_r,iX,iY);
		case 'S':	return IsPixel(char_S,iX,iY);
		case 's':	return IsPixel(char_s,iX,iY);
		case 'T':	return IsPixel(char_T,iX,iY);
		case 't':	return IsPixel(char_t,iX,iY);
		case 'U':	return IsPixel(char_U,iX,iY);
		case 'u':	return IsPixel(char_u,iX,iY);
		case 'V':	return IsPixel(char_V,iX,iY);
		case 'v':	return IsPixel(char_v,iX,iY);
		case 'W':	return IsPixel(char_W,iX,iY);
		case 'w':	return IsPixel(char_w,iX,iY);
		case 'X':	return IsPixel(char_X,iX,iY);
		case 'x':	return IsPixel(char_x,iX,iY);
		case 'Y':	return IsPixel(char_Y,iX,iY);
		case 'y':	return IsPixel(char_y,iX,iY);
		case 'Z':	return IsPixel(char_Z,iX,iY);
		case 'z':	return IsPixel(char_z,iX,iY);
		case '0':	return IsPixel(char_0,iX,iY);
		case '1':	return IsPixel(char_1,iX,iY);
		case '2':	return IsPixel(char_2,iX,iY);
		case '3':	return IsPixel(char_3,iX,iY);
		case '4':	return IsPixel(char_4,iX,iY);
		case '5':	return IsPixel(char_5,iX,iY);
		case '6':	return IsPixel(char_6,iX,iY);
		case '7':	return IsPixel(char_7,iX,iY);
		case '8':	return IsPixel(char_8,iX,iY);
		case '9':	return IsPixel(char_9,iX,iY);
		default:	return IsPixel(char_Space,iX,iY);
	}
}

char GetPixelMatrix(Matrix8x8 c_Letter,char iX, char iY){
	return IsPixel(c_Letter,iX,iY);
}

void WritePixel(Matrix8x8 &lLet,byte iX,byte iY,byte iPixel){
	byte iYBin = GetBinary(iY);
	switch(iX){
		case 0:	if (iPixel == 1) {lLet.b0 += (IsPixel(lLet,iX,iY) == 0) ? iYBin : 0;} else {lLet.b0 -= IsPixel(lLet,iX,iY) ? iYBin : 0;}  return;
		case 1:	if (iPixel == 1) {lLet.b1 += (IsPixel(lLet,iX,iY) == 0) ? iYBin : 0;} else {lLet.b1 -= IsPixel(lLet,iX,iY) ? iYBin : 0;}  return;
		case 2:	if (iPixel == 1) {lLet.b2 += (IsPixel(lLet,iX,iY) == 0) ? iYBin : 0;} else {lLet.b2 -= IsPixel(lLet,iX,iY) ? iYBin : 0;}  return;
		case 3:	if (iPixel == 1) {lLet.b3 += (IsPixel(lLet,iX,iY) == 0) ? iYBin : 0;} else {lLet.b3 -= IsPixel(lLet,iX,iY) ? iYBin : 0;}  return;
		case 4:	if (iPixel == 1) {lLet.b4 += (IsPixel(lLet,iX,iY) == 0) ? iYBin : 0;} else {lLet.b4 -= IsPixel(lLet,iX,iY) ? iYBin : 0;}  return;
		case 5:	if (iPixel == 1) {lLet.b5 += (IsPixel(lLet,iX,iY) == 0) ? iYBin : 0;} else {lLet.b5 -= IsPixel(lLet,iX,iY) ? iYBin : 0;}  return;
		case 6:	if (iPixel == 1) {lLet.b6 += (IsPixel(lLet,iX,iY) == 0) ? iYBin : 0;} else {lLet.b6 -= IsPixel(lLet,iX,iY) ? iYBin : 0;}  return;
		case 7:	if (iPixel == 1) {lLet.b7 += (IsPixel(lLet,iX,iY) == 0) ? iYBin : 0;} else {lLet.b7 -= IsPixel(lLet,iX,iY) ? iYBin : 0;}  return;
	}
}