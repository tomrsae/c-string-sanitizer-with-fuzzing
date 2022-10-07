#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../input_sanitizer.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {

    char* buffer = malloc(sizeof(char) * size + 1);
    memcpy(buffer, data, size);
    buffer[size] = '\0';

    char* sanitized_string = sanitize(buffer, size + 1);

    free(buffer);
    free(sanitized_string);
    
    return 0;
}
