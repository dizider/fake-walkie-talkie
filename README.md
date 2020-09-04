# Fake walkie-talkie

## It's a game!
If you are looking for working walkie-talkie based on ESP8266/32 and RF24, you will
be disappoited.

### Game example
Children have the task collect all components. Then they put them togethe
accorging to [schematic](schematic.pdf). If wiring is correct some sound will
be played.

## How does it works?
Program check if all components are correctly wired ([schematic](schematic.pdf)).
If YES, play soud files from SD card (from *1.wav* to *n.wav*) saved in the
root directory, otherwise it does nothing.

## Sound format
Only mono 8-bit WAV with sample rate from 8 to 32KHz are supported.

## Sound playback
Tracks must be named from *1* to *n*.
