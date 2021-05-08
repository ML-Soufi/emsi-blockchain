#include "blockchain.h"

/**
 * blockchain_create - function create a new blockchain
 *
 * Return: this function return the created blockchain
 *
*/
blockchain_t *blockchain_create(void)
{
	blockchain_t *blk_ch;
	block_t *blk_genesis;

	blk_ch = calloc(1, sizeof(*blk_ch));
	if (blk_ch == NULL)
		return (NULL);
	blk_genesis = calloc(1, sizeof(*blk_genesis));
	if (blk_genesis == NULL)
	{
		free(blk_ch);
		return (NULL);
	}
	blk_ch->chain = llist_create(MT_SUPPORT_TRUE);
	if (blk_ch->chain == NULL)
	{
		free(blk_ch);
		free(blk_genesis);
		return (NULL);
	}
	blk_genesis->info.index = 0;
	blk_genesis->info.difficulty = 0;
	blk_genesis->info.timestamp = GNS_TIMESTAMP;
	blk_genesis->info.nonce = 0;
	memset(blk_genesis->info.prev_hash, 0, SHA256_DIGEST_LENGTH);
	memcpy(&(blk_genesis->data.buffer), GNS_DATA, GNS_DATA_LEN);
	blk_genesis->data.len = GNS_DATA_LEN;
	memcpy(&(blk_genesis->hash), GNS_HASH, SHA256_DIGEST_LENGTH);
	if (llist_add_node(blk_ch->chain, blk_genesis, ADD_NODE_FRONT) == -1)
	{
		free(blk_genesis);
		llist_destroy(blk_ch->chain, 0, NULL);
		free(blk_ch);
		return (NULL);
	}
	return (blk_ch);
}
