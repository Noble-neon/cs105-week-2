#include <ctype.h>
#include <stdio.h>

int compute_score(const char word[]);

int main(void)
{
    char word1[100];
    char word2[100];

    scanf("%s", word1);
    printf("second word:\n");
    scanf("%s", word2);

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 == score2) {
        printf("\nTie!");
    } else if (score1 > score2) {
        printf("\nPlayer 1 wins!");
    } else {
        printf("\nPlayer 2 wins!");
    }
}

int compute_score(const char word[])
{   int score = 0;
    int scores_for_letters[] = {1, 3, 3,	2,	1,	4,	2,	4,	1,	8,	5,	1,
                                	3,	1,	1,	3,	10,	1, 1,	1,	1,	4,	4,	8,	4,	10};
    for(int i = 0; word[i] != '\0'; i++){
        int s = tolower(word[i])  - 'a';  // this is a temporary variable which gives as the number of the character in the alphabet
        if (s < 0 || s >= 26) {  // this condition checks whether the dedicated character is in the alpahabet or not
            continue;          /* skip any non alphabetic characters like special symbols and spaces*/
        }
        score += scores_for_letters[s];
    }   
        printf("%d    ", score);
        return score;
}