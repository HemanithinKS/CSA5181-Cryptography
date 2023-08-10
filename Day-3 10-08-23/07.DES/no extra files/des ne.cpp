#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/des.h>

int main() {
    DES_cblock key;
    DES_key_schedule schedule;
    unsigned char text[] = "Hello, DES!";
    unsigned char encrypted_text[sizeof(text)];
    unsigned char decrypted_text[sizeof(text)];

    // Set the encryption key
    memset(key, 0, sizeof(DES_cblock)); // For demonstration purposes only
    DES_set_key(&key, &schedule);

    // Encrypt
    DES_ecb_encrypt((const_DES_cblock *)text, encrypted_text, &schedule, DES_ENCRYPT);

    // Decrypt
    DES_ecb_encrypt((const_DES_cblock *)encrypted_text, decrypted_text, &schedule, DES_DECRYPT);

    printf("Original Text: %s\n", text);
    printf("Encrypted Text: ");
    for (int i = 0; i < sizeof(text); i++) {
        printf("%02X", encrypted_text[i]);
    }
    printf("\n");
    printf("Decrypted Text: %s\n", decrypted_text);

    return 0;
}
