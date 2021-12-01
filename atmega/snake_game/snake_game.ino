void(* resetFunc) (void) = 0;

int latchPin = 6;
int clockPin = 5;
int dataPin = 4;

int upPin = 7;
int downPin = 8;
int leftPin = 9;
int rightPin = 10;

int SNAKE_SPEED = 2;
unsigned char *input;
bool started = false;
unsigned long currentTime;
unsigned int lastRenderTime = 0;
float secondsSinceLastRender;

unsigned char grid[8][8];
void setup() {
  randomSeed(seed());
  Serial.begin(500000);
  pinMode(latchPin, OUTPUT);
  initFood();
  pinMode(upPin,OUTPUT);
  pinMode(downPin,OUTPUT);
  pinMode(leftPin,OUTPUT);
  pinMode(rightPin,OUTPUT);


}

void draw(unsigned char grid[][8]) {
  for (unsigned char i = 0; i < 8; i++) {
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, msb_bits(1 << i) << 4| msb_bits(~array_to_byte(grid[i])));
    shiftOut(dataPin, clockPin, reverse(lsb_bits(1 << i))  | lsb_bits(~array_to_byte(grid[i])));
    digitalWrite(latchPin, 1);
  }
}
void loop() {
  currentTime = millis();
  secondsSinceLastRender = (currentTime - lastRenderTime) / 1000.0;
  input = getInput();
  if (secondsSinceLastRender > (1.0 / SNAKE_SPEED)) {
        lastRenderTime = currentTime;
    
        updateSnake();
        updateFood();
  }
  draw(grid);
 
}
