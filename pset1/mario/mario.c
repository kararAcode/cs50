#include <stdio.h>
#include <cs50.h>

int get_positive_int(string prompt);

int main(void)
{
    int height = get_positive_int("Height: "); // asks for height of pyramid
    for (int i = 1; i <= height; i++) // loop for making pyramid
    {
        for (int s = 0; s < height - i ; s++) // creates spaces before hash marks
        {
            printf(" ");
        }

        for (int j = 1; j <= i * 2; j++) // makes one row
        {
            printf("#");
            if (j == i)
            {
                printf("  ");
            }
        }

        printf("\n");
    }
}

int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}