# dave-o-rec
The big button what records the trucks!

Requires the `DigiKeyboard.h` library, which is included in the Arduino IDE's DigiStump package.

## Setup Instructions
In Arduino IDE, go to Tools -> Boards -> Board Manager and install `DigiStump AVR Boards`.

Once installed, Under Tools -> Boards -> DigiStump AVR Boards, select your board (I went with Default and it worked just fine).

Change `pinBTN` to whatever pin you want to use as the button press. I've found that `P5` appears to reset the board rather than do anything when shorted, and I'm using `P1` as the LED output since it has the inline LED. Other boards may have `P0` as the LED pin, so check your board.

Connect `pinBTN` to the button and the other side to `GND`.

Upload sketch and enjoy.

You can optionally hook an LED across `pinLED` and `GND` and it will illuminate at the same time as the board LED, which is fun and cool.

## Usage
Do something cool in a videogame and then smash that like button

The button will be disabled for five seconds (denoted by the LED illuminating) between records, just to prevent bouncing trying to trigger multiple records and crashing your computer.

## Further development
Probably make it so the button pin isn't an `INPUT_PULLUP`, I dunno

Could change the LED to be on normally and off for the five seconds while recording by tweaking the `digitalWrite(pinLED, <x>)` lines
