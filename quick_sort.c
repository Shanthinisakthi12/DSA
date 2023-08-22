//quick sort implementation in c
#include <stdio.h>

void swap(int *s, int *t ){
    int temp = *s ;
    *s = *t ;
    *t = temp ;
}


int partition( int a[], int lb, int ub){

    int start=lb, end=ub, pivot=a[lb] ;

    while(start < end){

        while(a[start] <= pivot){
            start++ ;
        }
        while(a[end] > pivot){
            end-- ;
        }

        if(start < end)swap(&a[start], &a[end]) ;
    }

    swap(&a[lb], &a[end]) ;

    return end ;
}

void quick_sort( int a[], int lb, int ub){

    if( lb < ub ){
        int location = partition(a, lb, ub) ;
        quick_sort(a, lb, location-1) ;
        quick_sort(a, location+1, ub) ;
    }
}


int main() {

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

    quick_sort(a, 0, n-1) ;

    printf("\n\nAfter sorting : ") ;
    for(int i=0; i<n; i++){
        printf("%d\t",a[i] );
    }
    return 0;
}
