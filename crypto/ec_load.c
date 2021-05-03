#include "hblk_crypto.h"

/**
 * ec_load -  a function that loads an EC key pair
 * @folder: is is the path to the folder from which to load the keys
 * Return: EC_KEY* a pointer to EC_KEY or null on failure
*/
EC_KEY *ec_load(char const *folder)
{
EC_KEY *mykey = NULL;
char myfile[512] = {0};
FILE *pfile;
struct stat st;
if (!folder)
return (NULL);
if (stat(folder, &st) == -1)
return (NULL);
sprintf(myfile, "./%s/%s", folder, PUB_FILENAME);
pfile = fopen(myfile, "r");
if (!pfile)
return (NULL);
if (!PEM_read_EC_PUBKEY(pfile, &mykey, NULL, NULL))
return (NULL);
fclose(pfile);
sprintf(myfile, "./%s/%s", folder, PRI_FILENAME);
pfile = fopen(myfile, "r");
if (!pfile)
return (NULL);
if (!PEM_read_ECPrivateKey(pfile, &mykey, NULL, NULL))
return (NULL);
fclose(pfile);
return (mykey);
}
