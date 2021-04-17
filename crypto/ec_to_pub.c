#include "hblk_crypto.h"

/**
 * ec_to_pub -  a function that extracts the public key
 * @key: points to the EC_KEY
 * @pub:  is the public key
 * Return: uint8_t* a pointer to digest or null on failure
*/
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
const EC_POINT *ec_point;
const EC_GROUP *group;

if (key == NULL)
return (NULL);

ec_point = EC_KEY_get0_public_key(key);

if (ec_point == NULL)
return (NULL);

group = EC_KEY_get0_group(key);

if (!group)
return (NULL);

if (!EC_POINT_point2oct(group, ec_point,
POINT_CONVERSION_UNCOMPRESSED, pub, EC_PUB_LEN, NULL))
return (NULL);
return (pub);
}
