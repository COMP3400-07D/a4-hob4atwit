#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

int main(int argc, const char* argv[]) {
    // Adjust argc to skip program name
    argc--;  // Now argc is the number of actual arguments
    argv++;  // Move argv to point to first actual argument
    
    // Handle cases based on number of arguments
    if (argc == 1) {
        // One argument: print it
        printf("%s\n", argv[0]);
    }
    else if (argc == 2) {
        // Two arguments: print both with space between
        printf("%s %s\n", argv[0], argv[1]);
    }
    else if (argc >= 3) {
        // Three or more arguments: print middle element(s)
        if (argc % 2 == 0) {
            // Even number of arguments: print middle two
            int mid = argc / 2 - 1;  // Index of first middle element
            printf("%s %s\n", argv[mid], argv[mid + 1]);
        } else {
            // Odd number of arguments: print middle one
            printf("%s\n", argv[argc / 2]);
        }
    }

    return 0;  // Return success
}
