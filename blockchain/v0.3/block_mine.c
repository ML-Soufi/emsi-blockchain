#include "blockchain.h"

/**
* block_mine - mine block
* @block: block to be mined
*/
void block_mine(block_t *block)
{
	block->info.nonce = 0;
	do {
		++block->info.nonce;
		if (!block_hash(block, block->hash))
			return;
	} while (hash_matches_difficulty(block->hash, block->info.difficulty) == 0);
}
