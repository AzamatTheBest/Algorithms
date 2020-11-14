#include <stdio.h>

#define MAX_LEN 128

static char dictionary[MAX_LEN][MAX_LEN];

void lz_encode(char *string_to_encode, char *encoded_string);
void lz_decode(char *encoded_string, char *decoded_string);
int is_written(char *string);
int are_equal(char *string1, char *string2);
int get_index(char *string);
int strlen(char *string);
void write_to_dictionary(char *string);
void itoa(int number, char *string);
void reverse(char *string);
int to_integer(char *string);
int is_encoded(char *string);

int main(int argc, char **argv)
{
    char string_to_encode[MAX_LEN] = "I am blue, da ba de da bu da";
    char encoded_string[MAX_LEN];
    char decoded_string[MAX_LEN];

    lz_encode(string_to_encode, encoded_string);

    printf("String to encode: %s\n", string_to_encode);
    printf("Encoded string: %s\n", encoded_string);

    lz_decode(encoded_string, decoded_string);
    
    printf("Decoded string: %s\n", decoded_string);
/*
    lz_decode(encoded_string, decoded_string);
    aababbabbaaba
Vepho Vandenberg mighty lighty fighty
    printf("Decoded string: %s\n", decoded_string);
*/  
    return 0;
}

void lz_encode(char *string_to_encode, char *encoded_string)
{
    char temp_code[MAX_LEN], temp_string[MAX_LEN], index_as_string[MAX_LEN];
    int i, j, temp_pointer, encoded_pointer, index;
    
    index = -1;
    for (i = encoded_pointer = temp_pointer = 0; string_to_encode[i] != '\0'; i++)
    {
	temp_code[temp_pointer++] = string_to_encode[i];
	temp_code[temp_pointer] = '\0';

        if (!is_written(temp_code))
	{
	    for (j = 0; temp_code[j + 1] != '\0'; j++)
	    {
		temp_string[j] = temp_code[j];
	    }
	    
	    temp_string[j] = '\0';
	    if ((index = get_index(temp_string)) != -1)
	    {
		itoa(index, index_as_string);

		for (j = 0; index_as_string[j] != '\0'; j++)
		{
		    encoded_string[encoded_pointer++] = index_as_string[j];
		}
	    }
	    encoded_string[encoded_pointer++] = temp_code[temp_pointer - 1];
	    write_to_dictionary(temp_code);
	    temp_pointer = 0;
	}
    }

    encoded_string[encoded_pointer] = '\0';
}

void lz_decode(char *encoded_string, char *decoded_string)
{
    int i, j, temp_pointer, decoded_pointer, index;
    char temp_code[MAX_LEN], temp_string[MAX_LEN];

    for (i = temp_pointer = decoded_pointer = 0; encoded_string[i] != '\0'; i++)
    {
	if (is_symbol(encoded_string[i]))
	{
	    if (temp_pointer != 0)
	    {
		index = to_integer(temp_code);
		for (j = 0; dictionary[index][j] != '\0'; j++)
		{
		    decoded_string[decoded_pointer++] = dictionary[index][j];
		}
	    }
	    decoded_string[decoded_pointer++] = encoded_string[i];
	    temp_pointer = 0;
	}
	else
	{
	    temp_code[temp_pointer++] = encoded_string[i];
	    temp_code[temp_pointer] = '\0';
	}
    }

    decoded_string[decoded_pointer] = '\0';
}

int is_encoded(char *string)
{
    int i;

    for (i = 0; string[i] != '\0'; i++)
    {
	if (string[i] > '9' || string[i] < '0')
	{
	    return 0;
	}
    }

    return 1;
}



int is_written(char *string)
{
    int i;

    for (i = 0; dictionary[i][0]; i++)
    {
	if (are_equal(dictionary[i], string))
	{
	    return 1;
	}
    }

    return 0;
}

int is_symbol(char character)
{
    return (!(character >= '0' && character <= '9')) ? 1 : 0;
}

int are_equal(char *string1, char *string2)
{
    int i;
    for (i = 0; string1[i] != '\0' || string2[i] != '\0'; i++)
    {
	if (string1[i] != string2[i])
	{
	    return 0;
	}
    }

    return 1;
}

int get_index(char *string)
{
    int i;

    for (i = 0; dictionary[i][0]; i++)
    {
	if (are_equal(dictionary[i], string))
	{
	    return i;
	}
    }

    return -1;
}

void write_to_dictionary(char *string)
{
    int i, j;

    for (i = 0; dictionary[i][0]; i++);

    for (j = 0; string[j] != '\0'; j++)
    {
	dictionary[i][j] = string[j];
    }

    dictionary[i][j] = '\0';
}

void itoa(int number, char *string)
{
    int i = 0;

    do
    {
	string[i++] = number % 10 + '0';
	number /= 10;
    }
    while (number > 0);

    string[i] = '\0';
    reverse(string);
}

void reverse(char *string)
{
    int i;
    int len = strlen(string);
    char temp;
    
    for (i = 0; i < len / 2; i++)
    {
	temp = string[len - 1 - i];
	string[len - 1 - i] = string[i];
	string[i] = temp;
    }
}

int strlen(char *string)
{
    int i;

    for (i = 0; string[i] != '\0'; i++);

    return i;
}

int to_integer(char *string)
{
    int i, number;

    for (i = number = 0; string[i] != '\0'; i++)
    {
	number = number * 10 + (string[i] - '0');
    }

    return number;
}


