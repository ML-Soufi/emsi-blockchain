#include "hblk_crypto.h"

/**
 * ec_from_pub - a function that creates an EC_KEY
 * @pub: is the public key
 * Return: EC_KEY* a pointer to EC_KEY or null on failure
*/
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN])
{
EC_KEY *ec_key;
EC_POINT *ec_point;
EC_GROUP *group;

if (!pub)
return (NULL);

ec_key = EC_KEY_new_by_curve_name(EC_CURVE);

if (!ec_key)
return (NULL);

group = EC_GROUP_new_by_curve_name(EC_CURVE);

if (!group)
return (NULL);

ec_point = EC_POINT_new(group);

if (!ec_point)
return (NULL);

if (!EC_POINT_oct2point(group, ec_point, pub, EC_PUB_LEN, NULL))
return (NULL);

if (!EC_KEY_set_public_key(ec_key, ec_point))
return (NULL);
return (ec_key);
}
