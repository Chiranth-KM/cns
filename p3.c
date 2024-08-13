
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int prepare(char pt[], int size)
{
    if(size%2==1)
    {
        pt[size++]='z';
        pt[size]='\0';
    }
    return size;
}

void keyTable(char key[], int ks, char mat[5][5])
{
    int *temp = (int*)calloc(26, sizeof(int));
    
    for(int k=0; k<ks; k++)
    {
        if(key[k]!='j')
        {
            temp[key[k]-97]=2;
        }
    }
    temp['j'-97]=1;
    
    int i=0, j=0;
    for(int k=0; k<ks; k++)
    {
        if(temp[key[k]-97]==2)
        {
            temp[key[k]-97]-=1;
            mat[i][j]=key[k];
            j++;
            if(j==5)
            {
                j=0;
                i++;
            }
        }
    }
    
    for(int k=0; k<26; k++)
    {
        if(temp[k]==0)
        {
            mat[i][j]=(char)(k+97);
            j++;
            if(j==5)
            {
                j=0;
                i++;
            }
        }
    }
}

void search(char mat[5][5], char a, char b, int arr[])
{
    if(a=='j')
    {
        a='i';
    }
    else if(b=='j')
    {
        b='i';
    }
    
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(mat[i][j]==a)
            {
                arr[0]=i;
                arr[1]=j;
            }
            
            else if(mat[i][j]==b)
            {
                arr[2]=i;
                arr[3]=j;
            }
        }
    }
}

void encrypt(char pt[], char mat[5][5], int ps)
{
    int a[4];
    for(int i=0; i<ps; i+=2)
    {
        search(mat,pt[i],pt[i+1],a);
        
        if(a[0]==a[2])
        {
            pt[i]=mat[a[0]][(a[1]+1)%5];
            pt[i+1]=mat[a[0]][(a[3]+1)%5];
        }
        
        else if(a[1]==a[3])
        {
            pt[i]=mat[(a[0]+1)%5][a[1]];
            pt[i+1]=mat[(a[2]+1)%5][a[1]];
        }
        
        else
        {
            pt[i]=mat[a[0]][a[3]];
            pt[i+1]=mat[a[2]][a[1]];
        }
    }
}


void playfair(char pt[], char key[])
{
    int ps=strlen(pt);
    int ks=strlen(key);
    ps=prepare(pt,ps);
    
    char mat[5][5];
    keyTable(key, ks, mat);
    encrypt(pt, mat, ps);
    
}

int main() {
    
    char pt[100], key[100];
    
    printf("Enter the plaintext:");
    scanf("%s",&pt);
    
    printf("Enter the key:");
    scanf("%s",&key);
    
    playfair(pt,key);
    
    printf("%s",pt);
    

    return 0;
}
