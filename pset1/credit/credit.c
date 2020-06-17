#include <stdio.h>
#include <math.h> //https://www.tutorialspoint.com/c_standard_library/math_h.htm
#include <cs50.h>

int length(long n);
double index(long n, long p);
int sum(long n);
bool checksum(long n);

int main(void)
{
    long number = get_long("Number: "); //user input
    // runs if card satisfies checksum
    if (checksum(number))
    {
        int first_digit = index(number, pow(10, length(number) - 1)); // first digit of num
        int sec_digit = index(number, pow(10, length(number) - 2)); // second digit of num
        // booleans for identification of card
        bool is_amex_len = length(number) == 15;
        bool start_w_34 = (first_digit == 3) && (sec_digit == 4);
        bool start_w_37 = (first_digit == 3) && (sec_digit == 7);
        bool is_amex = is_amex_len && (start_w_34 || start_w_37);

        bool is_master_len = length(number) == 16;
        bool start_w_51 = (first_digit == 5) && (sec_digit == 1);
        bool start_w_52 = (first_digit == 5) && (sec_digit == 2);
        bool start_w_53 = (first_digit == 5) && (sec_digit == 3);
        bool start_w_54 = (first_digit == 5) && (sec_digit == 4);
        bool start_w_55 = (first_digit == 5) && (sec_digit == 5);
        bool is_master = is_master_len && (start_w_51 || start_w_52 || start_w_53 || start_w_54 || start_w_55);

        bool is_visa_len = (length(number) == 13) || (length(number) == 16);
        bool start_w_4 = (first_digit == 4);
        bool is_visa = is_visa_len && start_w_4;

        // prints card type
        if (is_amex)
        {
            printf("AMEX\n");
        }

        else if (is_master)
        {
            printf("MASTERCARD\n");
        }

        else if (is_visa)
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}

// returns length of num
int length(long n)
{
    return floor(log10(n) + 1);
}

double index(long n, long p)
{
    long x = n / p;
    return floor(x % 10);
}
// returns sum of digits of num
int sum(long n)
{
    int result = 0;
    for (int i = 1; i <= pow(10, length(n) - 1); i *= 10)
    {
        result += index(n, i);
    }
    return result;
}
// checksum func
bool checksum(long n)
{
    int result = 0;
    for (double i = 1; i <= pow(10, length(n) - 1); i *= 10)
    {
        double digit = index(n, i);
        // logic for checksum
        if (length(i) % 2 != 0)
        {
            result += digit;
        }

        else
        {
            if (length(digit * 2) > 1)
            {
                result += sum(digit * 2);
            }

            else
            {
                result += digit * 2;
            }
        }
    }

    return result % 10 == 0;
}