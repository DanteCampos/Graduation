#include <stdio.h>

/*
Flips a specific bit from an int value
The bit position must be between 0 and 31 (because an int have 32 bits)
*/
void toggle(int *value, int bit){
	unsigned int copy = *value, mask1=1, mask2=1;
	
	//CAPTURARE THE REQUESTED BIT, THEN FLIPS IT
	mask1 = ~((mask1<<bit) & *value); // mask1 = 0000b000 -> mask1 = 1111B111
	//MASK TO ERASE THE BIT FROM THE VALUE
	mask2 = mask2 << bit; //mask2 = 00001000
	//PUTTING THE FLIPPED BIT IN THE VALUE
	*value = (*value | mask2) & mask1; // (copy = bbbb1bbb) & 1111B111 = bbbbBbbb
	
	return;
}

int main() {
  int value;

  value = 0x00000000;
  toggle(&value, 0);
  printf("0x00000001 == 0x%.8X\n", value);

  value = 0xF0000000;
  toggle(&value, 31);
  printf("0x70000000 == 0x%.8X\n", value);

  value = 0xF002000F;
  toggle(&value, 16);
  printf("0xF003000F == 0x%.8X\n", value);

  return 0;

}
