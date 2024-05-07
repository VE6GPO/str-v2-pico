#include "Arduino.h"

class NJW1194{
  private:
    byte data;
    bool chip_address[4] = {0,0,0,0};
    bool select_adress[4];
    int latch_pin;
    int clk_pin;
    int data_pin;
    byte treble_value = 1;
    bool bypass_switch = true;
  public:
    void initialize(int L_PIN , int C_PIN , int D_pin , bool CA[4]);
    void volume_control_1   (float value);
    void volume_control_2   (float value);
    void input_selector     (int value);  
    void treble_control     (int vlaue);  
    void bass_control       (int vlaue);  
    void send_data          (byte D , byte Ad);
    void tone_bypass_switch (bool value);
};