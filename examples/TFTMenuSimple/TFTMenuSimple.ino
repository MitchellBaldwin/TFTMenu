/*
* Name:		TFTMenuSimple.ino
* Created:	9/27/2024 10:47:26 AM
* Author:	Mitchell Baldwin copyright 2024
*
*	Test display of TFTMenu with representative Items of various MenuItemTypes
* 
*/

#include "src/DEBUG Macros.h"

#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();

#include <TFTMenu.h>
MenuItemClass* item1 = new MenuItemClass("Power", 20, 20, 64, 12);
MenuItemClass* item2 = new MenuItemClass("Nav", 20, 32, 64, 12);
TFTMenuClass mainMenu;

void setup()
{
	Serial.begin(115200);

	tft.init();
	tft.setRotation(3);
	
	_PP("Display extents: ")
	_PP(tft.width())
	_PP("x")
	_PL(tft.height())

	// Display power is not eanbled by default when the board is powered through the LiPo battery connector
	//so must explicitly turn LCD power on:
	pinMode(LCD_POWER_ON, OUTPUT);
	digitalWrite(LCD_POWER_ON, HIGH);
	pinMode(LCD_BL, OUTPUT);
	digitalWrite(LCD_BL, HIGH);

	// Clear screen:
	tft.fillScreen(TFT_BLACK);

	// Draw header:
	tft.setTextSize(1);
	tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
	tft.setTextDatum(TC_DATUM);
	tft.drawString("Testing TFTMenu", tft.width() / 2, 2);

	// Build an example menu:
	mainMenu.Init(&tft);	// Do not reinitialize; Init() is called from the constructor! <- this turned out to be a problem, resulting in guru meditation error(s)

	item1->Init(&tft);
	//item1->Draw(&tft, true);
	item2->Init(&tft);
	//item2->Draw(&tft, false);

	mainMenu.AddItem(item1);
	mainMenu.AddItem(item2);

	mainMenu.Draw();

}

void loop()
{
  
}
