#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../include/commands.h"

// Color Definitions
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
#define PURPLE "\033[1;35m"

#define MAX_STRING_SIZE 1024
#define MAX_VARS 100
#define MAX_VAR_NAME 64
#define MAX_VAR_VALUE 256

//Structure to hold a single variable
typedef struct {
    char name[MAX_VAR_NAME];
    char value[MAX_VAR_VALUE];
} shell_var_t;

// Static variable storage
static shell_var_t variable_table[MAX_VARS];
static int variable_count = 0;

// help command
void help(int argc, char **argv)
{
    if (argc > 1)
    {
        printf(RED "ByteShell error: 'help' takes no arguments. Did you try to run multiple commands?\n" RESET);
        return;
    }
    printf(GREEN "---->HELP<---- \n");
    printf("Functions: \n" RESET);
    printf(PURPLE "help --> displays the available commands\n");
    printf("version --> displays the current version of ByteShell\n");
    printf("time --> displays the current time\n");
    printf("repeat --> repeats what you type and can be multiplied the number of times too\n");
    printf("set --> used to create variables\n");
    printf("get --> returns values for variables if defined\n");
    printf("clear --> clears the previous commands\n");
    printf("exit --> exits the shell\n" RESET);
}

// version command
void version(int argc, char **argv)
{
    if (argc > 1)
    {
        printf(RED "ByteShell error: 'version' takes no arguments.\n" RESET);
        return;
    }
    printf(RED "Version:\033[1;33m ByteShell v0.4\n" RESET);
}

// clear command
void clear(int argc, char **argv)
{
    if (argc > 1)
    {
        printf(RED "ByteShell error: 'clear ' takes no arguments.\n" RESET);
        return;
    }
    // ANSI sequence: \033[H moves cursor to top-left, \033[2J clears the screen
    printf("\033[H\033[2J");
    fflush(stdout);
}

// time command
void time_shell(int argc, char **argv)
{
    if (argc > 1)
    {
        printf(RED "ByteShell error: 'time' takes no arguments.\n" RESET);
        return;
    }

    time_t raw_time;
    struct tm *time_info;
    char time_buffer[80];

    time(&raw_time);
    time_info = localtime(&raw_time);

    // Format time: Day Month Date Hour:Minute:Second Year
    strftime(time_buffer, sizeof(time_buffer), "%a %b %d %H:%M:%S %Y", time_info);
    printf("Current local time: \033[1;33m %s\n" RESET, time_buffer);
}

// repeat command
void repeat(int argc, char **argv)
{
    char sentence [MAX_STRING_SIZE] = "";
    if (argc == 1)
        return;
    int i = 1;
    for (; i < argc; i++)
    {
        if (strcmp(argv[i], "*") == 0)
        {
            break; // Found the multiplier marker, stop building the sentence
        }
        
        // Add a space between words (but not before the very first word)
        if (i > 1 && strlen(sentence) > 0)
        {
            strcat(sentence, " ");
        }
        
        // Check for buffer overflow before adding the next argument
        if (strlen(sentence) + strlen(argv[i]) + 1 < MAX_STRING_SIZE)
        {
            strcat(sentence, argv[i]);
        }
    }
    long int rep = 1;
    if (i < argc && strcmp(argv[i], "*") == 0)
    {
        if (i + 1 < argc) // Make sure the number actually exists
        {
            rep = strtol(argv[i + 1], NULL, 10);
        }
    }
    // Print the sentence the specified number of times
    for (int r = 0; r < rep; r++)
    {
        printf(PURPLE "%s\n", sentence); // Safe printf usage
    }
    
    printf(RESET);
}

//set command
void set(int argc, char **argv){
    if (argc != 3) {
        printf(RED "ByteShell error: 'set' requires exactly 2 arguments. \nUsage: set [name] [value]\n" RESET);
        return;
    }
    char *name = argv[1];
    char *value = argv[2];

    // Check if the variable name or value is too long
    if (strlen(name) >= MAX_VAR_NAME || strlen(value) >= MAX_VAR_VALUE) {
        printf(RED "ByteShell error: Variable name or value exceeds allowed limits.\n" RESET);
        return;
    }
    // Check if the variable already exists to update it
    for (int i = 0; i < variable_count; i++) {
        if (strcmp(variable_table[i].name, name) == 0) {
            strncpy(variable_table[i].value, value, MAX_VAR_VALUE);
            return;
        }
    }

    // Otherwise, create a new variable if memory isn't full
    if (variable_count >= MAX_VARS) {
        printf(RED "ByteShell error: Shell memory full. Cannot set more variables.\n" RESET);
        return;
    }

    strncpy(variable_table[variable_count].name, name, MAX_VAR_NAME);
    strncpy(variable_table[variable_count].value, value, MAX_VAR_VALUE);
    variable_count++;
}

//get command
void get(int argc, char **argv){
    if (argc != 2) {
        printf(RED "ByteShell error: 'get' requires exactly 1 argument. Usage: get [name]\n" RESET);
        return;
    }
    char *name = argv[1];

    // Scan our storage array for a match
    for (int i = 0; i < variable_count; i++) {
        if (strcmp(variable_table[i].name, name) == 0) {
            printf(GREEN "%s\n" RESET, variable_table[i].value);
            return;
        }
    }

    // If we finished the loop without returning, the variable wasn't found
    printf(RED "ByteShell error: variable '%s' is not defined.\n" RESET, name);
}

// exit command
void exit_shell(int argc, char **argv)
{
    if (argc > 1)
    {
        printf(RED "ByteShell error: 'version' takes no arguments.\n" RESET);
        return;
    }
    printf("Exiting....\n");
    exit(0);
}
