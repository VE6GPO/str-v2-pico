#include"NJW1194.h"

void NJW1194::initialize(int L_PIN , int C_PIN , int D_PIN , bool CA[4]){
    latch_pin = L_PIN;
    clk_pin   = C_PIN;
    data_pin  = D_PIN;

    pinMode(latch_pin , OUTPUT);
    pinMode(clk_pin , OUTPUT);
    pinMode(data_pin , OUTPUT);
    digitalWrite(latch_pin , HIGH);
    for(int i = 0 ; i < 4 ; i++){
    chip_address[i] = CA[i];
    }
    
 data = 0b11111111;
 byte address = 0b00000000;
 send_data(data , address);

 data = 0b11111111;
 address = 0b00010000;
 send_data(data , address);

 data = 0b00000000;
 address = 0b00100000;
 send_data(data , address);

 data = 0b00000000;
 address = 0b00110000;
 send_data(data , address);
 
 data = 0b00000000;
 address = 0b01000000;
 send_data(data , address);
}

void NJW1194::volume_control_1 (float value){
  if(value == 0){
    data = 64;
  }
else if (value > 31.5){
  data = 0;
}
else if (value < -95){
  data = 255;
}
else if( value > 0){
  data = 64 -  (byte)(value/0.5);
}
else if( value < 0){
  data = (byte)(-1*value/0.5) + 64;
}

byte address = 0b00000000;
send_data(data , address);
}



void NJW1194::volume_control_2 (float value){
  if(value == 0){
    data = 64;
  }
else if (value > 31.5){
  data = 0;
}
else if (value < -95){
  data = 255;
}
else if( value > 0){
  data = 64 -  (byte)(value/0.5);
}
else if( value < 0){
  data = (byte)(-1*value/0.5) + 64;
}

byte address = 0b00010000;
send_data(data , address);
}


void NJW1194::input_selector   (int value){
  data = value << 2;
  byte address = 0b00100000;
  send_data(data , address);
}

void NJW1194::treble_control(int value){
treble_value = value;
  if (value == 0){
    data = 0;
  }
  else if(value > 0){
    data = 0b10000100;
    byte temp = byte(value);
    data = data | temp<<3;
  }
  else if(value < 0){
    data = 0b00000100;
    byte temp = byte(-1*value);
    data = data | temp <<3;
  }
  byte address =  0b00110000;
  send_data(data , address);
}


void NJW1194::bass_control(int value){

  if (value == 0){
    data = 0;
  }
  else if(value > 0){
    data = 0b10000000;
    byte temp = byte(value);
    data = data | temp<<3;
  }
  else if(value < 0){
    data = 0b00000000;
    byte temp = byte(-1*value);
    data = data | temp <<3;
  }
  data = data | 1<<2;
  byte address =  0b00100000;
  send_data(data , address);
}

void NJW1194::tone_bypass_switch (bool value){

  if(value == true){
    data = 0b10000100;
    byte temp = treble_value ;
    data = data | temp<<3;
  }
  else{
    data = 0b00000000;
    byte temp = treble_value ;
    data = data | temp <<3;
  }
  byte address =  0b00110000;
  send_data(data , address);
}


void NJW1194::send_data(byte data , byte address){
  
for(int i = 0 ; i < 4 ; i++){
  address = address | chip_address[i] << i;
}

digitalWrite(latch_pin , LOW);
delay(1);
shiftOut(data_pin, clk_pin, LSBFIRST, data);
shiftOut(data_pin, clk_pin, LSBFIRST, address);
delay(1);
digitalWrite(latch_pin , HIGH);
}