#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int only_digits(const char text[]);
char rotate(char c, int key);

int main(int argc, char *argv[])
{
    char a = only_digits("2321312a");
    printf("%c", a);
    // Validate the command-line argument.

    // Convert the key to an integer.

    // Read the plaintext.

    // Rotate and print every character.
}

int only_digits(const char text[])
{
    // Return 1 if text is non-empty and contains only digits; otherwise 0
    for( int i = 0; i != '\0'; i++){
        unsigned char j = text[i];
        if (!(isdigit(j))){
            printf("0");
            return 0;
        }
    }
    
    return 1;
}

char rotate(char c, int key)
{
    // Rotate letters and return non-letter characters unchanged.
}