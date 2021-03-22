#include <iostream>

// First realisation
class FIFO1
{
public:
    FIFO1(int input_size);
    ~FIFO1(void);
    void push(int value);
    int pop(void);

private:
    int size;
    int *data;
    int front, back;
};

FIFO1::FIFO1(int input_size)
{
    size = input_size;
    data = new int[input_size];
    front = back = 0;
}

FIFO1::~FIFO1(void)
{
    delete[] data;
}

void FIFO1::push(int element)
{
    int temp, i;

    if (back + 1 >= size)
    {
	std::cout << "Queue is full" << std::endl;
    }
    else
    {
	for (i = back; i > 0; i--)
	{
	    data[i] = data[i - 1];
	    
	}
	data[front] = element;
	back++;
    }   
}

int FIFO1::pop(void)
{
    if (front == back)
    {
	std::cout << "Queue is empty" << std::endl;
	return 0;
    }
    else
    {
	return data[--back];
    }
}


// Second realisation

class FIFO2
{
public:
    FIFO2(void);
    void push(int value);
    int pop(void);

private:
    struct node
    {
	int data;
	struct node *next;
	struct node *prev;
    };
    node *front, *back;
};

FIFO2::FIFO2(void)
{
    front = back = 0;
}

void FIFO2::push(int value)
{
    node *temp = new node;
    temp->data = value;
    if (!front && !back)
    {
	front = temp;
	back = temp;

	front->next = front->prev = 0;	
    }
    else
    {
	front->prev = temp;
	temp->next = front;
	front = temp;
    }
}

int FIFO2::pop(void)
{
    int data_to_return = back->data;
    if (back)
    {
	if (back != front)
	{
	    back = back->prev;
	    delete back->next;
	}
	else
	{
	    delete back;
	    front = back = 0;
	}
    }
    else
    {
	std::cout << "Queue is empty" << std::endl;
	data_to_return = 0;
    }

    return data_to_return;
}


int main(int argc, char **argv)
{
    FIFO1 queue(12);
    // FIFO2 queue;
    queue.push(1);
    std::cout << queue.pop() << std::endl;
    queue.push(8);
    queue.push(7);
    queue.push(5);
    queue.push(1);
    queue.push(1);
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    queue.push(3);
    queue.push(4);
    
    return 0;
}

