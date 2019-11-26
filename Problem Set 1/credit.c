#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Returns the company based on card number
string getCompany(long card)
{
    long cc = card;
    int nDigits = floor(log10(labs(cc))) + 1;
    string output = "";
    
    while (cc > 100)
    {
        cc = cc / 10;
    }

    if ((nDigits == 13 || nDigits == 16) && (cc / 10 == 4))
    {
        output = "VISA";
    }
    else if (nDigits == 16 && (cc > 50 && cc < 56))
    {
        output = "MASTERCARD";
    }
    else if (nDigits == 15 && (cc == 34 || cc == 37))
    {
        output = "AMEX";
    }
    else
    {
        output = "INVALID";
    }
    
    return output;
}

// Checks validity of Luhn's Algorithm
string checkLuhn(long card)
{
    long cc = card;
    int sum = 0;
    int nDigits = floor(log10(labs(cc))) + 1;
    string output = "INVALID";
    
    for (int i = 1; i <= nDigits; i++)
    {
        int digit = cc % 10;
        if (i % 2 == 0)
        {      
            if (digit * 2 > 9)
            {
                sum += (digit * 2) - 9;
            }
            else
            {
                sum += digit * 2;
            }
       
        }
        else
        {
            sum += digit;
        }
        cc /= 10;
    }
    
    if (sum % 10 == 0)
    {    
        output = getCompany(card);
    }
    return output;
}

// Main program
int main(void)
{
    long card = 0;
    card = get_long("Number: ");
    
    string output = checkLuhn(card);
    printf("%s\n", output);
}