#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/commands.h"
#include "../include/shell.h"

// Color Definitions
#define YELLOW "\033[1;33m"
#define CYAN  "\033[1;36m"
#define RESET "\033[0m"

#define BUFFER_SIZE 1024 //giving the max size to buffer
#define MAX_ARGS 64 //max args in a command
#define TOKEN_DELIMITERS " \t\r\n\a" //delimiters to spilt on

int main(){
    char input[BUFFER_SIZE];
    char *argv[MAX_ARGS];

    printf(YELLOW " ````Welcome to ByteShell!```` \n" RESET);
    printf(YELLOW "write 'help' to get started\n" RESET);

    // infinite Loop
    while (1) {
        printf(CYAN "ByteShell>> " RESET);
        fflush(stdout); // Ensure the input prints immediately

        // Read user input safely
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n"); // Handle EOF
        }
        int argc = 0;
        // Grab the primary command name
        char *token = strtok(input, TOKEN_DELIMITERS);

        // Continue chopping the string until no more tokens are found
        while (token != NULL && argc < MAX_ARGS - 1) {
            argv[argc] = token;
            argc++;
            token = strtok(NULL, TOKEN_DELIMITERS);
        }
        
        // Null-terminate the argument array
        argv[argc] = NULL; 

        // Hand the cleanly parsed arguments off to the execution router
        if (argc > 0) {
            identify_command(argc, argv);
        }
    }

    return 0;
}