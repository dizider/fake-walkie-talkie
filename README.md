# Fake walkie-talkie

Program check if all components are correctly wired ([schematic](schematic.pdf)).
If YES, play soud files from SD card (from *1.wav* to *n.wav*) saved in the
root directory, otherwise it does nothing.

## Sound format
Only mono 8-bit WAV with sample rate from 8 to 32KHz are supported.

## Sound playback
Tracks must be named from *1* to *n*.
