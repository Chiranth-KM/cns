#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long int p, q, n, quotient, flag;
long int public_key[100], private_key[100], temp[100], key_index;
long int plaintext[100], ciphertext[100], i;
char message[100];

int is_prime(long int);
void generate_keys();
long int compute_modular_inverse(long int);
void encrypt();
void decrypt();

int main() {
    // Input for the first prime number
    printf("Enter 1st Prime Number: ");
    scanf("%ld", &p);
    flag = is_prime(p);
    if (flag == 0 || p == 1) {
        printf("WRONG INPUT\n");
        exit(1);
    }

    // Input for the second prime number
    printf("Enter 2nd Prime Number: ");
    scanf("%ld", &q);
    flag = is_prime(q);
    if (flag == 0 || q == 1 || p == q) {
        printf("WRONG INPUT\n");
        exit(1);
    }

    // Input for the message to be encrypted
    printf("Enter the message: ");
    scanf(" %[^\n]s", message);
    for (i = 0; i < strlen(message); i++)
        plaintext[i] = message[i];

    n = p * q;
    quotient = (p - 1) * (q - 1);

    generate_keys();

    printf("\nPOSSIBLE VALUES OF PUBLIC KEY AND PRIVATE KEY ARE:\n");
    for (i = 0; i < key_index - 1; i++)
        printf("%ld\t%ld\n", public_key[i], private_key[i]);

    encrypt();
    decrypt();

    return 0;
}

// Function to check if a number is prime
int is_prime(long int pr) {
    if (pr == 1)
        return 0;

    for (int i = 2; i <= sqrt(pr); i++) {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

// Function to generate RSA keys
void generate_keys() {
    int k = 0;
    for (i = 2; i < quotient; i++) {
        if (quotient % i == 0)
            continue;
        flag = is_prime(i);
        if (flag == 1 && i != p && i != q) {
            public_key[k] = i;
            flag = compute_modular_inverse(public_key[k]);
            if (flag > 0) {
                private_key[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }
    key_index = k;
}

// Function to compute the modular inverse
long int compute_modular_inverse(long int x) {
    long int k = 1;
    while (1) {
        k = k + quotient;
        if (k % x == 0)
            return (k / x);
    }
}

// Function to encrypt the message
void encrypt() {
    long int pt, ct, key = public_key[0], k, len;
    len = strlen(message);
    for (i = 0; i < len; i++) {
        pt = plaintext[i];
        k = 1;
        for (int j = 0; j < key; j++) {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ciphertext[i] = k;
    }
    ciphertext[i] = -1;
    printf("\nThe Encrypted Message is:\n");
    for (i = 0; ciphertext[i] != -1; i++)
        printf("%ld ", ciphertext[i]);
    printf("\n");
}

// Function to decrypt the message
void decrypt() {
    long int pt, ct, key = private_key[0], k;
    for (i = 0; ciphertext[i] != -1; i++) {
        ct = temp[i];
        k = 1;
        for (int j = 0; j < key; j++) {
            k = k * ct;
            k = k % n;
        }
        pt = k;
        plaintext[i] = pt;
    }
    plaintext[i] = -1;
    printf("\nThe Decrypted Message is: ");
    for (i = 0; plaintext[i] != -1; i++)
        printf("%c", plaintext[i]);
    printf("\n");
}
