#include "hblk_crypto.h"

/**
 * ec_verify - a function that verifies the signature
 * @key: points to the EC_KEY
 * @msg:  points to the msg
 * @msglen: is the length of msg
 * @sig: holds the address at which to store the signature
 * Return: int a number 1 or 0 on failure
*/
int ec_verify(EC_KEY const *key, uint8_t const *msg,
size_t msglen, sig_t const *sig)
{
if (!key || !msg || !sig)
return (0);
if (ECDSA_verify(0, msg, (int)msglen,
sig->sig, sig->len, (EC_KEY *)key) < 1)
return (0);
return (1);
}
