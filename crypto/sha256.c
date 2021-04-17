#include "hblk_crypto.h"

/**
 * sha256 - computes the hash of a sequence of bytes
 * @s: is the sequence of bytes to be hashed
 * @len:  is the number of bytes to hash in s
 * @digest: is the resulting hash
 * Return: uint8_t* a pointer to digest or null on failure
*/
uint8_t *sha256(int8_t const *s, size_t len,
uint8_t digest[SHA256_DIGEST_LENGTH])
{
if (digest == NULL)
return (NULL);
else
return (SHA256((unsigned char *)s, len, digest));
}

