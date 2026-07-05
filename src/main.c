#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/commands.h"
#include "../include/shell.h"

#define BUFFER_SIZE 1024 //giving the max size to buffer

int main(){
    char input[BUFFER_SIZE];
    printf(" ````Welcome to ByteShell!```` \n");
    printf("write 'help' to get started\n");

    // infinite Loop
    while (1) {
        printf("ByteShell>> ");
        fflush(stdout); // Ensure the input prints immediately

        // Read user input safely
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n"); // Handle EOF (like Ctrl+D) gracefully
            break;
        }

        // Evaluate and Execute
        identify_command(input);
    }
    return 0;
}