#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main(int argc, char **argv) {

    char *username = getlogin();

    char *command = "/usr/bin/import -window root /home/anthony/Documents/C/i3lock/slim_test.png";

    char *envp[] = {"PATH=/usr/bin:/usr/local/bin", NULL};

    char *arguments[] = {
        "/usr/bin/env", "DISPLAY=:0.0", "/usr/bin/sudo", "-i", "su", username, "-c", command, (char *)NULL,
    };
    
    if(fork() == 0) {
        execvpe(arguments[0], arguments, envp);
    }

}
