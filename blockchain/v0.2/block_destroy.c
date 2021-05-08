#include "blockchain.h"

/**
 * block_destroy - function destroy a block
 *
 * @block: pointer to the block to be destroied
 */
void block_destroy(block_t *block)
{
	if (!block)
		return;
	free(block);
}
