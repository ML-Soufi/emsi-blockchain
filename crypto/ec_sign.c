#include "hblk_crypto.h"

/**
 * ec_sign - a function that signs a given set of bytes
 * @key: points to the EC_KEY
 * @msg:  points to the msg
 * @msglen: is the length of msg
 * @sig: holds the address at which to store the signature
 * Return: uint8_t* a pointer to digest or null on failure
*/
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg,
size_t msglen, sig_t *sig)
{
uint32_t len = 0;

if (!key || !msg || !msglen)
return (NULL);

memset(sig->sig, 0, sizeof(sig->sig));
if (!ECDSA_sign(0, msg, (int)msglen, sig->sig, &len, (EC_KEY *)key))
{
sig->len = 0;
return (NULL);
}

sig->len = (uint8_t)len;
return (sig->sig);
}
