/*
 Name:		TFTMenuTest.ino
 Created:	9/26/2024 6:22:44 AM
 Author:	Mitchell Baldwin copyright 2024

 v1.0 - Initial design

*/

#include <TFT_eSPI.h>
TFT_eSPI tft;

#include <TFTMenu.h>

void setup() {
	
	Serial.begin(115200);
	if (!Serial)
	{
		while (!Serial);		// Wait for serial debug port
	}
	else
	{
		Serial.println("");
		Serial.println("Serial debug port initialized");
	}

	// Display power is not eanbled by default when the board is powered through the LiPo battery connector
	//so must explicitly turn LCD power on:
	pinMode(LCD_POWER_ON, OUTPUT);
	digitalWrite(LCD_POWER_ON, HIGH);

	tft.init();
	tft.setRotation(1);

	// Clear display:
	tft.fillScreen(TFT_BLACK);
	
	// Draw header:
	tft.setTextSize(1);
	tft.setTextColor(TFT_BLUE, TFT_BLACK, false);
	tft.setTextDatum(TC_DATUM);
	tft.drawString("Testing TFTMenu", tft.width() / 2, 2);
	
	TFTMenuClass* MainMenu = new TFTMenuClass(&tft);

	MenuItemClass* item = new MenuItemClass("Power", 20, 20, 64, 12, MenuItemClass::MenuItemTypes::OffOn);
	item->Init(&tft);
	MainMenu->AddItem(item);

	item = new MenuItemClass("Watts", 20, 40, 64, 12, MenuItemClass::MenuItemTypes::Numeric);
	item->Init(&tft);
	item->SetMinValue(0);
	item->SetMaxValue(100);
	item->SetValue(50);
	MainMenu->AddItem(item);

	item = new MenuItemClass("Reset", 100, 40, 64, 12, MenuItemClass::MenuItemTypes::Action);
	item->Init(&tft);
	MainMenu->AddItem(item);

	MainMenu->Draw();

}

void loop() {
  
}
