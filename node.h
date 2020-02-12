#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

struct person
{
    char name;

    struct person *next;
};

struct person * append (struct person *i_node, char i_name)
{
    struct person *newNode = (struct person *) malloc(sizeof(struct person));
    newNode->name = i_name;
    newNode->next = NULL;

    if (i_node == NULL)
    {
        i_node = newNode;
    }
    else
    {
        struct person *curNode = i_node;
        while (curNode->next != NULL)
        {
            curNode = curNode->next;
        }
        curNode->next = newNode;
    }
    return i_node;
}

//struct node * getFirst (struct node *i_node)
char getFirst (struct person *i_node)
{
    //node *first = NULL;
    char first = '-';
    if (i_node != NULL)
    {
        //first = i_node;
        first = i_node->name;
        i_node = i_node->next;
    }
    return first;
}

struct person * deleteFirst (struct person *i_node)
{
    struct person *first = NULL;
    if (i_node->next != NULL)
    {
        first = i_node->next;
    }
    free(i_node);
    return first;
}

int sizeOf (struct person *i_list)
{
    int size = 0;
    for (struct person *n = i_list; n != NULL; n = n->next)
    {
        size++;
    }
    return size;
}

void printElems (struct person * i_list)
{
    printf(" %d\r\n", sizeOf(i_list));
    for (struct person *n = i_list; n != NULL; n = n->next)
    {
        printf("%c ", n->name);
    }
    printf("\r\n");
}

void print (struct person *i_person, struct person *i_kassa1, struct person *i_kassa2)
{
    printf("Personen:");
    printElems(i_person);

    printf("Kassa 1:");
    printElems(i_kassa1);

    printf("Kassa 2:");
    printElems(i_kassa2);
}

void freeList (struct person *i_list)
{
    struct person *tmp;
    while (i_list != NULL)
    {
        tmp = i_list->next;
        free(i_list);
        i_list = tmp;
    }
}
#endif // NODE_H_INCLUDED
