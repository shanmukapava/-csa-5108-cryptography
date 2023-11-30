#include <stdio.h>

int modInverse(int a) {
    for (int x = 1; x < 26; x++) {
        if ((a * x) % 26 == 1) {
            return x;
        }
    }
    return -1; 
}

void decrypt(char ciphertext[], int a, int b) {
    int i;
    char decryptedMessage[100];

    int aInverse = modInverse(a);

    if (aInverse == -1) {
        printf("Invalid value of 'a'. It must be relatively prime to 26.\n");
        return; 
    }

    for (i = 0; ciphertext[i] != '\0'; ++i) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            decryptedMessage[i] = ((aInverse * (ciphertext[i] - 'A' - b + 26)) % 26) + 'A';
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            decryptedMessage[i] = ((aInverse * (ciphertext[i] - 'a' - b + 26)) % 26) + 'a';
        } else {
            decryptedMessage[i] = ciphertext[i];
        }
    }

    decryptedMessage[i] = '\0';

    printf("Decrypted message: %s\n", decryptedMessage);
}

int main() {
    char ciphertext[100];
    int a, b;

    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    
    int mostFrequentPosition = 'B' - 'A';
    int secondMostFrequentPosition = 'U' - 'A';

    
    for (a = 1; a < 26; a++) {
        int aInverse = modInverse(a);

        if (aInverse == -1) {
            continue; 
        }

        
        for (b = 0; b < 26; b++) {
            if ((a * mostFrequentPosition + b) % 26 == secondMostFrequentPosition) {
                
                decrypt(ciphertext, a, b);
                return 0; 
            }
        }
    }

    printf("Unable to break the code with the given information.\n");

    return 0;
}

