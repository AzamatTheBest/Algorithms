#include <stdio.h>

double to_float(char *string)

int main(int argc, char **argv)
{
  char *number_as_string = "-325.34";
  char *another_number_as_string = "+326.42E-3";
  printf("%f %f\n", to_float(number_as_string), to_float(another_number_as_string));
  return 0;
}

double to_float(char *string)
{
    int i, sign, magnitude_sign;
    double value, power, magnitude;

    for (i = 0; string[i] == ' '; i++);

    sign = (string[i] == '-') ? -1 : 1;
    if (string[i] == '+' || string[i] == '-')
    {
	i++;
    }

    for (value = 0; string[i] >= '0' && string[i] <= '9'; i++)
    {
	value = value * 10 + (string[i] - '0');
    }

    if (string[i] == '.')
    {
	i++;
    }

    for (power = 1; string[i] >= '0' && string[i] <= '9'; i++)
    {
       	value = value * 10 + (string[i] - '0');
	power *= 10;
    }

    if (string[i] == 'e' || string[i] == 'E')
    {
	i++;
    }

    magnitude_sign = ('-' == string[i]) ? -1 : 1; 
    if (string[i] == '+' || string[i] == '-')
    {
	i++;
    }
    
    for (magnitude = 0; string[i] >= '0' && string[i] <= '9'; i++)
    {
	magnitude = magnitude * 10 + (string[i] - '0');
    }

    if (magnitude_sign == 1)
    {
	return pow(10, magnitude) * sign * (value / power);
    }
    else
    {
	return sign * (value / (power * pow(10, magnitude)));
    }
}
