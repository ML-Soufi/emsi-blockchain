#include "blockchain.h"

/**
 * blockchain_serialize - function serializes a Blockchain into a file
 * @blockchain: pointer to blockchain to be serialized
 * @path: the path to a file
 *
 * Return: 0 upon success, -1 upon failure
 */
int blockchain_serialize(blockchain_t const *blockchain, char const *path)
{
	int file, i, length;
	uint8_t endianness = _get_endianness();

	if (!blockchain || !blockchain->chain || !path)
		return (-1);
	length = llist_size(blockchain->chain);
	file = open(path, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
	if (file == -1)
		return (-1);
	if (write(file, HBLK_MAGIC, strlen(HBLK_MAGIC))
		 != strlen(HBLK_MAGIC))
		return (close(file), -1);
	if (write(file, HBLK_VERSION, strlen(HBLK_VERSION))
		!= strlen(HBLK_VERSION))
		return (close(file), -1);
	if (write(file, &endianness, 1) != 1)
		return (close(file), -1);
	if (write(file, &length, 4) != 4)
		return (close(file), -1);
	for (i = 0; i < length; i++)
	{
		block_t *block = llist_get_node_at(blockchain->chain, i);

		if (!block)
			return (close(file), -1);
		if (write(file, &(block->info), sizeof(block->info))
			!= sizeof(block->info))
			return (close(file), -1);
		if (write(file, &(block->data.len), 4) != 4)
			return (close(file), -1);
		if (write(file, block->data.buffer, block->data.len)
			!= block->data.len)
			return (close(file), -1);
		if (write(file, block->hash, SHA256_DIGEST_LENGTH)
			!= SHA256_DIGEST_LENGTH)
			return (close(file), -1);
	}
	return (close(file), 0);
}
