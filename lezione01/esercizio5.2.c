#include <stdio.h>
#include <string.h>
#include <ctype.h>

void upperExtract(char *str, char *out) {
    char *token = strtok(str, " \n\0");
    while (token != NULL) {
        if (isupper(token[0])) {
            strcpy(out, token);
            out += strlen(token);
        }
        token = strtok(NULL, " !\n\0");
    };
}

int main() {
    char str[] = "Hello World this is a nice Day!";
    char buf[31];
    
    upperExtract(str, buf);
    printf("%s\n", buf);

    return 0;
}