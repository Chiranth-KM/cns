#include <stdio.h>
#include <string.h>

void encrypt(char pt[], int key[][3], int keySize)
{
    int enc[100];
    int len = strlen(pt);

    while (len % keySize != 0)
    {
        pt[len++] = 'x';
    }

    for (int i = 0; i < len; i++)
    {
        if (pt[i] == ' ')
            enc[i] = 23;

        else
            enc[i] = pt[i] - 'a';
    }

    for (int i = 0; i < len; i += keySize)
    {
        for (int j = 0; j < keySize; j++)
        {
            int sum = 0;
            for (int k = 0; k < keySize; k++)
            {
                sum += key[k][j] * enc[i + k];
            }
            enc[i + j] = sum % 26;
        }
    }

    for (int i = 0; i < len; i++)
    {
        printf("%c ", enc[i] + 'a');
    }
}

void main()
{
    int key[3][3] = {{17, 17, 5}, {21, 18, 21}, {2, 2, 19}};
    char plaintText[] = "paymoremoney";
    encrypt(plaintText, key, 3);
}
