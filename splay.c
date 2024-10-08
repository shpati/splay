// compile with: tcc splay.c -lwinmm

#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>

int main(int argc, char **argv) {
    char command[MAX_PATH + 64];

    // If no command line argument is given then show the usage instructions
    if (argc < 2) {
        printf("\nShpati Koleka 2022, MIT license\nUsage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Build the command string to open the audio file
    snprintf(command, sizeof(command), "open \"%s\" type mpegvideo alias Audio", argv[1]);

    // Open the audio file
    if (mciSendString(command, NULL, 0, NULL) != 0) {
        printf("Failed to open: %s\n", argv[1]);
        return 1;
    }

    // Play and close the audio file
    mciSendString("play Audio Wait", NULL, 0, 0);
    mciSendString("close Audio", NULL, 0, 0);

    return 0;
}
