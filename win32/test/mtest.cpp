
// for testing modexp32.asm
//
// jwasm -coff -Cp -c modexp32.asm
// cl /I C:\OpenSSL-Win32\include mtest.cpp C:\OpenSSL-Win32\lib\vc\libeay32MT.lib modexp32.obj

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include <openssl/bn.h>
#include <openssl/rand.h>

#define bzero(b, len) (memset((b), '\0', (len)), (void) 0)  
#define bcopy(b1, b2, len) (memmove((b1), (b2), (len)), (void) 0)

extern "C" void __fastcall modexp32(uint32_t bitlen, uint8_t *base, 
    uint8_t *exponent, uint8_t *modulus, uint8_t *result);
                     
int main(int argc, char *argv[])
{
  BIGNUM *b, *e, *m, *c;
  BN_CTX *ctx;
  uint8_t base[256], exponent[256], modulus[256], result[256];
  
  if (argc!=4) { printf ("\nUsage: mtest <base> <exponent> <modulus>\n"); return 0; }
  
  // initialize context
  ctx = BN_CTX_new ();
  BN_CTX_init (ctx);
  
  b  = BN_new ();
  e  = BN_new ();
  m  = BN_new ();
  c  = BN_new ();
  
  BN_dec2bn (&b, argv[1]);
  BN_dec2bn (&e, argv[2]);
  BN_dec2bn (&m, argv[3]);
  
  BN_mod_exp (c, b, e, m, ctx);
  
  printf ("\nBN_mod_exp result = %s", BN_bn2hex (c));
  
  uint32_t maxbits = max ((BN_num_bits(b), BN_num_bits(e)), BN_num_bits(m));
  
  bzero (base,     sizeof (base));
  bzero (exponent, sizeof (exponent));
  bzero (modulus,  sizeof (modulus));
  
  bcopy (base,     &b->d[0], BN_num_bytes (b));
  bcopy (exponent, &e->d[0], BN_num_bytes (e));
  bcopy (modulus,  &m->d[0], BN_num_bytes (m));
  
  // align by 32
  maxbits = (maxbits & -32) + 32;
  
  modexp32 (maxbits, base, exponent, modulus, result);
  printf ("\nmodexp32 result   = ");
  for (int i=BN_num_bytes(m)-1; i>=0; --i) printf ("%02X", result[i]);
  putchar ('\n');
  
  BN_free (c);
  BN_free (m);
  BN_free (e);
  BN_free (b);
  
  // release context
  BN_CTX_free (ctx);
  return 0;
}
