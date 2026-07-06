#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/commands.h"    

//help command
void help(int argc, char **argv){
    (void)argc; (void)argv; // Suppress unused parameter warnings
    printf("---->HELP<---- \n");
    printf("Functions: \n");
    printf("help --> displays the available commands\n");
    printf("version --> displays the current version of ByteShell\n");
    printf("exit --> exits the shell\n");
}

//version command
void version(int argc, char **argv){
    (void)argc; (void)argv; // Suppress unused parameter warnings
    printf("Version: ByteShell 0.1\n");
}

//exit command
void exit_shell(int argc, char **argv){
    (void)argc; (void)argv; // Suppress unused parameter warnings  
    printf("Exiting....\n");
    exit(0);
}


