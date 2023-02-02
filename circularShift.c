#include <stdio.h>

/*
Write a library function to beform circular/wrap-around bit shifting, e.g. (8-bit):
  0b11000011 << 2 = 0b00001111
  0b00001100 >> 4 = 0b11000000

The API and required types are provided below (do not modify).
Use the body of main to test your code.
Feel free to debug as you go (printf is your friend).
*/

//-------------------------------------------------------------------------------------------------
// Do not modify below
typedef enum
{
  SHIFT_LEFT,
  SHIFT_RIGHT
} ShiftDir_E;

static int CircularShiftBits(const int value, const int numToShift, const ShiftDir_E shiftDir)
{
// Do not modify above
//-------------------------------------------------------------------------------------------------
  return 0;
}

int main() {

  printf("expected? %d\n", (int)(CircularShiftBits(0b00001111, 4, SHIFT_LEFT) == 0b11110000));
  printf("expected? %d\n", (int)(CircularShiftBits(0b11110000, 4, SHIFT_RIGHT) == 0b00001111));


  return 0;
}
