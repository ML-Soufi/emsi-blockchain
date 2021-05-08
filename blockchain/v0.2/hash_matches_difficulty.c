#include "blockchain.h"
/**
 * compute_difficulty - count the number of leading zero-bits in a hash
 *
 * @hash: hash buffer
 *
 * Return: computed difficulty of hash
 */
static uint32_t compute_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH])
{
	const uint8_t *ptr = hash;
	uint32_t difficulty = 0;
	int i = 0;

	while (ptr < hash + SHA256_DIGEST_LENGTH)
	{
		for (i = 7; i >= 0; i -= 1)
		{
			if ((*ptr >> i) & 1)
				return (difficulty);
			difficulty += 1;
		}
		ptr += 1;
	}
	return (difficulty);
}

/**
 * hash_matches_difficulty - check if a given hash matches a given difficulty
 *
 * @hash: pointer to the hash to check
 * @difficulty: minimum difficulty the hash must match
 *
 * Return: If @difficulty is matched, return 1. Otherwise, return 0.
 */
int hash_matches_difficulty(
	uint8_t const hash[SHA256_DIGEST_LENGTH], uint32_t difficulty)
{
	return (hash ? compute_difficulty(hash) >= difficulty : 0);
}
