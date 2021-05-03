#include "blockchain.h"

/**
 * block_hash - function compute the block hash
 *
 * @block: the bloch to be hashed
 * @hash_buf: the hash of the block
 * Return: the hash of the block
 */
uint8_t *block_hash(block_t const *block,
		uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
SHA256((const unsigned char *)&(block->info),
4 + 4 + 8 + 8 + 32 + block->data.len, hash_buf);
return (hash_buf);
}
