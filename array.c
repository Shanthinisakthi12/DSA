//Implementation of LIST ADT using array

#include <stdio.h>
#include<stdlib.h>
int a[100],n;
void ins_last(){
    int ele;
    printf("enter the ele to insert\n");
    scanf("%d",&ele);
    n=n+1;
    a[n-1]=ele;
    printf("inserted\n");
}
void del_last(){
    n=n-1;
    printf("deleted\n");
}
void size_a(){
    int count=0;
    for(int i=0;i<n;i++){
        count++;
    }
    printf("the size of the array = %d\n",count);
}
void search(){
    int ele;
    printf("enter the element to search\n");
    scanf("%d",&ele);
    for(int i=0;i<n;i++){
        if(a[i]==ele){
            printf("%d element found at index =%d\n",ele,i);
        }
        else
        printf("%d not found at index = %d\n",ele,i);
    }
}
void del_middle(){



  
}
void update(){
    int ele,val;
    printf("enter the element to search\n");
    scanf("%d",&ele);
    printf("enter the value to be updated\n");
    scanf("%d",&val);
    for(int i=0;i<n;i++){
    if(a[i]==ele){
        a[i]=val;
        printf("%d new value updated at index =%d\n",val,i);
    }
    else{
        printf("%d not found\n",ele);
    }
    }
}
void disp(){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
    
}
void ins_middle(){
    int ele,index;
    printf("enter the element to be inserted\n");
    scanf("%d",&ele);
    printf("enter the index\n");
    scanf("%d",&index);
    n=n+1;
    for(int i=n-1;i>=index;i--)
    {
        a[i]=a[i-1];
    }
        
        a[index-1]=ele;
}

int main(){
    int i,choice;
    printf("enter the value of n\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    while(1){
    printf("\n menu \n1.insertion \n2.deletion \n3.update \n4.serach \n5.display \n6.size \n7.insertion at the last \n8.deletion at the last \n 9.exit");
    printf("enter the choice\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: ins_last();
        break;
        case 2: del_last();
        break;
        case 3: update();
        break;
        case 4: search();
        break;
        case 5:disp();
        break;
        case 6:size_a();
        break;
        case 7:ins_middle();
        break;
        case 8:del_middle();
        break;
        case 9:exit(0);
    }
    }
}
