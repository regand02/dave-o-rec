# dave-o-rec
The big button what records the trucks!

Requires the DigiKeyboard.h library, which is included in the Arduino IDE's DigiSpark package.

## Setup Instructions
In Arduino IDE, go to Tools -> Boards -> Board Manager and install DigiStump AVR Boards.

Once instealled, Under Tools -> Boards -> DigiStump AVR Boards, select your board (I went with Default and it worked just fine).

Change pinBTN to whatever pin you want to use as the button press. I've found that 5 appears to reset the board rather than do anything when shorted, and I'm using 1 as the LED output, so maybe don't use those ones.

Connect that pin to the button and the other side to GND.

Run code.

You can optionally hook an LED across pin 1 and GND and it will illuminate at the same time as the board LED, which is fun and cool.

## Usage
Do something cool in a videogame and then smash that like button

The button will be disabled for five seconds (denoted by the LED illuminating) between records, just to prevent bouncing trying to trigger multiple records and crashing your computer.

You can reset the board by holding the button down for three seconds, let go when it flashes and it will restart.

## Further development
Probably make it so the pin isn't an INPUT_PULLUP, I dunno
