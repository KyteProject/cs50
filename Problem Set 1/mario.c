#include <cs50.h>
#include <stdio.h>

void repeatChar(string ch, int num)
{
    for (int i = 0; i != num; i++)
    {
        printf("%s", ch);
    }
}

void makeMountain(int air, int blocks)
{
    string space = " ";
    string block = "#";
    
    repeatChar(" ", air);
    repeatChar("#", blocks);
    repeatChar(" ", 2);
    repeatChar("#", blocks);
    printf("\n");
}

int main(void)
{
    int height = 0;
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }
    
    for (int r = 1; r != height + 1; r++)
    {
        int spaces = (height - r);
        makeMountain(spaces, r);
    }
}