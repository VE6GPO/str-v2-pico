#include "NJW1194.h"

bool chip_address[4] = {0,0,0,0};

NJW1194 audio_chip;
void setup() {
Serial.begin(9600);
audio_chip.initialize(8,9,10 , chip_address); //audio_chip.initialize(latch_pin ,clock_pin , data_pin , chip_address)
audio_chip.input_selector(1); // value from 0 to 4; 0 for mute
audio_chip.volume_control_1(31); //value from +31.5 to -95; other values mean mute
audio_chip.volume_control_2(31);// value from +31.5 to -95; other values mean mute
audio_chip.treble_control(5); // value from 10 to -10
audio_chip.bass_control(5);// value from 10 to -10
audio_chip.tone_bypass_switch(true); 
}

void loop() {
  // main code here

}