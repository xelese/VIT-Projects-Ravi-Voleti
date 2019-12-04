#include<stdio.h>
int main()
{

int n,i,j,k,temp,a[20],ch=0;
printf("Enter the number of elements in the array\n");
scanf("%d",&n);

for(i=0;i<n;i++)
    {
      printf("Enter element %d\n",i+1);
      scanf("%d",&a[i]);
    }

printf ("Selection sort.\narray before sorting:\n");
for (i=0;i<n;i++)
    printf ("%d ",a[i]);

printf ("\n");

for(i=0;i<n;i++)
    {
      printf ("After iteration %d\n", i+1);
      for(j=i+1;j<n;j++)
        {
           if(a[i]>a[j])
               {
                 temp=a[i];
                 a[i]=a[j];
                 a[j]=temp;
               }
         }
        printf("Do you want to see this iteration? 1.yes 2.no\n");
        scanf("%d",&ch);
        if(ch==1){
          for (k=0;k<n;k++)
              printf ("%d ",a[k]);
          printf ("\n");
        }
    }
printf("Array after sorting:\n");
for(i=0;i<n;i++)
    printf ("%d ",a[i]);

return 0;
}
