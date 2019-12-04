#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch=0,data=0,n=0,i=0,j=0,m=0,f=0,l,array[15],temp=0;
    printf("enter the number of values: \n");
            scanf("%d",&n);
            l=n-1;
            for(i=0;i<n;i++){
                printf("Enter the element: \n");
                scanf("%d",&array[i]);
            }
            printf("enter the element to be searched: \n");
            scanf("%d",&data);
        printf("1.Linear_search\t2.Binary_search\n");
        scanf("%d",&ch);
        if(ch==1){
            for(i = 0;i<n;i++){
                if(data == array[i]){
                    printf("%d element found at %d\n",data,i+1);
                }
                else if(data!=array[4]){
                    printf("element not found\n");
                }
            }
        }
        else if(ch==2){
          for (i=0;i<n;i++)
          {
            for (j=0;j<n-1;j++)
            {
              if (array[j]>array[j+1])
              {
                temp       = array[j];
                array[j]   = array[j+1];
                array[j+1] = temp;
              }
            }
          }
          printf("sorted array\n");
          for(i=0;i<n;i++){
            printf("%d\t",array[i]);
          }
              while (f<=l) {
                  if (array[m] < data)
                     f= m+1;
                  else if (array[m]==data) {
                     printf("\n%d found at location %d.\n", data, m+1);
                     break;
                  }
                  else
                     l=m-1;

                  m=(f+l)/2;
               }
               if (f>l)
                  printf("\nNot found! %d is not present in the list.\n", data);

       return 0;

          }
}
