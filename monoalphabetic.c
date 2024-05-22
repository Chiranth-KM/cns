#include<stdio.h>
#include<string.h>

char alpha[27][3] = { { 'a', ' ' }, { 'b', ' ' }, { 'c', ' ' }, { 'd', ' ' }, {
        'e', ' ' }, { 'f', ' ' }, { 'g', ' ' }, { 'h', ' ' }, { 'i', ' ' }, {
        'j', ' ' }, { 'k', ' ' }, { 'l', ' ' }, { 'm', ' ' }, { 'n', ' ' }, {
        'o', ' ' }, { 'p', ' ' }, { 'q', ' ' }, { 'r', ' ' }, { 's', ' ' }, {
        't', ' ' }, { 'u', ' ' }, { 'v', ' ' }, { 'w', ' ' }, { 'x', ' ' }, {
        'y', ' ' }, { 'z', ' ' }};

void assignkey()
{
    char *key="qwertyuiopasdfghjklzxcvbnm";
    for (int i = 0; i < strlen(key); i++)
    {
        alpha[i][1]=key[i];
    }
}

char encryp(char a)
{
    int i;
    for(i=0; i<27; i++)
    {
        if(a==alpha[i][0])
        return alpha[i][1];
    }
    return a;
}

char dencryp(char a)
{
    int i;
    for(i=0; i<27; i++)
    {
        if(a==alpha[i][1])
        return alpha[i][0];
    }
    return a;
}
void main()
{
    char pt[100]={};
    gets(pt);
    int size= strlen(pt);

    assignkey();

    char enc[100];
    char dec[100];
    for (int i = 0; i < size; i++)
    {
        enc[i]=encryp(pt[i]);
    }

    for (int i = 0; i < size; i++)
    {
        dec[i]=dencryp(enc[i]);
    }
    
    for (int i = 0; i < size; i++)
    {
        printf("%c",enc[i]);
    }

    printf("\n");

    for (int i = 0; i < size; i++)
    {
        printf("%c",dec[i]);
    }
}
