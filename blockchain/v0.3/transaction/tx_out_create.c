#include "transaction.h"

/**
* tx_out_create - creates a transaction output
* @amount: amount of the transaction
* @pub: public key of a transaction receiver
* Return: transaction output
*/
tx_out_t *tx_out_create(uint32_t amount, uint8_t const pub[EC_PUB_LEN])
{
	tx_out_t *tr;

	if (!pub)
		return (NULL);
	tr = calloc(1, sizeof(*tr));
	if (!tr)
		return (NULL);
	tr->amount = amount;
	memcpy(tr->pub, pub, EC_PUB_LEN);
	if (!sha256((const int8_t *)tr, TX_OUT_HASH_LEN, tr->hash))
	{
		free(tr);
		return (NULL);
	}
	return (tr);
}
