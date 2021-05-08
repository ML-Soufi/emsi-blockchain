#include "transaction.h"

/**
* coinbase_is_valid - validate coinbase transaction
* @coinbase: transaction to validate
* @block_index: block index where @coinbase is stored
* Return: 1 if valid, 0 if otherwise
*/
int coinbase_is_valid(transaction_t const *coinbase, uint32_t block_index)
{
	uint8_t hash[SHA256_DIGEST_LENGTH];
	tx_in_t *in;
	int i;

	if (!transaction_hash(coinbase, hash)
		|| memcmp(hash, coinbase->id, SHA256_DIGEST_LENGTH))
		return (0);
	if (llist_size(coinbase->inputs) != 1 || llist_size(coinbase->outputs) != 1)
		return (0);
	in = llist_get_head(coinbase->inputs);
	if (!in || in->sig.len
		|| memcmp(in->tx_out_hash, &block_index, sizeof(block_index)))
		return (0);
	for (i = 0; i < SHA256_DIGEST_LENGTH; ++i)
	{
		if (in->block_hash[i] || in->tx_id[i])
			return (0);
	}
	for (i = 0; i < SIG_MAX_LEN; ++i)
	{
		if (in->sig.sig[i])
			return (0);
	}
	return (1);
}
