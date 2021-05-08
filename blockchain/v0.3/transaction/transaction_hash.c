#include "transaction.h"

/**
* tin_to_buffer - copies transaction outputs into buffer
* @tr: transaction node
* @idx: index of @tr
* @buffer: buffer to copy transaction
* Return: 0 on success
*/
int tin_to_buffer(llist_node_t tr, unsigned int idx, void *buffer)
{
	memcpy((int8_t *)buffer + idx * TX_IN_HASH_VAL_LEN, tr, TX_IN_HASH_VAL_LEN);
	return (0);
}

/**
* tout_to_buffer - copies transaction inputs into buffer
* @tr: transaction node
* @idx: index of @tr
* @buffer: buffer to copy transaction
* Return: 0 on success
*/
int tout_to_buffer(llist_node_t tr, unsigned int idx, void *buffer)
{
	memcpy((int8_t *)buffer + idx * TX_OUT_HASH_VAL_LEN,
		   ((tx_out_t *)tr)->hash,
		   TX_OUT_HASH_VAL_LEN);
	return (0);
}

/**
* unspent_tx_out_create - creates a unspent transaction output
* @transaction: points to the unspent transaction output to be converted
* @hash_buf: buffer to store hash of @transaction
* Return: @hash_buf if success, NULL on failure
*/
uint8_t *transaction_hash(transaction_t const *transaction,
						  uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	size_t tin_size, tout_size;
	int8_t *buffer;

	if (!transaction || !hash_buf || llist_size(transaction->inputs) == -1
		|| llist_size(transaction->outputs) == -1)
	{
		return (NULL);
	}
	tin_size = (size_t)llist_size(transaction->inputs) * TX_IN_HASH_VAL_LEN;
	tout_size = (size_t)llist_size(transaction->outputs) * TX_OUT_HASH_VAL_LEN;
	buffer = calloc(1, tin_size + tout_size);
	if (!buffer)
	{
		return (NULL);
	}
	llist_for_each(transaction->inputs, tin_to_buffer, buffer);
	llist_for_each(transaction->outputs, tout_to_buffer, buffer + tin_size);
	sha256(buffer, tin_size + tout_size, hash_buf);
	free(buffer);
	return (hash_buf);
}
