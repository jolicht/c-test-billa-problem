#include <stdio.h>
#include <stdlib.h>

#include "node.h"

int main()
{
	// Lists here
    struct person * personInWaitingLine = NULL;
    struct person * personAtCashDeskOne = NULL;
    struct person * personAtCashDeskTwo = NULL;
    char personName;
    do{
        printf(": ");
        scanf(" %c", &personName);

        // Add person
        if(personName != '-'){
            personInWaitingLine = append(personInWaitingLine, personName);
        }
    } while(personName != '-');

    char command;

    if (NULL == personInWaitingLine) {
        return 0;
    }

    do
    {
        // Print here
        print(personInWaitingLine, personAtCashDeskOne, personAtCashDeskTwo);


        printf(": ");
        scanf(" %c", &command);

        switch(command)
        {
            case 'a':
            {
                // anstellen
                //node *nodePerson = getFirst(persons);
                char personName = getFirst(personInWaitingLine);

                personInWaitingLine = deleteFirst(personInWaitingLine);

                if (sizeOf(personAtCashDeskOne) <= sizeOf(personAtCashDeskTwo))
                {
                    if (NULL == personAtCashDeskOne) {
                        personAtCashDeskOne = personInWaitingLine;

                    } else {
                        personAtCashDeskOne->next = personInWaitingLine;
                    }


                    //personAtCashDeskOne = append(personAtCashDeskOne, personName);
                }
                else
                {
                    personAtCashDeskTwo = append(personAtCashDeskTwo, personName);
                }
                break;
            }

            case '1':
                // kassa1
                personAtCashDeskOne = deleteFirst(personAtCashDeskOne);
                break;
            case '2':
                // kassa2
                personAtCashDeskTwo = deleteFirst(personAtCashDeskTwo);
                break;
        }
    } while ('-' != command);

    // free list

    return 0;
}
