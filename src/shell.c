#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/commands.h"
#include "../include/shell.h"

void identify_command(char *cmd){
    //remove the newline from fgets
    cmd[strcspn(cmd, "\n")] = '\0';
    //skip the empty lines
    if (strlen(cmd) == 0) {
        return; 
    }
    
    //identify the command
    if (strcmp(cmd, "help") == 0) {
        help();
    } else if (strcmp(cmd, "version") == 0) {
        version();
    } else if (strcmp(cmd, "exit") == 0) {
        exit_shell();
    } else {
        printf("ByteShell: command not found: %s\n", cmd);
    }
}