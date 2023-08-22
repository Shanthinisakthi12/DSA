#include <stdio.h>
#include <stdlib.h>


struct Node{
     int data ;
     struct Node* next ;
};

int get_max(int a[], int n){
     int myMax = -10000 ;
     for(int i=0; i<n; i++){
          if(a[i] > myMax){
               myMax = a[i] ;
          }
     }
}

void swap(int *s, int *t){
    int temp = *s ;
    *s = *t ;
    *t = temp ;
}

void insertion_sort( int a[] , int n){

    for( int i=1 ; i<n ; i++ ){

        int j = i ;
        while( j>0 && a[j]<a[j-1]){
            swap( &a[j] , &a[j-1] ) ;
            --j ;
        }
    }
}

void bucket_sort(int a[], int n){

     int max = get_max(a, n) ;
     int bucket[max] ;

     for(int i=0; i<max; i++)bucket[i] = 0 ;

     for(int i=0; i<n; i++){
          bucket[a[i]]++ ;
     }
     int j = 0 ;
     for(int i=0; i<max; i++){
          while(bucket[a[i]]--){
               a[j++] = i ;
          }
     }
}

int main(){

   int a[10],n;
    printf("enter the size of the array\n");
    scanf("%d",&n);
    printf("enter the elements of the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Before sorting : ") ;
    for(int i=0; i<n; i++){
        printf("%d\t",a[i] );
    }

    insertion_sort(a, n) ;

    printf("\n\nAfter sorting : ") ;
    for(int i=0; i<n; i++){
        printf("%d\t",a[i] );
    }

    return 0;
}
