#include "blockchain.h"

/**
* block_hash - get the hash of a block
* @block: block to be hashed
* @hash_buf: buffer for digest
* Return: hash digest
*/
uint8_t *block_hash(block_t const *block,
uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
size_t len;

len = sizeof(block->info) + block->data.len;
return (sha256((int8_t const *)block, len, hash_buf));
}
