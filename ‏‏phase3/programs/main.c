#include <stdio.h>
#include "global.h"

FILE* output, * input, *err;

int main() {
    fopen_s(&input, "input.txt", "r");
    if (input == NULL) {
        printf("the file does not exist\n");
        return 1; 
    }

    fopen_s(&err, "err.txt", "w");

    fopen_s(&output, "output.txt", "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        return 1; 
    }

    init();
    parse();

    fclose(input);
    fclose(output);
    fclose(err);


    return 0;
}