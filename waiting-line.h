
struct customer
{
    char name;
    struct customer *nextCustomer;
};

struct waitingLine
{
    char name;
    struct customer *firstCustomerInLine;
};


struct waitingLine *addToWaitingLine (struct waitingLine *waitingLine, struct customer *customer)
{
    if (NULL == waitingLine->firstCustomerInLine) {
        waitingLine->firstCustomerInLine = customer;
        return waitingLine;
    }

    struct customer *currentCustomer = waitingLine->firstCustomerInLine;

    while (NULL != currentCustomer->nextCustomer)
    {
        currentCustomer = currentCustomer->nextCustomer;
    }
    currentCustomer->nextCustomer = customer;

    return waitingLine;
}

void *switchWaitingLine (struct waitingLine *sourceWaitingLine, struct waitingLine *destWaitingLine)
{
    struct customer *currentCustomer = sourceWaitingLine->firstCustomerInLine;
    struct customer *nextCustomer = currentCustomer->nextCustomer;

    addToWaitingLine(destWaitingLine, currentCustomer);

    sourceWaitingLine->firstCustomerInLine = nextCustomer;
    currentCustomer->nextCustomer = NULL;
}

void *releaseFirstFromWaitingLine (struct waitingLine *waitingLine)
{
    struct customer *currentCustomer = waitingLine->firstCustomerInLine;
    struct customer *nextCustomer = currentCustomer->nextCustomer;

    waitingLine->firstCustomerInLine = nextCustomer;
    currentCustomer->nextCustomer = NULL;
    free(currentCustomer);
}

int numberOfCustomersInWaitingLine(struct waitingLine *waitingLine)
{

    if (NULL == waitingLine->firstCustomerInLine) {
        return 0;
    }

    int numberOfCustomers = 0;

    struct customer *customer = waitingLine->firstCustomerInLine;

    for (struct customer *n = customer; customer != NULL; customer = customer->nextCustomer)
    {
        numberOfCustomers++;
    }
    return numberOfCustomers;
}

void outputWaitingLineInfo(struct waitingLine *waitingLine)
{
    printf(" %d customers in waiting line %c: ", numberOfCustomersInWaitingLine(waitingLine), waitingLine->name);

    struct customer *customer = waitingLine->firstCustomerInLine;
    for (struct customer *n = customer; customer != NULL; customer = customer->nextCustomer) {
        printf("%c ", customer->name);
    }

    printf(" \r\n");
}
