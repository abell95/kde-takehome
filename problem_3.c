// Array Bitpacking

// Write a function in C that accepts a contiguous array of 12-bit integers. For
// example, if the array represents the sequence of integers [1000, 1001, 1002,
// 1003], the input array will be represented in memory as the bytes

// [0x3e, 0x83, 0xe9, 0x3e, 0xa3, 0xeb]

// The function should return a larger array which contains the same integers each
// stored at a 16-bit offset. In this case, the result would be represented in memory
// as the bytes:

// [0x03, 0xe8, 0x03, 0xe9, 0x03, 0xea, 0x03, 0xeb]

// You should use stdint.h for the integer types.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef struct twelvebit {
    int int12 : 12;
} int12_t;

int16_t * array_bitpacker(int12_t array[], int length) {
    int16_t * arr = malloc(sizeof(int16_t) * length);

    for (int i = 0; i < length * 1.5; i++) {
        arr[i] = array[i].int12;
    }

    return arr;
}

int main() {
    int12_t * testArray = malloc(sizeof(int12_t) * 4);

    testArray[0].int12 = 1000;
    testArray[1].int12 = 1001;
    testArray[2].int12 = 1002;
    testArray[3].int12 = 1003;

    assert(sizeof(testArray) == 6);

    int16_t * arr = array_bitpacker(testArray, 4);

    assert(arr[0] == 1000);
    assert(arr[1] == 1001);
    assert(arr[2] == 1002);
    assert(arr[3] == 1003);

    assert(sizeof(arr) == 8); // 16 bit * 4 elements

    free(testArray);
    free(arr);

    return 0;
}
