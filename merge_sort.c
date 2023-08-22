//merge sort using array
#include <stdio.h>


void merge( int a[], int lb, int mid, int ub ){

    int k=0, i=lb, j=mid+1 ;
    int b[ub-lb+1] ;

    while( i<=mid && j<=ub ){
        if( a[i] <= a[j] ){
            b[k] = a[i] ;
            ++i;
        }
        else if( a[i] > a[j] ){
            b[k] = a[j] ;
            j++ ;
        }
        k++ ;
    }

    while( i <= mid ){
        b[k] = a[i] ;
        i++ ;
        k++ ;
    }

    while( j<=ub ){
        b[k] = a[j] ;
        j++ ;
        k++ ;
    }
    for( int q=lb ; q<=ub ; q++ ){
        a[q] = b[q-lb] ;
    }
}

void merge_sort( int a[], int lb, int ub ){
    if( lb < ub ){

        int mid = ( lb+ub ) / 2 ;
        merge_sort( a , lb , mid ) ;
        merge_sort( a , mid+1 , ub ) ;

        merge( a , lb , mid , ub ) ;
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

    merge_sort(a, 0, n-1) ;

    printf("\n\nAfter sorting : ") ;
    for(int i=0; i<n; i++){
        printf("%d\t",a[i] );
    }
    return 0;
}
