#include "transaction.h"

/**
* coinbase_create - create coinbase transaction
* @receiver: pub key of a receiver
* @block_index: index of block of this transaction
* Return: a new coinbase transaction
*/
transaction_t *coinbase_create(EC_KEY const *receiver, uint32_t block_index)
{
	transaction_t *tr;
	tx_out_t *out;
	tx_in_t *in;
	uint8_t pub[EC_PUB_LEN];

	if (!ec_to_pub(receiver, pub))
		return (NULL);
	out = tx_out_create(COINBASE_AMOUNT, pub);
	if (!out)
		return (NULL);
	in = calloc(1, sizeof(*in));
	if (!in)
		return (free(out), NULL);
	memcpy(in->tx_out_hash, &block_index, sizeof(block_index));
	tr = calloc(1, sizeof(*tr));
	if (!tr)
		return (free(in), free(out), NULL);
	tr->inputs = llist_create(MT_SUPPORT_FALSE);
	tr->outputs = llist_create(MT_SUPPORT_FALSE);
	llist_add_node(tr->inputs, in, ADD_NODE_REAR);
	llist_add_node(tr->outputs, out, ADD_NODE_REAR);
	transaction_hash(tr, tr->id);
	return (tr);
}
