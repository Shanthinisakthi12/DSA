//stack using array
#include <stdio.h>
#include<stdlib.h>
int stack[100],n,top =-1;
void push(){
    int ele;
    printf("enter the element to be inserted\n");
    scanf("%d",&ele);
    if(top>= n-1)
    {
        printf("element cannot be inserted- stack overflow\n");
    }
    else{
        top++;
        stack[top]=ele;    
}}
void pop(){
    if(top<=-1){
        printf("stack underflow\n");
        
    }
    else{
        top --;
    }
}
void display(){
    for(int i=top;i>=0;i--){
        printf("%d",stack[i]);
    }
}
void peak(){
    printf("peak=%d",stack[top]);
}
int main(){
    int choice,n;
    printf("enter the size of the stack");
    scanf("%d",&n);
    while(1){
    printf("\n MENU \n1.PUSH \n2.POP \n3.PEAK \n4.DISPLAY \n5.EXIT");
    printf("enter the choice\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: push();
        break;
        case 2: pop();
        break;
        case 3: peak();
        break;
        case 4: display();
        break;
        case 5:exit(0);
    }
    }
}
