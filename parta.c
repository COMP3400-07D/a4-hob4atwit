#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>

int main(int argc, const char* argv[]) {
    // Check if no arguments were provided (argc == 1 means only program name)
    if (argc == 1) {
        printf("ERROR: No arguments\n");
        return 1;  // Return error status
    }

    // Process each argument starting from index 1 (index 0 is program name)
    for (int i = 1; i < argc; i++) {
        // Get current argument and convert to uppercase while printing
        const char *current = argv[i];
        for (int j = 0; current[j] != '\0'; j++) {
            putchar(toupper(current[j]));
        }
        
        // Add comma after each argument except the last one
        if (i < argc - 1) {
            putchar(',');
        }
    }
    
    // Print newline at the end
    putchar('\n');
    return 0;  // Return success status
}
