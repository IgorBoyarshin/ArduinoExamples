/* Uses library from https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads GNU General Public License, version 3 (GPL-3.0) */
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C  lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the I2C bus address for an unmodified backpack

byte heart[8] = {
  B00000,
  B01010,
  B10101,
  B10001,
  B01010,
  B00100,
  B00000,
};

byte smile[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};


const int ROWS = 2;
const int COLUMNS = 16;
 
void setup()
{  
  lcd.begin (COLUMNS, ROWS); 
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(LOW);

  lcd.createChar(0, smile);

  //lcd.setCursor(0,1);
  //lcd.print("");  

  bool upperRow = true;
  for (int column = 0; column < COLUMNS; column++) {
    if (upperRow) {
      lcd.setCursor(column, 0);
    } else {
      lcd.setCursor(column, 1);
    }

    upperRow = !upperRow;
    lcd.write(byte(0));
  }

  /*
  bool doPut = true;
  lcd.home(); // set cursor to 0,0
  for (int row = 0; row < ROWS; row++) {
    lcd.setCursor(0, row);
    for (int column = 0; column < COLUMNS; column++) {
      if (doPut) {
        lcd.write(byte(0));
      } else {
        lcd.write(" ");
      }

      doPut = !doPut;
    }    
  }
  */
}
 
void loop(){}
