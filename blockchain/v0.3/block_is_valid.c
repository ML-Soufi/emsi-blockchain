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
* verify_transactions - verify each transaction
* @node: current node
* @idx: index of @node
* @all_unspent: list of unspent transactions
* Return: 0 if transaction is valid, 1 otherwise
*/
int verify_transactions(llist_node_t node, unsigned int idx, void *all_unspent)
{
	if (idx == 0)
		return (0);
	if (!transaction_is_valid(node, all_unspent))
		return (1);
	return (0);
}

/**
* verify_blocks - a function that verifies that a Block is valid
* @block: block to be verified
* @prev_block: previous block
* @all_unspent: unspent transactions
* Return: -1 if block is not valid, 0 if block is valid
*/
static int verify_blocks(block_t const *block,
						 block_t const *prev_block, llist_t *all_unspent)
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
	if (llist_size(block->transactions) < 1)
		return (-1);
	if (!coinbase_is_valid(llist_get_head(block->transactions),
						   block->info.index))
		return (-1);
	if (llist_for_each(block->transactions, verify_transactions, all_unspent))
		return (-1);
	return (0);
}

/**
* block_is_valid - a function that verifies that a Block is valid
* @block: block to be verified
* @prev_block: previous block
* @all_unspent: unspent transactions
* Return: -1 if block is not valid, 0 if block is valid
*/
int block_is_valid(block_t const *block, block_t const *prev_block,
				   llist_t *all_unspent)
{
	if (!block)
		return (-1);
	if (hash_matches_difficulty(block->hash, block->info.difficulty) == 0)
		return (-1);
	if (!prev_block)
		return (verify_genesis_block(block));
	return (verify_blocks(block, prev_block, all_unspent));
}
