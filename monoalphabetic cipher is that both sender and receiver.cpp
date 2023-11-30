#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to generate the cipher sequence from the keyword
void generateCipherSequence(char keyword[], char cipherSequence[]) {
    int i, j = 0;
    int keywordLength = strlen(keyword);
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Copy the keyword to the beginning of the cipher sequence
    strcpy(cipherSequence, keyword);

    // Fill the remaining characters in the cipher sequence
    for (i = keywordLength; i < 26; i++) {
        if (strchr(keyword, alphabet[i]) == NULL) {
            cipherSequence[j + keywordLength] = alphabet[i];
            j++;
        }
    }

    cipherSequence[26] = '\0';  // Null-terminate the string
}

// Function to perform monoalphabetic encryption
void monoalphabeticEncrypt(char plaintext[], char cipherSequence[], char ciphertext[]) {
    int i;

    // Encrypt each character in the plaintext
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char currentChar = toupper(plaintext[i]);
            int index = currentChar - 'A';
            ciphertext[i] = islower(plaintext[i]) ? tolower(cipherSequence[index]) : cipherSequence[index];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[i] = '\0';  // Null-terminate the string
}

int main() {
    char keyword[] = "CIPHER";
    char cipherSequence[27];
    char plaintext[1000];
    char ciphertext[1000];

    // Generate the cipher sequence from the keyword
    generateCipherSequence(keyword, cipherSequence);

    // Get the plaintext from the user
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove the newline character from the input
    if (strlen(plaintext) > 0 && plaintext[strlen(plaintext) - 1] == '\n') {
        plaintext[strlen(plaintext) - 1] = '\0';
    }

    // Encrypt the plaintext
    monoalphabeticEncrypt(plaintext, cipherSequence, ciphertext);

    // Display the encrypted ciphertext
    printf("Encrypted Ciphertext: %s\n", ciphertext);

    return 0;
}

