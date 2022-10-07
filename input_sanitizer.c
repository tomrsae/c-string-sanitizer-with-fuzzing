#include <stdio.h>
#include "input_sanitizer.h"

int main(int argc, char** argv) {
    char* str = ">Some& sc<ary in>put";

    printf("String before sanitization: %s\n", str);

    str = sanitize(str);

    printf("String after sanitization: %s\n", str);

    free(str);

    return 0;
}

