#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int only_digits(const char text[]);
char rotate(char c, int key);

int main(int argc, char *argv[])
{
    // Validate the command-line argument.
    // Convert the key to an integer.
    // Read the plaintext.
    // Rotate and print every character.
    if (argc != 2 || !only_digits(argv[1])) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    char plaintext[1000];
    printf("plaintext: ");
    fgets(plaintext, sizeof plaintext, stdin);
    printf("cyphertext:");
    for (int i = 0; plaintext[i] != '\0'; i++ ){
        printf("%c", rotate(plaintext[i], atoi(argv[1])));
        }

}

int only_digits(const char text[])
{
    // Return 1 if text is not empty and contains only digits otherwise 0
    for( int i = 0; text[i] != '\0'; i++){
        unsigned char j = text[i];
        if (!(isdigit(j))){
            printf("0");
            return 0;
        }
    }
    return 1;
}

char rotate(char c, int key) {

    // Rotate letters and return non-letter characters unchanged.
    if (isupper(c)) {
        return 'A' + (c - 'A' + key) % 26;
    }
    else if (islower(c)) {
        return 'a' + (c - 'a' + key) % 26;
    }
    return c;        
}