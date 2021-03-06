#include "blockchain.h"

/**
* block_create - creates a new block
* @prev: previous block
* @data: data for a new block
* @data_len: length of @data
* Return: a block
*/
block_t *block_create(block_t const *prev, int8_t const *data,
uint32_t data_len)
{
block_t *new_blk;

if (!prev || !data || !data_len)
return (NULL);
new_blk = calloc(1, sizeof(*new_blk));
if (new_blk == NULL)
return (NULL);

new_blk->info.index = prev->info.index + 1;
new_blk->info.difficulty = 0;
new_blk->info.nonce = 0;
new_blk->info.timestamp = time(NULL);
memcpy(new_blk->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);
memset(new_blk->hash, 0, SHA256_DIGEST_LENGTH);
if (data_len <= BLOCKCHAIN_DATA_MAX)
{
memcpy(&(new_blk->data.buffer), data, data_len);
new_blk->data.len = data_len;
}
else
{
memcpy(&(new_blk->data.buffer), data, BLOCKCHAIN_DATA_MAX);
new_blk->data.len = BLOCKCHAIN_DATA_MAX;
}

return (new_blk);
}
