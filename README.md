# Controlling NJW1194 pre-amp with RasPi Pico or Arduino Nano

### NJW1194 has:
- 4 stereo inputs
- SPI interface
- controls Volume (separate L/R)
- controls Tone (Bass/Treble)

### TODO:

- Utilize rotary encoder w. push button for Volume/Mute control
- Use existing pots fed to ADC for controlling Tone + Balance

### Audio inputs:
- AM Radio
- FM Radio
- IP Radio (Raspberry Pi as internet radio stream receiver)
- External input (TV)

### MCU inputs - total 12 GPI:
- Power switch - 1 GPI
- Phono/AM/FM switch - 3 GPI
- Tape Select - 1 GPI
- Volume (rotary ctrl) - 2 GPI
- Mute - 1 GPI
- Bass/Treble/Balance - 3 ADC
- IR receiver - 1 GPI

### MCU outputs - total 9 GPO:
- Power relay - 1 GPO
- SPI (Data, Clock, ChipSelect) - 3 GPO
- RGB dial light (PWM) - 3 GPO
- Display I2C - 2 GPO

MCU needs 21 GPIO lines in total, plus maybe another 2 to "talk" to Raspberry Pi ...