#include "blockchain.h"

/**
* hash_matches_difficulty - checks if hash matches difficulty
* @hash: hash to check
* @difficulty: difficulty of a block
* Return: 1 if hash matches difficulty, otherwise 0
*/
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
							uint32_t difficulty)
{
	uint32_t i, mod;

	/* equal to difficulty % 8 */
	mod = difficulty & 7;
	difficulty -= mod;
	difficulty /= 8;
	for (i = 0; i < difficulty; ++i)
	{
		if (hash[i] != 0)
			return (0);
	}
	if (hash[difficulty] >> (8 - mod))
		return (0);
	return (1);
}
