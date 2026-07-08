# ByteShell
A embedded shell that can be used to run various functions using UART
This shell is designed to monitor and debug various things for a STM32 microcontroller board

Though currently it does not support uart, it is a normal shell

Folder structure of this project:
```
ByteShell/
├── include/                 # Header files
│   ├── commands.h
│   └── shell.h
├── src/                     # Source files
│   ├── commands.c
│   ├── main.c
│   └── shell.c
├── .gitignore               # Git ignore rules
├── LICENSE                  # Project license
├── Makefile                 # Build instructions
├── README.md                # Project documentation
└── changelog.md             # Version history
```

To run this project, type this command in the cloned folder:
` make `

then run it simply by:
` ./ByteShell `