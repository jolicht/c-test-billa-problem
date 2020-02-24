#include <stdio.h>
#include <stdlib.h>


#include "waiting-line.h"

int main()
{
    char humanInput;
    char command;

    struct waitingLine *mainWaitingLine = (struct waitingLine *) malloc(sizeof(struct waitingLine));
    struct waitingLine *desk1WaitingLine = (struct waitingLine *) malloc(sizeof(struct waitingLine));
    struct waitingLine *desk2WaitingLine = (struct waitingLine *) malloc(sizeof(struct waitingLine));
    mainWaitingLine->name = 'M';
    desk1WaitingLine->name = '1';
    desk2WaitingLine->name = '2';

    do{
        printf(": ");
        scanf(" %c", &humanInput);



        if('-' != humanInput){
            struct customer *customer = (struct customer *) malloc(sizeof(struct customer));
            customer->name = humanInput;
            addToWaitingLine(mainWaitingLine, customer);
        }
    } while(humanInput != '-');


    outputWaitingLineInfo(mainWaitingLine);

    do
    {
        printf(": ");
        scanf(" %c", &command);

        switch(command) {
            case 'a':
                if (0 == numberOfCustomersInWaitingLine(mainWaitingLine)) {
                    printf("main waiting line is empty\r\n");
                    break;
                }
                if (numberOfCustomersInWaitingLine(desk1WaitingLine) <= numberOfCustomersInWaitingLine(desk2WaitingLine)) {
                    switchWaitingLine(mainWaitingLine, desk1WaitingLine);
                } else {
                    switchWaitingLine(mainWaitingLine, desk2WaitingLine);
                }
                break;
            case '1':
                if (0 == numberOfCustomersInWaitingLine(desk1WaitingLine)) {
                    printf("desk 1  waiting line is empty\r\n");
                    break;
                }
                releaseFirstFromWaitingLine(desk1WaitingLine);
                break;
            case '2':
                if (0 == numberOfCustomersInWaitingLine(desk2WaitingLine)) {
                    printf("desk 2  waiting line is empty\r\n");
                    break;
                }
                releaseFirstFromWaitingLine(desk2WaitingLine);
                break;
        }

        outputWaitingLineInfo(mainWaitingLine);
        outputWaitingLineInfo(desk1WaitingLine);
        outputWaitingLineInfo(desk2WaitingLine);

    } while ('-' != command);

    return 0;
}
