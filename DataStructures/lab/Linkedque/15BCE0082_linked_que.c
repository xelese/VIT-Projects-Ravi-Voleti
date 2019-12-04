#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
}*fr,*re,*temp,*f;

void enqueue(int data);
void dequeue();
void display();
void create();
int switcher = 0;
void main()
{
    if(switcher == 0){
        int no, ch, e;

        printf("============================");
        printf("\n 1 - ENTER AN ELEMENT");
        printf("\n 2 - DEQUE AN ELEMENT");
        printf("\n 3 - DISPLAY QUEUE");
        printf("\n 4 - EXIT");
        printf("\n============================");
        create();
        while (1)
        {
            printf("\n Enter choice : ");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                printf("Enter data : ");
                scanf("%d", &no);
                enqueue(no);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice, Please enter correct choice  ");
                break;
            }
        }
    }
}

/* Create an empty queue*/
void create()
{
    fr = re = NULL;
}

/* Enque*/
void enqueue(int data)
{
    if (re == NULL)
    {
        re = (struct node *)malloc(1*sizeof(struct node));
        re->ptr = NULL;
        re->data = data;
        fr = re;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        re->ptr = temp;
        temp->data = data;
        temp->ptr = NULL;

        re = temp;
    }

}

/* Display */
void display()
{
    f = fr;

    if ((f == NULL) && (re == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (f != re)
    {
        printf("%d ", f->data);
        f = f->ptr;
    }
    if (f == re)
        printf("%d", f->data);
}

/* Dequeing the queue */
void dequeue()
{
    f = fr;

    if (f == NULL)
    {
        printf("\n :Error:");
        return;
    }
    else
        if (f->ptr != NULL)
        {
            f = f->ptr;
            printf("\n Dequed value : %d", fr->data);
            free(fr);
            fr = f;
        }
        else
        {
            printf("\n Dequed value : %d", fr->data);
            free(fr);
            fr = NULL;
            re = NULL;
        }

}

