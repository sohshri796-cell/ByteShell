#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/commands.h"
#include "../include/shell.h"

//function pointer
typedef void (*cmd_func)(int argc, char **argv);

// Define the structure for each command table entry
typedef struct {
    const char *inp;    // What the user types (e.g., "help")
    cmd_func function; // The C function to run
} command_entry;

//create a command table
static const command_entry command_table[] = {
    {"help",    help},
    {"version", version},
    {"exit",    exit_shell}
};

// Calculate the number of elements in the table at compile time
#define NUM_COMMANDS (sizeof(command_table) / sizeof(command_table[0]))

void identify_command(int argc, char **argv){
    if (argc == 0 || argv[0] == NULL) {
        return;
    }

    for (size_t i = 0; i < NUM_COMMANDS; i++) {
        if (strcmp(argv[0], command_table[i].inp) == 0) {
            command_table[i].function(argc, argv); // Pass the whole argument context!
            return;
        }
    }
        
    printf("ByteShell: command not found: %s\n", argv[0]);
    return;
}