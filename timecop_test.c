#include "rijndael.h"
#include "poison.h"

#define KEYBITS 128


int main() {


    // Example key and plaintext
    unsigned char key[16] = {
        0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
        0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
    };
    unsigned char plaintext[16] = {
        0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d,
        0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34
    };
    
    //poison
    poison(key, sizeof(key));
    poison(plaintext, sizeof(plaintext));

    // Round key for encryption and decryption
    unsigned long rk[RKLENGTH(KEYBITS)];

    // Set up encryption keys
    int nrounds = rijndaelSetupEncrypt(rk, key, KEYBITS);

    // Buffer for ciphertext
    unsigned char ciphertext[16];

    // Encrypt the plaintext
    rijndaelEncrypt(rk, nrounds, plaintext, ciphertext);
    
    // Set up decryption keys
    nrounds = rijndaelSetupDecrypt(rk, key, KEYBITS);
    
    // Buffer for decrypted plaintext
    unsigned char decrypted_plaintext[16];

    // Decrypt the ciphertext
    rijndaelDecrypt(rk, nrounds, ciphertext, decrypted_plaintext);

    //unpoison
    unpoison(key, sizeof(key));
    unpoison(plaintext, sizeof(plaintext));

    
    return 0;

}
