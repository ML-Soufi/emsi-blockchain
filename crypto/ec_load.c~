#include "hblk_crypto.h"

/**
 * ec_load -  a function that loads an EC key pair
 * @folder: is is the path to the folder from which to load the keys
 * Return: EC_KEY* a pointer to EC_KEY or null on failure
*/
EC_KEY *ec_load(char const *folder)
{
EC_KEY *ec_key = NULL;
char FL[512] = {0};
FILE *F;
struct stat st;

if (!folder)
return (NULL);

if (stat(folder, &st) == -1)
return (NULL);

sprintf(FL, "./%s/%s", folder, PUB_FILENAME);
F = fopen(FL, "r");

if (!F)
return (NULL);

if (!PEM_read_EC_PUBKEY(F, &ec_key, NULL, NULL))
return (NULL);

fclose(F);
sprintf(FL, "./%s/%s", folder, PRI_FILENAME);
F = fopen(FL, "r");

if (!F)
return (NULL);

if (!PEM_read_ECPrivateKey(F, &ec_key, NULL, NULL))
return (NULL);
fclose(F);
return (ec_key);
}
