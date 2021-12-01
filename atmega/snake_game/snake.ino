unsigned char snakeBody[50][2] = {
  {3,3},
};
unsigned char snakeLength = 1;

void updateSnake() {
  for (int i = snakeLength - 2; i>=0; i--) {
    //Split up to avoid copy problems
    snakeBody[i+1][0] = snakeBody[i][0];
    snakeBody[i+1][1] = snakeBody[i][1];
  }
  if (input[0]!=0 || input[1]!=0) {
    started=true;  
  }
  snakeBody[0][0] = (input[0] + snakeBody[0][0]) % 8;
  snakeBody[0][1] = (input[1] + snakeBody[0][1]) % 8;
  if (onSnake(snakeBody[0],true)) {
      resetFunc();
  
  }
  prepareGridForDraw();
}
void prepareGridForDraw() {
  //Clear grid to zeros
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      grid[i][j] = 0;
    }
  }
  //Loop through snake body and 
  for (int i = 0; i < snakeLength; i++) {
    grid[snakeBody[i][0]][snakeBody[i][1]] = 1;
  }

}
void expandSnake(unsigned char amount) {
    snakeBody[snakeLength][0] = snakeBody[snakeLength-1][0] ;
    snakeBody[snakeLength][1] = snakeBody[snakeLength-1][1] ;
    snakeLength++;
}
bool onSnake(unsigned char* pos,bool ignoreHead) {
   for (int i = 0; i < snakeLength; i++) {
      if (snakeBody[i][0] == pos[0] && snakeBody[i][1] == pos[1]) {
        if (ignoreHead && i==0) {
          continue;
        }
        return true;
      }
  }
  return false;
}
