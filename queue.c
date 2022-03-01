#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int data;
    struct queue *link;
}queue;
void enque(int data,queue **front,queue **rear)
{
    queue *new=NULL;
    new = (queue *)malloc(sizeof(queue));
    if(new==NULL)
    {
	 printf("Memory not allocated\n");
    }
    else
    {
    new->data=data;
    new->link=NULL;
    }
    if(*front == NULL && *rear == NULL)
    {
	   *front = new;
	   *rear = new;
    }
    else
    {
	   (*rear)->link=new;
	   (*rear)=new;
    } 
    return ;
}
void deque(queue **front,queue **rear)
{
   if(*front == NULL)
       printf("Queue is Empty\n");
   else
   {
       queue *temp = *front;
       *front = temp->link;
       free(temp);       
   }   
   return ;
}
void peek(queue **front)
{
    printf("Peek element in Queue is %d\n",(*front)->data);
    return ;
}
void display(queue **front,queue **rear)
{
    queue *temp = *front;
    printf("Queue Elements\n");
    while(temp!=NULL)
    {
	printf("Data : %d\n",temp->data);
        temp = temp->link;	
    }
    return ;
}
int main(void)
{
     queue *front =NULL,*rear=NULL;
     enque(10,&front,&rear);
     enque(20,&front,&rear);
     enque(30,&front,&rear);
     enque(40,&front,&rear);
     peek(&front);
     display(&front,&rear);
     deque(&front,&rear);
     deque(&front,&rear);
     deque(&front,&rear);
     peek(&front);
     display(&front,&rear);
     return 0;
}
