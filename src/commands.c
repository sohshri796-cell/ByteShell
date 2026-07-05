#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/commands.h"

//help command
void help(){
    printf("---->HELP<---- \n");
    printf("Functions: \n");
    printf("help --> displays the available commands\n");
    printf("version --> displays the current version of ByteShell\n");
    printf("exit --> exits the shell\n");
}

//version command
void version(){
    printf("Version: ByteShell 0.2\n");
}

//exit command
void exit_shell(){
    printf("Exiting....\n");
    exit(0);
}
