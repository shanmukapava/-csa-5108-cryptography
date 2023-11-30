#include <stdio.h>
#include <string.h>

void encrypt(char message[], char key[]) {
    int i;
    char encryptedMessage[100];

    for (i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encryptedMessage[i] = key[message[i] - 'a'];
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encryptedMessage[i] = key[message[i] - 'A'] + 'A' - 'a';
        } else {
            encryptedMessage[i] = message[i];
        }
    }

    encryptedMessage[i] = '\0';

    printf("Encrypted message: %s\n", encryptedMessage);
}

int main() {
    char message[100];
    char key[26]; 

    
    strcpy(key, "zyxwvutsrqponmlkjihgfedcba");

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    
    message[strcspn(message, "\n")] = '\0';

    encrypt(message, key);

    return 0;
}

