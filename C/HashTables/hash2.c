#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELETED (char *) 0xFFFFFFFFF

int hash(char *string);
void init_hash_table(void);
void free_hash_table(void);
void insert_member(char *string);
void print_table(void);

static char **hash_table;
static unsigned int table_size = 8;

int main(int argc, char **argv)
{
    init_hash_table();
    insert_member("Azamat");
    insert_member("John");
    insert_member("Alexander");
    insert_member("Mpho");
    insert_member("Tamara");
    insert_member("Sasinka");
    insert_member("Ladiko");
    insert_member("Sara");
    insert_member("Lara");
    insert_member("NikoMiko");
    insert_member("LALALEND");
    insert_member("Shikaka");

    print_table();
    
    delete_member("Mpho");
    delete_member("Sasinka");
    delete_member("Shikaka");
    delete_member("Ladiko");
    
    print_table();
    
    free(hash_table);
    return 0;    
}

int hash(char *string)
{
    int hash_index, i;
    unsigned int hash_value;
    unsigned int table_size = sizeof(hash_table);
    
    for (i = hash_value = 0; string[i]; i++)
    {
	hash_value = (hash_value + string[i]) * string[i];	
    }

    hash_index = hash_value % table_size;

    return hash_index;
}

void insert_member(char *string)
{
    unsigned int hash_index, i;

    hash_index = hash(string);
    
    while (hash_table[hash_index] != NULL && strcmp(hash_table[hash_index], "") != 0)
    {
	hash_index = (hash_index + 1) % table_size;
	if (hash_index + 1 == table_size)
	{
	    break;
	}
    }

    if (hash_index + 1 == table_size)
    {
	table_size <<= 1;
	hash_table = realloc(hash_table, table_size * sizeof(char *));
	for (i = table_size/2; i < table_size; i++)
	{
	    hash_table[i] = NULL;
	}
	hash_table[table_size/2] = string;
    }
    else
    {
	hash_table[hash_index] = string;
    }
}

void init_hash_table(void)
{
    hash_table = malloc(table_size * sizeof(char *));

    int i;
    for (i = 0; i < table_size; i++)
    {
	hash_table[i] = NULL;
    }
}

void print_table(void)
{
    int i;
    for (i = 0; i < table_size; i++)
    {
	
	printf("%d.---", i);

	if (hash_table[i] == DELETED)
	{
	    printf("(deleted)");
	}
	else if (hash_table[i] != NULL)
	{ 
	    printf("%s", hash_table[i]);
	}

	printf("\n");
    }
}

void delete_member(char *string)
{
    unsigned int hash_index;

    hash_index = hash(string);
    
    while (hash_table[hash_index] != NULL)
    {
	while (hash_table[hash_index] == DELETED)
	{
	    hash_index = (hash_index + 1) % table_size;
	}
	
	if (strcmp(hash_table[hash_index], string) == 0)
	{
	    hash_table[hash_index] = DELETED;
	    break;	    
	}
	
	hash_index = (hash_index + 1) % table_size;
	
	while (hash_table[hash_index] == DELETED)
	{
	    hash_index = (hash_index + 1) % table_size;
	}
    }    
    printf("\n");
}

