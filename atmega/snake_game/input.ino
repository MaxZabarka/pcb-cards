unsigned char inputDirection[] = {1, 0};
static unsigned char rv[2];

unsigned char* getInput() {
  if (digitalRead(downPin) > 0.7 && rv[0]==0) {
    rv[0] = 1;
    rv[1] = 0;
  } else if (digitalRead(upPin) > 0.7 && rv[0]==0) {
    rv[0] = -1;
    rv[1] = 0;
  } else if (digitalRead(rightPin) > 0.7 && rv[1]==0) {
    rv[0] = 0;
    rv[1] = 1;
  } else if (digitalRead(leftPin) > 0.7 && rv[1]==0) {
    rv[0] = 0;
    rv[1] = -1;
  }

  return rv;
}
