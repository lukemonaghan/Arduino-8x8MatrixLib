============
8x8MatrixLib
Luke Monaghan
03/01/14
Arduino Scrolling 8x8 LED matrix example with library
============

============
letters.h
============
Sketch size = 3220
Estimated ram use = 496

8x8 matrix letters binary library.
I have tried to make this as minimal as possible to preserve as much memory for arduino devices as possible.
It uses bitwise operations on chars(signed byte values) to store on off boolean switches, using the whole 8 bits with no waste.
Currently it supports A-Z,a-z and 0-9.

To search through the file search for @INFO tags, doing so will jump complete segments. saves scrolling.

Fell free to use for educational use, any other forms of use must ask for permission first.

I am not responsible for any damage to any of your parts, code, wires, or animals.


============
TextMatrix.ino
============
Sketch size = 10340 (with Letters.h)
Estimated ram use = 1350 (with Letters.h)

8x8 matrix letters binary sample code.
Display scrolling text using my Letter.h library, code is commented for educational use.

Fell free to use for educational use, any other forms of use must ask for permission first.

I am not responsible for any damage to any of your parts, code, wires, or animals.

============