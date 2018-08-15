// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       sprite_test.ino
    Created:	8/13/2018 7:55:33 AM
    Author:     Alan Ryker
*/

// Define User Types below here or use a .h file
//
#include <Arduboy.h>
Arduboy arduboy;
const unsigned char player[] PROGMEM = { 0xfe, 0x1, 0x3d, 0x25, 0x25, 0x3d, 0x1, 0x1, 0xc1, 
	0x1, 0x3d, 0x25, 0x25, 0x3d, 0x1, 0xfe, 0x7f, 0x80, 0x9c, 0xbc, 0xb0, 0xb0, 0xb2, 0xb2, 
	0xb3, 0xb0, 0xb0, 0xb0, 0xbc, 0x9c, 0x80, 0x7f, };
const unsigned char background[] PROGMEM = { 0x84, 0x20, 0x9, 0x00, 0x24, 0x00, 0x10, 0x80, };
const int playerWidth = 16;
const int playerHeight = 16;
const int maxRight = 128;
const int maxDown = 64;

int playerx = 5;
int playery = 10;

// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts
void setup()
{
	arduboy.begin();
	arduboy.clear();
}

// Add the main program code into the continuous loop() function
void loop()
{
	arduboy.clear();
	if(arduboy.pressed(LEFT_BUTTON) && playerx > 0)
	{
		playerx--;
	}
	if(arduboy.pressed(RIGHT_BUTTON) && playerx < (WIDTH-playerWidth))
	{
		playerx++;
	}
	if(arduboy.pressed(UP_BUTTON) && playery > 0)
	{
		playery--;
	}
	if(arduboy.pressed(DOWN_BUTTON) && playery < (HEIGHT-playerHeight))
	{
		playery++;
	}

	for (int bgx = 0; bgx < 128; bgx = bgx + 8)
	{
		for (int bgy = 0; bgy < 64; bgy = bgy + 8)
		{
			arduboy.drawBitmap(bgx, bgy, background, 8, 8, WHITE);
		}
	}
	arduboy.fillRect(playerx, playery, 16, 16, BLACK);
	arduboy.drawBitmap(playerx, playery, player, 16, 16, WHITE);

	arduboy.display();
}
