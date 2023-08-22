//insertion sort using C
#include <stdio.h>


void swap(int *a, int *b ){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
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


int main() {

    int a[10],n;
    printf("enter the size of the array\n");
    scanf("%d",&n);
    printf("enter the elements of the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Before sorting-Insertion sort ") ;
    for(int i=0; i<n; i++){
        printf("%d\t",a[i] );
    
    }

    insertion_sort(a, n) ;

    printf("\n\nAfter sorting-Insertion sort ") ;
    for(int i=0; i<n; i++){
        printf("%d\t",a[i] );
    
    }
    return 0;
}
