#include "blockchain.h"

/**
 * blockchain_destroy - function destroy a blockchain
 *
 * @blockchain: pointet to the blockchain to be destroied
 */
void blockchain_destroy(blockchain_t *blockchain)
{
	if (blockchain)
	{
		llist_destroy(blockchain->chain, 1, (node_dtor_t)block_destroy);
		free(blockchain);
	}
}
