#include<stdio.h>
#include<string.h>
void main()
{
       int KeyWord,i;
      char PlainText[200];

      printf("\nEnter plain text in lowercase :\n");
      gets(PlainText);  //plain text.

      printf("\nEnter the key word: ");
      scanf("%d",&KeyWord);  //key.

      if(KeyWord>26)
      KeyWord=KeyWord % 26; //0<=key<26.

      for(i=0;i<strlen(PlainText);i++)
      {
       if(PlainText[i]==' ')
        {
          continue;
        }
       else
        {
          if(PlainText[i]>= 'x')
           {
            PlainText[i]=PlainText[i]-26;
           }

           PlainText[i]=PlainText[i]+KeyWord;
        }
     }
      printf("Your cipher text is: %s\n",PlainText); //cipher text.

  }
