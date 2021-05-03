#include "blockchain.h"

/**
* verify_genesis_block - a function that verifies the Genesis block
* @block: block to be verified
* Return: -1 if block is not valid, 0 if block is valid
*/
static int verify_genesis_block(block_t const *block)
{
	blockchain_t *blockchain = blockchain_create();
	int ret = 0;

	if (!blockchain)
		return (-1);
	ret = memcmp(block, llist_get_head(blockchain->chain), sizeof(*block)) != 0;
	blockchain_destroy(blockchain);
	return (ret * -1);
}

/**
* verify_blocks - a function that verifies that a Block is valid
* @block: block to be verified
* @prev_block: previous block
* Return: -1 if block is not valid, 0 if block is valid
*/
static int verify_blocks(block_t const *block, block_t const *prev_block)
{
	uint8_t block_sha[SHA256_DIGEST_LENGTH];
	uint8_t prev_sha[SHA256_DIGEST_LENGTH];

	if (prev_block->info.index != block->info.index - 1)
		return (-1);
	if (!block_hash(prev_block, prev_sha) ||
		memcmp(prev_block->hash, prev_sha, SHA256_DIGEST_LENGTH))
		return (-1);
	if (!block_hash(block, block_sha) ||
		memcmp(block->hash, block_sha, SHA256_DIGEST_LENGTH) ||
		memcmp(block->info.prev_hash, prev_sha, SHA256_DIGEST_LENGTH))
		return (-1);
	if (block->data.len > BLOCKCHAIN_DATA_MAX)
		return (-1);
	return (0);
}

/**
* block_is_valid - a function that verifies that a Block is valid
* @block: block to be verified
* @prev_block: previous block
* Return: -1 if block is not valid, 0 if block is valid
*/
int block_is_valid(block_t const *block, block_t const *prev_block)
{
	if (!block)
		return (-1);
	if (!prev_block)
		return (verify_genesis_block(block));
	return (verify_blocks(block, prev_block));
}
