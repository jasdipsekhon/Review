#pragma once
#include <stdio.h>
#include<stdint.h>

#define MACRO 235
#define PI 3.14
#define AREA(x) x * x * PI 
#define MIN(x, y) (( x < y) ? x : y) // function like MACRO
#define DEBUG_TEST_1 
// #define DEBUG_TEST_2 

typedef enum {
    RED,
    GREEN,
    BLUE,
} enum_e;

typedef struct {
    uint32_t red_time_in_sec;
    uint32_t green_time_in_sec;
    uint32_t yellow_time_in_sec;
} time_s;

typedef struct {
    enum_e color;
    time_s timings;
    uint32_t time_counter;
} struct_s;

uint32_t sl_byte_conversion__from_network_to_uint32(const uint8_t *bytes, const size_t length_of_bytes);