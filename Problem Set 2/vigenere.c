#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        exit(1);
    }
    
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./vigenere keyword\n");
            exit(1);
        }
    }
    
    string key = argv[1];
    string plaintext = get_string("plaintext: ");
    int len = strlen(plaintext);
    printf("ciphertext: ");
    int x = 0;

    for (int j = 0; j < len; j++)
    {
        char ch = plaintext[j];
        
        if (x > strlen(key) - 1)
        {
            x = x % strlen(key);
        }

        int k = shift(argv[1][x]);

        if (ch >= 'A' && ch <= 'Z')
        {
            printf("%c", ((ch - 'A' + k) % 26) + 'A');                   
            x++;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            printf("%c", ((ch - 'a' + k) % 26) + 'a');
            x++;
        }
        else
        {
            printf("%c", ch);
        }
    }
    
    printf("\n");
    exit(0);
}

int shift(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return (ch - 'A') % 26;
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        return (ch - 'a') % 26;
    }
    else
    {
        return 0;
    }
}
