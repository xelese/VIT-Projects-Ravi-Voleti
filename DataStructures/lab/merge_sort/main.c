#include <stdio.h>
#define max 10

int a[10];
int b[10];

void merge(int left, int mid, int right) {
   int i, j, k;

   for(i = left, j = mid + 1, k = left; i <= mid && j <= right; k++) {
      if(a[i] <= a[j])
         b[k] = a[i++];
      else
         b[k] = a[j++];
   }

   while(i <= mid)
      b[k++] = a[i++];

   while(j <= right)
      b[k++] = a[j++];

   for(k = left; k <= right; k++)
      a[k] = b[k];
}

void mergesort(int left, int right) {
   int mid;

   if(left < right) {
      mid = (left + right) / 2;
      mergesort(left, mid);
      mergesort(mid+1, right);
      merge(left, mid, right);
   } else {
      return;
   }
}

int main() {
   int k;
   printf("===============================\n");
   printf(" Enter the List for sorting\n");

   for(k = 0; k <= max; k++) scanf("%d ", &a[k]);
   printf("===============================");
   mergesort(0, max);

   printf("\nList after sorting\n");
   printf("===============================\n");
   for(k = 0; k <= max; k++)
      printf("%d ", a[k]);
   printf("\n===============================");
}
