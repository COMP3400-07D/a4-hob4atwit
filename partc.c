#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

int main(int argc, const char* argv[]) {
    // Check if we have exactly 2 arguments (plus program name)
    if (argc != 3) {
        return 1;  // Return error status for incorrect usage
    }

    const char* word = argv[1];    // Word to search for
    const char* filename = argv[2]; // File to search in
    
    // Try to open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("ERROR: %s doesn't exist\n", filename);
        return 2;  // Return error status for file not found
    }
    
    // Buffer for reading lines from file
    char line[1024];
    bool found = false;
    
    // Read file line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove newline if present
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        
        // Check if word appears in this line
        if (strstr(line, word) != NULL) {
            found = true;
            break;
        }
    }
    
    // Close the file
    fclose(file);
    
    // Print result
    if (found) {
        printf("FOUND: %s\n", word);
    } else {
        printf("NOT FOUND: %s\n", word);
    }
    
    return 0;  // Return success status
}
