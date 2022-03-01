#include<stdio.h>
#include<stdlib.h>
#define NODE_SIZE 5
typedef struct node
{
	char data;
	struct node *link;
}node;

node *head=0,*new =0,*latest=0,*temp=0;

void insert(int data1)
{
	new = (node*)malloc(sizeof(node));
        new->data = data1;
        new->link = NULL;
        if(head==NULL)
          head=new;
        else
          latest->link=new;
        latest=new;
	return ;
}

void des_sort()
{
	temp = head;
        int i,j,temp1;
	if(temp==NULL)
                printf("Node is Empty\n");
	else
	{
	  for(i=0;i<NODE_SIZE -1;i++)
	    {
	      temp=head;
	      for(j=0;j<NODE_SIZE -i-1;j++)
	      {
		  if((temp->data) < (temp->link->data))
		  {
		      temp1 = temp->data;
		      temp->data = temp->link->data;
		      temp->link->data = temp1;
		  }
		  temp=temp->link;
	      }
	    }
	}
	return ;
}
void display()
{
	temp = head;
	if(temp==NULL)
		printf("Node is Empty\n");
	else
	{
          while(temp!=NULL)
          {
            printf("%-4d",temp->data);
            temp=temp->link;
          }
	}
	return ;
}
int main(void)
{
	int data,i=0;
	while(i<NODE_SIZE)
	{
	printf("Enter Data\n");
	scanf("%d",&data);
	insert(data);
	i++;
	}
	des_sort();
	display();
	return 0;
}
