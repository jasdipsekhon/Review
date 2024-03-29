#include "teslaPrac.h"
#include <stdint.h>
#include <string.h>
static void even_num(uint8_t num) {
    num % 2 == 0 ? printf("even\n") : printf("odd\n");
}

// convert array to integer
uint32_t sl_byte_conversion__from_network_to_uint32(const uint8_t *bytes, const size_t length_of_bytes) { 
  uint32_t answer = 0;
  int number = 0;
  for (int i = 1; i < length_of_bytes; i++) {
      int value =  bytes[i];
      while (value != 0) {
        value = value / 10;
        number = number * 10;
      }
      number = number + bytes[i];
  }
  printf("%i\n", number);
  return number;
}

void init_state_machine(struct_s *traffic_light, time_s timings) { // pointer to struct
    if (timings.red_time_in_sec < 10) {
      timings.red_time_in_sec = 10;
    } else if (timings.green_time_in_sec < 10) {
      timings.green_time_in_sec = 10;
    }
    else if (3 > timings.yellow_time_in_sec || timings.yellow_time_in_sec > 7){
      timings.yellow_time_in_sec = 3;
    }
    traffic_light->color = RED;
    traffic_light->timings = timings;
}

void state_machine(struct_s *traffic_light, uint32_t hz_1_counter) {
  switch (traffic_light->color) {
       RED: {
         if (traffic_light->timings.red_time_in_sec % 10 == hz_1_counter) {
             traffic_light->color = GREEN;
         }
           break;
       }
       GREEN: {
           break;
       }
       YELLOW: {
           break;
       }
       default:{break;}
  }
}

// get highest number in array
uint32_t get_highest(const uint32_t *array, size_t array_size) {
  if (array == NULL || array_size <= 0) {
    return 0;
  }
  uint32_t highest = array[0];
  for (int i = 1; i < array_size; i++) {
    if (array[i] > highest) {
      highest = array[i];
    }
  }
  printf("%i\n", highest);
  return highest;
}

// get right most set bit
// starts from LSB
static void get_right_most_set_bit(uint8_t num) {
  uint8_t m = 0b00000001;
  int answer = 0;
  while ((num & m) == 0) {
    m = m << 1;
    answer++;
  }
  printf("%i\n", answer);
}

static void get_left_most_set_bit(uint8_t num) {
  uint8_t m = 0b10000000;
  int answer = 8;
  while ((num & m) == 0) {
      m = m >> 1;
      answer--;
  }
  printf("%i\n", answer);
}

void swapBits(uint8_t *b) {
  // Answer: TODO

  *b = (*b & 0x0F) << 4 | (*b & 0xF0 >> 4);
  printf("%i\n", *b);
}

typedef struct{
  uint32_t x ,y;
}Point;

int multiply(Point *p) {
  return p->x * p->y;
}

int main() {
#ifdef DEBUG_TEST_1 // Macro Practice
  printf("MACRO: %i\n", MACRO);
  printf("Area of Circle: %0.3f\n", AREA(2));
#endif

#ifdef DEBUG_TEST_2
  printf("MIN: %i\n", MIN(2, 5));
#endif

  uint8_t num = 0b00000111; // Shifting
  printf("No shift: %i\n", num);
  num >>= 1;
  printf("Shift by One: %i\n", num);

  int count = 0; // Count Set Bits
  while (num) {
    if ((num & 1) == 1) {
      count++;
    }
    num >>= 1;
  }
  printf("Count Set Bits: %i\n", count);

  even_num(5); // Check if even number
  even_num(2);
  even_num(30);

  uint32_t i = 0x1234ABCD; // Read bytes from 32 bit variable (4 bytes)
  printf("0x%X\n", i >> 24);
  printf("0x%X\n", (i >> 16) & 0xFF);
  printf("0x%X\n", (i >> 8) & 0xFF);
  printf("0x%X\n", (i >> 0) & 0xFF);

  char a[] = "stupid"; // Reverse String
  int size = strlen(a);
  for (int i = 0; i < size / 2; i++) {
    char temp = a[i];
    a[i] = a[size - 1 - i];
    a[size - 1 - i] = temp;
  }
  printf("%s\n", a);

  uint8_t j = 4;
  j |= (3 << 0); // Set bit
  printf("%i\n", j);
  j &= ~(1 << 2); // Clear bit
  printf("%i\n", j);
  j ^= (1 << 3); // Toggles bit
  printf("%i\n", j);

  for (int i = 0; i < 8; i++) { // Toggle all bits
    j ^= (1 << i);
  }
  printf("%i\n", j);

  uint8_t bytes[] = {50, 2};
  sl_byte_conversion__from_network_to_uint32(bytes,
                                             2); // Converts array to integer

  uint32_t array[] = {1, 50, 2};
  get_highest(array, 2); // get highest value in array

  get_right_most_set_bit(0b01001100); // get right most set bit

  get_left_most_set_bit(0b01001100); // get left most set bit
  uint8_t x = 0b01001100; 
  swapBits(&x);

  Point point; // struct
  point.x = 5;
  point.y = 5;
  uint32_t multi = multiply(&point);
  printf("Multiply:%d", multi);
}
