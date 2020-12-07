#include <stdio.h>

#define MAX_LEN 128

typedef struct node
{
    char data;
    int frequency;
    struct node *left;
    struct node *right;
} node_t;

static char codes[MAX_LEN][MAX_LEN];
static node_t nodes[MAX_LEN];
static char symbols[MAX_LEN];
static node_t root_node;

void count_frequencies(char *string);
int is_symbol_written(char symbol);
void sort_nodes(node_t *nodes, int low, int high);
int partition(node_t *nodes, int low, int high);


void create_tree(void);
int count_number_of_nodes(void);
void print_tree(node_t *node);
void calculate_codes(node_t *node, char code[]);
void encode_the_message(char *message, char *encoded_message);
void decode_the_message(char *message, char *decoded_message);
int code_is_written(char *code);
int symbol_is_written(char symbol);
int are_equal(char *string1, char *string2);

int main(int argc, char **argv)
{
    char string[MAX_LEN] = "Javascript is shit";
    char encoded_string[MAX_LEN];
    char decoded_string[MAX_LEN];
    
    count_frequencies(string);

    printf("\nString to encode: %s\n", string);
    printf("\n------Frequencies------\n");
    for (int i = 0; nodes[i].data; i++)
    {
	printf("%c %d\n", nodes[i].data, nodes[i].frequency);
    }

    create_tree();
    printf("\n");
    char code[MAX_LEN] = "";
    calculate_codes(&root_node, code);

    printf("\n------Codes------\n");
    for (int i = 0; symbols[i] != '\0'; i++)
    {
	printf("%c %s\n", symbols[i], codes[i]);
    }

    encode_the_message(string, encoded_string);
    printf("\nEncoded message: %s\n", encoded_string);

    decode_the_message(encoded_string, decoded_string);
    printf("\nDecoded message: %s\n", decoded_string);
    return 0;
}

void count_frequencies(char *string)
{
    int i, j, pointer, size;

    for (i = pointer = 0; string[i] != '\0'; i++)
    {
	if (!is_symbol_written(string[i]))
	{
	    nodes[pointer].data = string[i];
	    nodes[pointer].frequency = 0;
	    nodes[pointer].left = nodes[pointer].right = 0;
	    
	    for (j = i; string[j] != '\0'; j++)
	    {
		if (string[i] == string[j])
		{
		    nodes[pointer].frequency++;
		}
	    }

	    pointer++;

	}
    }

    sort_nodes(nodes, 0, pointer - 1);

    for (i = 0; nodes[i].frequency; i++)
    {
	symbols[i] = nodes[i].data;
    }
}

int is_symbol_written(char symbol)
{
    int i;

    for (i = 0; nodes[i].data; i++)
    {
	if (nodes[i].data == symbol)
	{
	    return 1;
	}
    }

    return 0;
}

void sort_nodes(node_t *nodes, int low, int high)
{
    int pi;

    if (low <= high)
    {
	pi = partition(nodes, low, high);

	sort_nodes(nodes, low, pi - 1);
	sort_nodes(nodes, pi + 1, high);
    }
}

int partition(node_t *nodes, int low, int high)
{
    int pivot, i, j;
    node_t temp;
    
    pivot = nodes[high].frequency;
    i = low - 1;

    for (j = low; j <= high - 1; j++)
    {
	if (nodes[j].frequency < pivot)
	{
	    i++;
	    temp = nodes[j];
	    nodes[j] = nodes[i];
	    nodes[i] = temp;
	}
    }

    temp = nodes[high];
    nodes[high] = nodes[i + 1];
    nodes[i + 1] = temp;

    return i + 1;
}

void create_tree(void)
{
    int position, i, multiplexer;
    int number_of_nodes = count_number_of_nodes(); 
    
    position = 0;
    multiplexer = 1;
    while (number_of_nodes > 1)
    {
	node_t node;
	node.left = &nodes[position];
	node.right = &nodes[position + 1];
	node.frequency = node.left->frequency + node.right->frequency;

	// finding the position of new node
	for (; nodes[position].frequency <= node.frequency && nodes[position].frequency; position++);

	// move nodes to the right and insert the new node to the position
	for (i = position + number_of_nodes - 1; i >= position; i--)
	{
	    nodes[i + 1] = nodes[i];
	}
	nodes[position] = node;

	position = multiplexer * 2;
	multiplexer++;
	number_of_nodes--;
    }

    root_node = nodes[position];
}

int count_number_of_nodes(void)
{
    int i;

    for (i = 0; nodes[i].frequency; i++);
    
    return i;
}

void print_tree(node_t *node)
{
    node_t *temp = node;

    if (temp->left == NULL && temp->right == NULL)
    {
	printf("%c %d\n", temp->data, temp->frequency);	
    }
    else
    {
	print_tree(temp->left);
	print_tree(temp->right);
    }
}

void calculate_codes(node_t *node, char code[])
{
    int i, j;
    if (!node->left && !node->right)
    {
	for (i = 0; symbols[i] != '\0'; i++)
	{
	    if (symbols[i] == node->data)
	    {
		for (j = 0; code[j] != '\0'; j++)
		{
		    codes[i][j] = code[j];
		}
		break;
	    }
	}
    }
    else
    {
	char temp_code1[MAX_LEN] = "";
	char temp_code2[MAX_LEN] = "";

	i = 0;
	if (code[i])
	{
	    for (; code[i] != '\0'; i++)
	    {
	    temp_code1[i] = code[i];
	    temp_code2[i] = code[i];
	    }
	}
	temp_code1[i] = '0';
	temp_code2[i++] = '1';
	temp_code1[i] = '\0';
	temp_code2[i] = '\0';

	calculate_codes(node->left, temp_code1);
	calculate_codes(node->right, temp_code2);
    }
}


void encode_the_message(char *string, char *encoded_string)
{
    int i, j, encoded_string_pointer, symbol_pointer;    

    for (i = encoded_string_pointer = 0; string[i] != '\0'; i++)
    {
	symbol_pointer = symbol_is_written(string[i]);
	
	for (j = 0; codes[symbol_pointer][j] != '\0'; j++)
	{
	    encoded_string[encoded_string_pointer++] = codes[symbol_pointer][j];
	}
    }
    encoded_string[encoded_string_pointer] = '\0';

}

void decode_the_message(char *message, char *decoded_message)
{
    char temp_code[MAX_LEN];

    int i, temp_pointer, decoded_pointer, symbol_pointer;

    for (i = temp_pointer = decoded_pointer = 0; message[i] != '\0'; i++)
    {
	temp_code[temp_pointer++] = message[i];
	temp_code[temp_pointer] = '\0';

	if ((symbol_pointer = code_is_written(temp_code)) != -1)
	{
	    decoded_message[decoded_pointer++] = symbols[symbol_pointer];
	    temp_pointer = 0;
	}
    }
    decoded_message[decoded_pointer] = '\0';
}

int code_is_written(char *code)
{
    int i;

    for (i = 0; codes[i][0]; i++)
    {
	if (are_equal(codes[i], code))
	{
	    return i;
	}
    }

    return -1;
}

int symbol_is_written(char symbol)
{
    int i;

    for (i = 0; symbols[i] != '\0'; i++)
    {
	if (symbols[i] == symbol)
	{
	    return i;
	}
    }

    return -1;
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

