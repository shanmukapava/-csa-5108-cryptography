#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key) {
    int i;
    char encryptedMessage[100];

    for (i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encryptedMessage[i] = (message[i] + key - 'a') % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encryptedMessage[i] = (message[i] + key - 'A') % 26 + 'A';
        } else {
            encryptedMessage[i] = message[i];
        }
    }

    encryptedMessage[i] = '\0';

    printf("With key %d: %s\n", key, encryptedMessage);
}

int main() {
    char message[100];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    
    message[strcspn(message, "\n")] = '\0';


    for (int key = 1; key <= 25; ++key) {
        encrypt(message, key);
    }

    return 0;
}

