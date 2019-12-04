#include<stdio.h>
#include <string.h>
#define MAX_STRINGS 5
#define MAX_STRING_LEN 200

int i,j,k;
void inst_sort(int []);
void InsertionSort(char list[MAX_STRINGS][MAX_STRING_LEN]);

/// NUMBERS
void inst_sort(int num[])
{
 for(j=1;j<5;j++)
 {
  k=num[j];
  for(i=j-1;i>=0 && k<num[i];i--)
   num[i+1]=num[i];
  num[i+1]=k;
 }
}
///CHARACTERS
void InsertionSort(char list[MAX_STRINGS][MAX_STRING_LEN])
{
    for (i = 1; i < MAX_STRINGS; i++)
    {
        int j = i;

        while (j > 0 && strcmp(list[j - 1], list[j]) > 0)
        {
            char tmp[MAX_STRING_LEN];
            strncpy(tmp, list[j - 1], sizeof(tmp) - 1);
            tmp[sizeof(tmp) - 1] = '\0';

            strncpy(list[j - 1], list[j], sizeof(list[j - 1]) - 1);
            list[j - 1][sizeof(list[j - 1]) - 1] = '\0';

            strncpy(list[j], tmp, sizeof(list[j]));
            list[j][sizeof(list[j]) - 1] = '\0';

            --j;
        }
    }
}

int main()
{
    int choice=0,ch=1;
 do{
     printf("1.Numbers\t2.Characters");
     scanf("%d",&ch);
         if(ch==1){                                     /// NUMBERS
             int num[5],count;
             printf("\nEnter the Five Numbers to sort:\n");

             for (count=0;count<5;count++)
              scanf("%d",&num[count]);
             inst_sort(num);

             printf("\n\nNumbers after sorting: \n");
             for(count=0;count<5;count++)
              printf("%d\n",num[count]);
             printf("\n Do you wish to continue?\nfor yes press 1\nto discontinue press 2");
             scanf("%d",&choice);
         }
         else if(ch==2){                                /// CHARACTERS
          int index;
    char strings[MAX_STRINGS][MAX_STRING_LEN];

    ///Get input
    printf("Enter %d strings.\n", MAX_STRINGS);
    for (index = 0; index < MAX_STRINGS; index++)
    {
        printf("Input string %d : ", index);
        scanf("%199s", strings[index]);     /// limit the width so we don't go past the buffer
        strings[index][sizeof(strings[index]) - 1] = '\0';
    }

    InsertionSort(strings);

    printf("\nThe input set, in alphabetical order:\n");
    for (index = 0; index < MAX_STRINGS; index++)
    {
        printf("%s\n", strings[index]);
    }
             printf("\n Do you wish to continue?\nfor yes press 1\nto discontinue press 2");
             scanf("%d",&choice);
         }
 }while(choice == 1);
}

