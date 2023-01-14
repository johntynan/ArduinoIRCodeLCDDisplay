// John Tynan
// Adapted from multiple sources including...
// 
//www.elegoo.com
//2016.12.9

// include the library code:
#include "IRremote.h"

// https://create.arduino.cc/projecthub/YoussefSabaa/lcd-display-in-real-time-ea0b7b
#include <LiquidCrystal.h>

/*
 * IR Receiver Module
 * GND: 1
 * 5v: 2
 * 13: 3
 */

/* 
 *  LCD1602 - 16 char / 2 line LCD Display  
 *  GND: VSS, VO, RW, K
 *  5V: VDD
 *  12: RS
 *  11: E
 *  2: D7
 *  3: D6
 *  4: D5
 *  5: D4
 *  3.3v: A
 */

// initialize the library with the numbers of the interface pins

// https://forum.arduino.cc/t/liquidcrystal-lcd-code-clarification/427857/2
// fill in aduino pin #s used to control LCD
const int rs=12; // arduino pin connect to LCD RS pin
const int en=11; // arduino pin connect to LCD Enable pin
const int d4=5;  // arduino pin connected to LCD data bit 4 pin
const int d5=4;  // arduino pin connected to LCD data bit 5 pin
const int d6=3;  // arduino pin connected to LCD data bit 6 pin
const int d7=2;  // arduino pin connected to LCD data bit 7 pin

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // constructor to initialize pins in library
// LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

/*-----( Global Constants )-----*/
const int receiver = 13;      // Signal Pin of IR receiver to Arduino Digital Pin 13


/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

// intitial array values
int nCol = 10;
int nRow = 2;
int myArray[2][10] = {
// float myArray[2][10] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};



/*-----( Function )-----*/
int setGameData() {          // takes action based on IR code received

/* 
  // https://www.delftstack.com/howto/arduino/arduino-2d-array
  // intitial array values
  // int nRow = 2;
  // int nCol = 10;
  int myArray[nRow][nCol] = {
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  };
*/  
  // set value
  // myArray[nRow][nCol] = 0;
  // get value
  // int myValue = myArray[nRow][nCol];



  //  int nRow = 2;
  //  int nCol = 10;

  int myValue = myArray[nRow][nCol];

  Serial.println("setGameData");
  Serial.println(nCol);
  Serial.println(nRow);
  Serial.println(myArray[nRow][nCol]);
  Serial.println(myValue);

  if (myValue == 0){
    myArray[1][nCol] = 1;
    lcd.write(nCol);
  }
/*
  if (myValue == 1){
    lcd.write(" Already Selected"); 
  };

*/
};

/*-----( Function )-----*/
void translateIR() {          // takes action based on IR code received
// describing Remote IR codes 

  switch(results.value){
    case 0xFFA25D: Serial.println("POWER");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("POWER");
    break;
    case 0xFFE21D: Serial.println("FUNC/STOP");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("FUNC/STOP");
    break;
    case 0xFF629D: Serial.println("VOL+");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("VOL+");
    break;
    case 0xFF22DD: Serial.println("FAST BACK");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("FAST BACK");
    break;
    case 0xFF02FD: Serial.println("PAUSE");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("PAUSE");
    break;
    case 0xFFC23D: Serial.println("FAST FORWARD");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("FAST FORWARD");
    break;
    case 0xFFE01F: Serial.println("DOWN");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("DOWN");
    break;
    case 0xFFA857: Serial.println("VOL-");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("VOL-");
    break;
    case 0xFF906F: Serial.println("UP");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("UP");
    break;
    case 0xFF9867: Serial.println("EQ");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("EQ");
    break;
    case 0xFFB04F: Serial.println("ST/REPT");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("ST/REPT");
    break;
    case 0xFF6897: Serial.println("0");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("0");

      nCol = 10;
      nRow = 2;
      setGameData();
    
    break;
    case 0xFF30CF: Serial.println("1");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("1");

      nCol = 1;
      nRow = 2;
      setGameData();

    break;
    case 0xFF18E7: Serial.println("2");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("2");
      
      nCol = 2;
      nRow = 2;
      setGameData();
      
    break;
    case 0xFF7A85: Serial.println("3");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("3");
      
      nCol = 3;
      nRow = 2;
      setGameData();
      
    break;
    case 0xFF10EF: Serial.println("4");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("4");
      
      nCol = 4;
      nRow = 2;
      setGameData();
    
    break;
    case 0xFF38C7: Serial.println("5");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("5");
       
      nCol = 5;
      nRow = 2;
      setGameData();
      
    break;
    case 0xFF5AA5: Serial.println("6");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("6");
    
      nCol = 6;
      nRow = 2;
      setGameData();
      
    break;
    case 0xFF42BD: Serial.println("7");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("7");

      nCol = 7;
      nRow = 2;
      setGameData();

    break;
    case 0xFF4AB5: Serial.println("8");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("8");

          
      nCol = 8;
      nRow = 2;
      setGameData();
      
    break;
    case 0xFF52AD: Serial.println("9");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("9");
    
      nCol = 9;
      nRow = 2;
      setGameData();
      
    break;
    case 0xFFFFFFFF: Serial.println(" REPEAT");
      lcd.clear();
      // lcd.write(results.value);
      lcd.write("REPEAT");
    break;

  default: 
    Serial.print(" other button   ");
    Serial.println(results.value);
    lcd.clear();
    // lcd.write(results.value);
    lcd.write("Invalid Input");


  }// End Case


} //END translateIR


void setup(){   /*----( SETUP: RUNS ONCE )----*/
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // initialize the serial communications:
  Serial.begin(9600);

  // Print a message to the LCD.
  lcd.print("initializing...");
  delay(500);
  // clear the screen
  lcd.clear();
  
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn();           // Start the receiver

  
}/*--(end setup )---*/

void loop(){   /*----( LOOP: RUNS CONSTANTLY )----*/
  if (irrecv.decode(&results))   // have we received an IR signal?
  {

    translateIR();
    delay(500);                 // Do not get immediate repeat
    irrecv.resume();            // receive the next value    
  }

  // https://create.arduino.cc/projecthub/YoussefSabaa/lcd-display-in-real-time-ea0b7b
  // when characters arrive over the serial port...
  if (Serial.available()) {

     // Serial.println("Serial Available");   

    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }    
    // print the number of seconds since reset:
    // lcd.print(millis()/1000);

    }

}/* --(end main loop )-- */
