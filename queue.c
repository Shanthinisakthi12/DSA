//implementation of queue using array
#include<stdio.h>   
#include<stdlib.h>    
int front = -1, rear = -1;  
int queue[10],n;
void enqueue()  
{  
    int ele;  
    if(rear == n-1)  
    {  
        printf("\nOVERFLOW\n");
        return;
         
    } 
  else{
    if(front == -1)  
    {  
        front = 0;   
    }  
    else   
    {  
        printf("\nEnter the element\n");  
        scanf("\n%d",&ele);      
        rear = rear+1;  
        queue[rear] = ele;  
        printf("\nValue inserted ");  }
      
}  }
void dequeue()  
{  
    if (front == -1 || front > rear)  
    {  
        printf("\nUNDERFLOW\n");   
              
    }  
    else  
    {  
        printf("deleted element=%d",queue[front]);
        front++;
    }  
      
      
}  
      
void display()  
{  
    int i;  
    if(rear == -1)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        for(i=front;i<=rear;i++)  
        {  
            printf("\n%d\n",queue[i]);  
        }     
    }  
}  
void main ()  
{  
    int choice; 
  printf("Enter the size of the queue");
  scanf("%d",&n);
    while(1)   
    {     
        printf("\n*************************Main Menu*****************************\n");  
        printf("\n=================================================================\n");  
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice ?");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            enqueue();  
            break;  
            case 2:  
            dequeue();  
            break;  
            case 3:  
            display();  
            break;  
            case 4:  
            exit(0);  
            break;  
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
}  
