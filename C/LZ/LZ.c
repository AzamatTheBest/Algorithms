#include <stdio.h>

#define MAX_LEN 128

static char dictionary[MAX_LEN][MAX_LEN];

void lz_encode(char *string_to_encode, char *encoded_string);
int is_written(char *string);
int are_equal(char *string1, char *string2);
int get_index(char *string);
void write_to_dictionary(char *string);

int main(int argc, char **argv)
{
    char string_to_encode[MAX_LEN] = "aababbabbaaba";
    char encoded_string[MAX_LEN];
    lz_encode(string_to_encode, encoded_string);

    printf("String to encode: %s\n", string_to_encode);
    printf("Encoded string: %s\n", encoded_string);
    return 0;
}

void lz_encode(char *string_to_encode, char *encoded_string)
{
    char temp_code[MAX_LEN];
    int i, j, temp_pointer, encoded_pointer, index;

    for (i = temp_pointer = encoded_pointer = 0; string_to_encode[i] != '\0'; i++)
    {
	temp_code[temp_pointer++] = string_to_encode[i];
	temp_code[temp_pointer] = '\0';

	if (is_written(temp_code))
	{
	    index = get_index(temp_code);
	}
	else
	{
	    if (index < 0)
	    {
		for (j = 0; temp_code[j] != '\0'; j++)
		{
		    encoded_string[encoded_pointer++] = temp_code[j];
		}
	    }
	    else
	    {
		encoded_string[encoded_pointer++] = index + '0';
		encoded_string[encoded_pointer++] = temp_code[temp_pointer - 1];
	    }
	    temp_pointer = 0;
	    write_to_dictionary(temp_code);
	}
    }

    encoded_string[encoded_pointer] = '\0';
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

