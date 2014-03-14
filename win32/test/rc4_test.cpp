
/**
    *** Assembler function ***

    Key: Key
    Plaintext: plaintext
    Ciphertext : 9bf316e8d940af0ad3

    Key: Wiki
    Plaintext: pedia
    Ciphertext : 1021bf0420

    Key: Secret
    Plaintext: Attack at dawn
    Ciphertext : 45a01f645fc35b383552544b9bf5

    *** OpenSSL libraries ***

    Key: Key
    Plaintext: plaintext
    Ciphertext : 9bf316e8d940af0ad3

    Key: Wiki
    Plaintext: pedia
    Ciphertext : 1021bf0420

    Key: Secret
    Plaintext: Attack at dawn
    Ciphertext : 45a01f645fc35b383552544b9bf5
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <openssl/rc4.h>

typedef struct _rc4_key {
  uint32_t x;
  uint32_t y;
  uint8_t s[256];
} RC4_KEY_ASM;

extern "C" void rc4_set_key (RC4_KEY_ASM *rc4key, size_t key_len, void *key);
extern "C" void rc4 (RC4_KEY_ASM *rc4key, size_t data_len, void *data);

void encrypt_asm (void *key, size_t key_len, 
  void* data, size_t data_len)
{
  RC4_KEY_ASM rc4asm;
  uint8_t *t = new uint8_t[data_len];
  memcpy (t, data, data_len);
  
  rc4_set_key (&rc4asm, key_len, key);
  rc4 (&rc4asm, data_len, t);
  printf ("\n\nKey: %s\nPlaintext: %s\nCiphertext : ", key, data);
  for (size_t i=0; i<data_len; i++) { printf ("%02x", t[i]); }
  delete[] t;
}

void encrypt (void *key, size_t key_len, 
  void* data, size_t data_len)
{
  RC4_KEY rc4key;
  uint8_t *t = new uint8_t[data_len];
  
  RC4_set_key (&rc4key, key_len, (uint8_t*)key);
  RC4 (&rc4key, data_len, (uint8_t*)data, t);
  printf ("\n\nKey: %s\nPlaintext: %s\nCiphertext : ", key, data);
  for (size_t i=0; i<data_len; i++) { printf ("%02x", t[i]); }
  delete[] t;
}

int main(void)
{
  char k1[]="Key";
  char p1[]="plaintext";

  char k2[]="Wiki";
  char p2[]="pedia";

  char k3[]="Secret";
  char p3[]="Attack at dawn";
  
  // assembler version
  printf ("\n\n*** Assembler function ***");
  encrypt_asm (k1, strlen(k1), p1, strlen(p1));
  encrypt_asm (k2, strlen(k2), p2, strlen(p2));
  encrypt_asm (k3, strlen(k3), p3, strlen(p3));
  
  // openssl
  printf ("\n\n*** OpenSSL libraries ***");
  encrypt (k1, strlen(k1), p1, strlen(p1));
  encrypt (k2, strlen(k2), p2, strlen(p2));
  encrypt (k3, strlen(k3), p3, strlen(p3));
 
  return 0;
}
