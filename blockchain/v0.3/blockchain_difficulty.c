#include "blockchain.h"

/**
* blockchain_difficulty - get new blockchain difficulty
* @blockchain: blockchain
* Return: return new difficulty
*/
uint32_t blockchain_difficulty(blockchain_t const *blockchain)
{
	block_t *last, *prev;
	uint64_t diff, interval;
	uint32_t new_difficulty;

	if (!blockchain)
		return (0);
	last = llist_get_tail(blockchain->chain);
	if (!last)
		return (0);
	if (last->info.index == 0 ||
		last->info.index % DIFFICULTY_ADJUSTMENT_INTERVAL != 0)
	{
		return (last->info.difficulty);
	}
	prev = llist_get_node_at(blockchain->chain,
							 last->info.index + 1 - DIFFICULTY_ADJUSTMENT_INTERVAL);
	if (!prev)
		return (0);
	diff = last->info.timestamp - prev->info.timestamp;
	new_difficulty = last->info.difficulty;
	interval = DIFFICULTY_ADJUSTMENT_INTERVAL * BLOCK_GENERATION_INTERVAL;
	if (diff * 2 < interval)
		++new_difficulty;
	else if (diff > interval * 2)
		new_difficulty = new_difficulty > 0 ? new_difficulty - 1 : 0;
	return (new_difficulty);
}
