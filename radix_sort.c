#include <stdio.h>


int max( int a[], int n){

    int myMax = -1 ;
    for(int i=0; i<n; i++){
        if(a[i] > myMax)myMax = a[i] ;
    }

    return myMax ;
}

void count_sort(int a[], int n, int digit){
    int count[10] = {0} ;
    int sorted[n] ;

    for(int i=0; i<n; i++){
        count[(a[i]/digit)%10]++ ;
    }
    for(int i=1; i<10; i++){
        count[i] += count[i-1] ;
    }

    for(int i=n-1; i>=0; i--){
        sorted[--count[(a[i]/digit)%10]] = a[i] ;
    }

    for(int i=0; i<n; i++){
        a[i] = sorted[i] ;
    }
}

void radix_sort(int a[], int n){

    int myMax = max(a,n) ;

    for(int digit=1; myMax/digit; digit*=10){
        count_sort(a,n,digit) ;
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

    radix_sort(a, n) ;

    printf("\n\nAfter sorting : ") ;
    for(int i=0; i<n; i++){
        printf("%d\t",a[i] );
        
    }}
