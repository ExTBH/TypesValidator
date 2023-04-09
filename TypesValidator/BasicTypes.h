//
//  BasicTypes.h
//  TypesValidator
//
//  Created by Natheer on 09/04/2023.
//

#ifndef BasicTypes_h
#define BasicTypes_h

#include <stdio.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

bool isBoolean(const uint8_t *bytes, size_t size);
bool isInteger(const uintptr_t address);
bool isFloat(const uintptr_t address);
bool isDouble(const uintptr_t address);
bool isObject(const uintptr_t address);

#ifdef __cplusplus
}
#endif

#endif /* BasicTypes_h */
