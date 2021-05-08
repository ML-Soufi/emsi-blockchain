#include "blockchain.h"

/**
* block_destroy - deletes the block
* @block: block to be deleted
*/
void block_destroy(block_t *block)
{
	llist_destroy(block->transactions, 1, (node_dtor_t)transaction_destroy);
	free(block);
}
