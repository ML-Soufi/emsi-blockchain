#include "transaction.h"

/**
* find_identifier - search for a node in llist
* @node: a node in llist
* @hash: hash to match
* Return: 1 if found, 0 if not found
*/
int find_identifier(llist_node_t node, void *hash)
{
	if (!memcmp(((unspent_tx_out_t *)node)->out.hash,
				hash, SHA256_DIGEST_LENGTH))
	{
		return (1);
	}
	return (0);
}

/**
* tx_in_sign - sign transaction
* @in:  points to the transaction input structure to sign
* @tx_id: contains the ID (hash) of the transaction the
* transaction input to sign is stored in
* @sender: contains the private key of the receiver of the coins contained
*  in the transaction output referenced by the transaction input
* @all_unspent: is the list of all unspent transaction outputs to date
* Return: signature or NULL if failed
*/
sig_t *tx_in_sign(tx_in_t *in, uint8_t const tx_id[SHA256_DIGEST_LENGTH],
				  EC_KEY const *sender, llist_t *all_unspent)
{
	uint8_t buffer[EC_PUB_LEN];
	unspent_tx_out_t *unspent;

	if (!in || !tx_id || !sender || !all_unspent)
		return (NULL);
	ec_to_pub(sender, buffer);
	unspent = llist_find_node(all_unspent, find_identifier, in->tx_out_hash);
	if (!unspent)
	{
		return (NULL);
	}
	if (memcmp(unspent->out.pub, buffer, EC_PUB_LEN))
	{
		return (NULL);
	}
	if (!ec_sign(sender, tx_id, SHA256_DIGEST_LENGTH, &in->sig))
	{
		return (NULL);
	}
	return (&in->sig);
}
