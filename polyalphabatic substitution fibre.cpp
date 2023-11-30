#include <stdio.h>
#include <string.h>

void encrypt(char message[], char key[]) {
    int i, j;
    char encryptedMessage[100];

    for (i = 0, j = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encryptedMessage[i] = 'a' + (message[i] - 'a' + key[j] - 'a') % 26;
            j = (j + 1) % strlen(key);
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encryptedMessage[i] = 'A' + (message[i] - 'A' + key[j] - 'a') % 26;
            j = (j + 1) % strlen(key);
        } else {
            encryptedMessage[i] = message[i];
        }
    }

    encryptedMessage[i] = '\0';

    printf("Encrypted message: %s\n", encryptedMessage);
}

int main() {
    char message[100];
    char key[100];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    
    message[strcspn(message, "\n")] = '\0';

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    key[strcspn(key, "\n")] = '\0';

    encrypt(message, key);

    return 0;
}

