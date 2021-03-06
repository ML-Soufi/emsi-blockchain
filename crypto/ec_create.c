#include "hblk_crypto.h"

/**
 * ec_create - a function that creates a new EC key pair.
 * Return: EC_KEY * a pointer to EC_KEY, or null on failure
*/
EC_KEY *ec_create(void)
{
EC_KEY *ec_key;
ec_key = EC_KEY_new_by_curve_name(EC_CURVE);
if (ec_key == NULL)
	return (NULL);
if (!EC_KEY_generate_key(ec_key))
{
	EC_KEY_free(ec_key);
	return (NULL);
}
return (ec_key);
}
