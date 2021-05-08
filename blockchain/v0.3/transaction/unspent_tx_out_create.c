#include "transaction.h"

/**
* unspent_tx_out_create - creates a unspent transaction output
* @block_hash: Hash of the Block containing the transaction @tx_id
* @tx_id: ID of the transaction containing @out
* @out: Copy of the referenced transaction output
* Return: an unspent transaction output
*/
unspent_tx_out_t *unspent_tx_out_create(uint8_t
										block_hash[SHA256_DIGEST_LENGTH],
										uint8_t tx_id[SHA256_DIGEST_LENGTH],
										tx_out_t const *out)
{
	unspent_tx_out_t *tr;

	tr = malloc(sizeof(*tr));
	if (!tr)
		return (NULL);
	memcpy(tr->block_hash, block_hash, SHA256_DIGEST_LENGTH);
	memcpy(tr->tx_id, tx_id, SHA256_DIGEST_LENGTH);
	memcpy(&tr->out, out, sizeof(*out));
	return (tr);
}
