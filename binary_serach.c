//binary search using c
#include <stdio.h>
int main()
{
  int  first, last, middle, n, key, a[100];

  printf("Enterthe value of n\n");
  scanf("%d", &n);
  printf("Enter the elements\n");
  for (int i = 0; i < n; i++){
    scanf("%d", &a[i]);}
  printf("Enter the element to search\n");
  scanf("%d", &key);
  first = 0;
  last = n - 1;
  middle = (first+last)/2;
  while (first <= last) {
    if (a[middle] < key){
      first = middle + 1;}
    else if (a[middle] == key) {
      printf("element found at posiion %d.\n",middle+1);
      break;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  if (first > last)
    printf("element not found\n");

  return 0;
}
