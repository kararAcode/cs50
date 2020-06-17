#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Gets user input
    string name = get_string("What is your name?\n");
    // prints hello, name(userinput)
    printf("hello, %s\n", name);
}