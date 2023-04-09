//
//  BasicTypes.c
//  TypesValidator
//
//  Created by Natheer on 09/04/2023.
//

#include "BasicTypes.h"
#include <string.h>
#include <stdlib.h>

bool isBoolean(const uint8_t *bytes, size_t size) {
    if (size != 1) {
        return false;
    }
    return (int8_t)bytes[0] >= 0;
}
// idk what or how this works, sourcelocation made it
bool isInteger(const uintptr_t address) {
    // Prepare buffer
    const size_t size = sizeof(int64_t);
    uint8_t *buffer = (uint8_t*)malloc(size);
    memcpy(buffer, (void*)address, size);
    
    // Check the endianness of the bytes
    int64_t value = 0;
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    for (size_t i = 0; i < size; i++) {
        value |= (int64_t) buffer[i] << (8 * i);
    }
    #elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    for (size_t i = 0; i < size; i++) {
        value |= (int64_t) buffer[size - i - 1] << (8 * i);
    }
    #endif
    // verify the resulting value matches the original
    for (size_t i = 0; i< size; i++) {
        if (buffer[i] != ((value >> (8 * i)) & 0xFF)) {
            return false;
        }
    }
    return true;
}
bool isFloat(uintptr_t address) {
    return true;
}
bool isDouble(uintptr_t address) {
    return true;
}
bool isObject(uintptr_t address) {
    return true;
}
