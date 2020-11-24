#include <stdio.h>
#include <string.h> 

#define MAX_STRING 128
#define TABLE_SIZE 20

typedef struct person
{
    char *name;
    int age;
    struct person *next;
} person_t;

static person_t *hash_table[TABLE_SIZE];

void hash_table_init(void);
unsigned int hash(person_t *person);
void print_table(void);
void insert_member(person_t *person);
void delete_member(person_t *person);
person_t *look_up_for_person(person_t *person);

int main(int argc, char **argv)
{
    hash_table_init();

    person_t mark;
    mark.name = "mark";
    mark.age = 32;
    
    person_t john;
    john.name = "john";
    john.age = 41;
    
    person_t george;
    george.name = "george";
    george.age = 17;

    person_t alen;
    alen.name = "alen";
    alen.age = 25;

    person_t norman;
    norman.name = "norman";
    norman.age = 55;

    person_t dovanator;
    dovanator.name = "Alduin";
    dovanator.age = 44;

    insert_member(&dovanator);
    insert_member(&alen);
    insert_member(&norman);
    insert_member(&mark);
    insert_member(&john);
    insert_member(&george);

    print_table();

    printf("\n\n");
    delete_member(&george);

    print_table();
    
    return 0;    
}


void hash_table_init(void)
{
    int i;

    for (i = 0; i < TABLE_SIZE; i++)
    {
	hash_table[i] = NULL;
    }
}

unsigned int  hash(person_t *person)
{
    unsigned int hash_index, hash_value, i;

    for (i = hash_value = 0; person->name[i]; i++)
    {
	hash_value = (hash_value + person->name[i]) * person->name[i];
    }

    hash_index = hash_value % TABLE_SIZE;

    return hash_index;
}

void insert_member(person_t *person)
{
    if (person == NULL)
    {
	return;
    }
    
    unsigned int hash_index, i;
    
    hash_index = hash(person);

    if (!hash_table[hash_index])
    {
	hash_table[hash_index] = person;
	hash_table[hash_index]->next = NULL;
    }
    else
    {
	person->next = hash_table[hash_index];
	hash_table[hash_index] = person;
    }
}

void delete_member(person_t *person)
{
    unsigned int hash_index, i;
    hash_index = hash(person);
    person_t *temp = hash_table[hash_index];
   
    if (person->age == temp->age &&
	strncmp(person->name , temp->name, MAX_STRING) == 0)
    {
	hash_table[hash_index] = temp->next;	
    }
    else
    {
	for (;temp->next;)
	{
	    if (person->age == temp->next->age &&
		strncmp(person->name , temp->next->name, MAX_STRING) == 0)
	    {
		if (!temp->next->next)
		{
		    temp->next = NULL;		    
		}
		else
		{
		    temp->next = temp->next->next;
		}
		break;
	    }
	    temp = temp->next;
	}
    }
}

person_t *look_up_for_person(person_t *person)
{
    unsigned int hash_index, i;
    hash_index = hash(person);
    person_t *temp = hash_table[hash_index];

    for (i = 0; temp; i++)
    {
	if (person->age == temp->age &&
	    strncmp(temp->name, person->name, MAX_STRING) == 0)
	{
	    return temp;
	}
	temp = temp->next;
    }

    printf("\nNo such item in the hash table\n");
    return NULL;
}

void print_table(void)
{
    int i;
    person_t *temp;

    for (i = 0; i < TABLE_SIZE; i++)
    {
	printf("%d.", i);
	if (hash_table[i])
	{
	    printf("%s", hash_table[i]->name);
	    if (hash_table[i]->next)
	    {
		temp = hash_table[i]->next;
		for (;temp;)
		{
		    printf("->%s", temp->name);
		    temp = temp->next;
		}
	    }
	}

	printf("\n");
    }
}

