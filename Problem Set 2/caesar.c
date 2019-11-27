#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
    
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            exit(1);
        }
    }
    
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    int len = strlen(plaintext);
    printf("ciphertext: ");

    for (int j = 0; j < len; j++)
    {
        char ch = plaintext[j];
        
        if (ch >= 'A' && ch <= 'Z')
        {
            printf("%c", ((ch - 'A' + key) % 26) + 'A');
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            printf("%c", ((ch - 'a' + key) % 26) + 'a');
        }
        else
        {
            printf("%c", ch);
        }  
    }
    
    printf("\n");
    exit(0);
}
