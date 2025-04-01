#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
void create();
void display();
void insertatbeg();
void insertatend();
void insertatspec();
void delatbeg();
void delatend();
int main()
{
    int opt,n,i;
    while(1)
    {
        printf("\n1.create\n2.display\n3.insertatbeg\n4.exit\n5.inseratend\n6.insertatspec\n7.delatbeg\n8.delatend");
        printf("\nenter your option");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("\n enter no.of nodes");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                create();
            }
            break;
            case 2: display();
            break;
            case 3: insertatbeg();
            break;
            case 4:exit(0);
            case 5:insertatend();
            break;
            case 6:  insertatspec();
            break;
            case 7:delatbeg();
            break;
            case 8: delatend();
            break;
            default: printf("Invalid Option");
        }
    }
}
void create()
{
    struct node *newnode,*temp;
    int ele;
    printf("enter element");
    scanf("%d",&ele);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=ele;
    if(start==NULL)
    {
        start=newnode;
        newnode->next=start;
    }
    else
    {
        temp=start;
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        newnode->next=start;
        temp->next=newnode;  
    }
}
void display()
{
    struct node *temp;
    temp=start;
    while(temp->next!=start)
    {
    printf("%d->",temp->data);
    temp=temp->next;
    }
    printf("%d->",temp->data);
   
}
void insertatbeg()
{
    struct node *temp,*newnode;
    int ele;
    printf("enter element");
    scanf("%d",&ele);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=ele;
    if(start==NULL)
    {
        start=newnode;
        newnode->next=start;
    }
    else
    {
      temp=start;
      while(temp->next!=start)
      {
           temp=temp->next;
      }
      newnode->next=start;
      start=newnode;
      temp->next=start;
    }
}
void insertatend()
{
    struct node *temp,*newnode;
    int ele;
    printf("enter element");
    scanf("%d",&ele);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=ele;
    if(start==NULL)
    {
        start=newnode;
        newnode->next=start;
    }
    else
    {
      temp=start;
      while(temp->next!=start)
      {
           temp=temp->next;
      }
      temp->next=newnode;
      newnode->next=start;
    }
}
void insertatspec()
{
    struct node *temp=start,*newnode;
    int ele,loc,i;
    printf("enter element");
    scanf("%d",&ele);
    printf("\nenter location after which node you want to insert");
    scanf("%d",&loc);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=ele;
    for(i=1;i<loc;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void delatbeg()
{
    struct node *temp=start;
    if(start==NULL)
    {
        printf("list is empty");
    }
    else
    {
         if(start->next==start)
         {
             start=NULL;
             free(temp);
         }
         else
         {
            start=temp->next;
         }
         free(temp);
    }
}
void delatend()
{
    struct node *temp1=start,*temp2;
    if(start==NULL)
    {
        printf("list is empty");
    }
    else
    {
         if(start->next==start)
         {
             start=NULL;
         }
         else
         {
            while(temp1->next!=start)
            {
                temp2=temp1;
                temp1=temp1->next;
            }
            temp2->next=start;
         }
   free(temp1);
    }
}
