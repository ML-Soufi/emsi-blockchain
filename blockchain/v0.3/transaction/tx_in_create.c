#include "transaction.h"

/**
* tx_in_create - creates a transaction input
* @unspent: points to the unspent transaction output to be converted
* to a transaction input
* Return: a transaction input
*/
tx_in_t *tx_in_create(unspent_tx_out_t const *unspent)
{
	tx_in_t *tr;

	tr = malloc(sizeof(*tr));
	if (!tr)
		return (NULL);
	memcpy(tr->block_hash, unspent->block_hash, SHA256_DIGEST_LENGTH);
	memcpy(tr->tx_id, unspent->tx_id, SHA256_DIGEST_LENGTH);
	memcpy(tr->tx_out_hash, unspent->out.hash, SHA256_DIGEST_LENGTH);
	memset(&tr->sig, 0, sizeof(tr->sig));
	return (tr);
}
