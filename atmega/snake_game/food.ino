unsigned char food[2];
const unsigned char EXPANSION_RATE = 1;


void updateFood() {

  if (onSnake(food,false)) {
    expandSnake(EXPANSION_RATE);

  } 
  while(onSnake(food,false)) {
    food[0] = random(0,8);
    food[1] = random(0,8);
  }
  if (started) {
      grid[food[0]][food[1]] = 1;

  }

}
void initFood() {
  do {
    food[0] = random(0,8);
    food[1] = random(0,8);
  }
  while(onSnake(food,false));
}
