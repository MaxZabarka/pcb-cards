unsigned char reverse(unsigned char b) {
  b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
  b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
  b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
  return b;
}
int seed()
{
    int value = 0;
    for (int a=0;a<8;a++)
    {
      value = value + (analogRead(a));
    }
    return value + millis();
}

unsigned char array_to_byte(unsigned char char_array[]) {
  return ((char_array[7] << 0) +
          (char_array[6] << 1) +
          (char_array[5] << 2) +
          (char_array[4] << 3) +
          (char_array[3] << 4) +
          (char_array[2] << 5) +
          (char_array[1] << 6) +
          (char_array[0] << 7));
}
unsigned char msb_bits(unsigned char input) {
  return input >> 4 & B00001111;
}
unsigned char lsb_bits(unsigned char input) {
  return input & B00001111;
}
void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  unsigned char register_two = B10000000;
  // This shifts 8 bits out MSB first,
  //on the rising edge of the clock,
  //clock idles low
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);
  //for each bit in the byte myDataOut&#xFFFD;
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights.
  for (int i = 7; i >= 0; i--)  {
    digitalWrite(myClockPin, 0);
    //if the value passed to myDataOut and a bitmask result
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000
    // and proceeds to set pinState to 1.
    if ( myDataOut & (1 << i) ) {
      pinState = 1;
    }
    else {
      pinState = 0;
    }
    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }
  //stop shifting
  digitalWrite(myClockPin, 0);
}
