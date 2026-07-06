#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/commands.h"
#include "../include/shell.h"

#define BUFFER_SIZE 1024 //giving the max size to buffer
#define MAX_ARGS 64 //max args in a command
#define TOKEN_DELIMITERS " \t\r\n\a" //delimiters to spilt on

int main(){
    char input[BUFFER_SIZE];
    char *argv[MAX_ARGS];

    printf(" ````Welcome to ByteShell!```` \n");
    printf("write 'help' to get started\n");

    // infinite Loop
    while (1) {
        printf("ByteShell>> ");
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