#include <ctype.h>
#include <stdio.h>
#include <string.h>

int valid_key(const char key[]);
char substitute(char c, const char key[]);

int main(int argc, char *argv[])
{
    // Check the number of arguments and validate the key.z
    if (argc != 2) {
    printf("Usage: ./substitute key\n");
    return 1;
    }

    //just to check
    if (valid_key(argv[1])) {
        printf("key is valid\n");
    } else {
        printf("key is invalid\n");
        return 1;
    }

    // Read the plaintext.
    printf("plaintext:");
    char text[256];
    fgets(text, sizeof(text), stdin);

    // Substitute and print each character.
    printf("cyphertext:");
    for ( int i =0; text[i] != '\0'; i++){
        printf("%c", substitute(text[i], argv[1]));
    }



}

int valid_key(const char key[])
{   int seen[26] = {0};

    // Check the key's length, characters, and uniqueness.

    if (strlen(key) != 26 ) {
        return 0;
    }
    for (int i = 0; key[i] != '\0'; i++){

        if ( !isalpha(key[i]) ){
            return 0;
        }

        int indx_seen = toupper(key[i]) - 'A'; // we get a num from 0 to 25

        if (seen[indx_seen] != 1) {
            seen[indx_seen] = 1; 
    } else {
            return 0;
        }
    }
    return 1;
}

char substitute(char c, const char key[])
{
    // Substitute letters, preserve case, and return other characters as-is.
    if (isalpha(c)) {
        if( isupper(c)) {
            int indx = c - 'A';
            return key[indx];
        }
        if (islower(c)) {
            int indx = c - 'a';
            return key[indx];
        }
    } else {
        return c;
    }

}