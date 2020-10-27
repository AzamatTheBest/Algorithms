#include <stdio.h>

int to_integer(char *string);

int main(int argc, char **argv)
{
  char* first_number = "123";
  char* second_number = "-1656";
  
  printf("%d %d\n", to_integer(first_nunmber), to_integer(second_number));
  return 0;
}

int to_integer(char *string)
{
    int number, i, sign;

    for (i = 0; string[i] == ' '; i++);

    sign = (string[i] == '-') ? -1 : 1;
    if (string[i] == '+' || string[i] == '-')
    {
	i++;
    }

    for (number = 0; string[i] >= '0' && string[i] <= '9'; i++)
    {
	number = number * 10 + (string[i] - '0');
    }
    return sign * number;
}
