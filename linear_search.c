//linear serach in c

#include<stdio.h>

int main() {
  int a[20], n, key, i, index;
  printf("Enter the size\n");
  scanf("%d", &n);
  printf("Enter elements\n");
  for (i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  printf("Enter the element to search\n");
  scanf("%d", &key);
  for (i= 0; i<n; i++){
    if (a[i] == key){
      break; 
    }}
  if (i < n) 
    printf("Key element found at index %d", i);
  else
    printf("Key element not found");

  return 0;
}
