#include<stdio.h>
#include<ctype.h>
#include<string.h>

void enrypt(char pt[], int key)
{
    for (int i = 0; i < strlen(pt); i++)
    {
        if (islower(pt[i]))
        {
            pt[i]=(pt[i]-'a'+key)%26 +'a';
        }

        else if (isupper(pt[i]))
        {
            pt[i]=(pt[i]-'A'+key)%26 +'A';
        }
        
    }
    
}

void decrypt(char pt[], int key)
{
    for (int i = 0; i < strlen(pt); i++)
    {
        if (islower(pt[i]))
        {
            pt[i]=(pt[i]-'a'-key+26)%26 +'a';
        }

        else if (isupper(pt[i]))
        {
            pt[i]=(pt[i]-'A'+key+26)%26 +'A';
        }
    }
    
}

void main()
{
    char pt[100]={};
    int key=3;
    printf("Enter the plain text:");
    gets(pt);

    enrypt(pt,key);
    printf("%s\n",pt);
    decrypt(pt,key);
    printf("%s",pt);
    
}
