#include "blockchain.h"
/**
 * blockchain_deserialize - deserializes blockchain from file
 * @path: path to file
 * Return: pointer to blockchain
 */
blockchain_t *blockchain_deserialize(char const *path)
{
	int file;
	blockchain_t *my_chain = NULL;
	uint8_t endianness;
	char buf[4096] = {0};
	uint32_t size;

	if (!path)
		return (NULL);
	file = open(path, O_RDONLY);
	if (file == -1)
		return (NULL);
	if (read(file, buf, strlen(HBLK_MAGIC)) != strlen(HBLK_MAGIC) ||
	    strcmp(buf, HBLK_MAGIC))
	{
		free(my_chain);
		close(file);
		return (NULL);
	}
	buf[strlen(HBLK_VERSION)] = 0;
	if (read(file, buf, strlen(HBLK_VERSION)) != strlen(HBLK_VERSION) ||
	    strcmp(buf, HBLK_VERSION))
	{
		free(my_chain);
		close(file);
		return (NULL);
	}
	my_chain = calloc(1, sizeof(*my_chain));
	if (!my_chain)
	{
		free(my_chain);
		close(file);
		return (NULL);
	}
	if (read(file, &endianness, 1) != 1)
	{
		free(my_chain);
		close(file);
		return (NULL);
	}
	endianness = endianness != _get_endianness();
	if (read(file, &size, 4) != 4)
	{
		free(my_chain);
		close(file);
		return (NULL);
	}
	CHECK_ENDIAN(size);
	my_chain->chain = deserialize_blocks(file, size, endianness);
	if (!my_chain)
	{
		free(my_chain);
		close(file);
		return (NULL);
	}
	return (close(file), my_chain);
}

/**
 * deserialize_blocks - deserializes blocks from the file
 * @file: open file to save file
 * @size: number of blocks in the file
 * @endianness: if endianess needs switching
 * Return: pointer to list of blocks or NULL
 */
llist_t *deserialize_blocks(int file, uint32_t size, uint8_t endianness)
{
	block_t *my_block;
	llist_t *list = llist_create(MT_SUPPORT_TRUE);
	uint32_t i = 0;

	if (!list)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		my_block = calloc(1, sizeof(*my_block));
		if (!my_block)
		{
			free(my_block);
			llist_destroy(list, 1, NULL);
			return (NULL);
		}
		if (read(file, &(my_block->info), sizeof(my_block->info)) != sizeof(my_block->info))
		{
			free(my_block);
			llist_destroy(list, 1, NULL);
			return (NULL);
		}
		CHECK_ENDIAN(my_block->info.index);
		CHECK_ENDIAN(my_block->info.difficulty);
		CHECK_ENDIAN(my_block->info.timestamp);
		CHECK_ENDIAN(my_block->info.nonce);
		if (read(file, &(my_block->data.len), 4) != 4)
		{
			free(my_block);
			llist_destroy(list, 1, NULL);
			return (NULL);
		}
		CHECK_ENDIAN(my_block->data.len);
		if (read(file, my_block->data.buffer, my_block->data.len) != my_block->data.len)
		{
			free(my_block);
			llist_destroy(list, 1, NULL);
			return (NULL);
		}
		if (read(file, my_block->hash, SHA256_DIGEST_LENGTH) !=
		    SHA256_DIGEST_LENGTH)
		{
			free(my_block);
			llist_destroy(list, 1, NULL);
			return (NULL);
		}
		if (llist_add_node(list, my_block, ADD_NODE_REAR))
		{
			free(my_block);
			llist_destroy(list, 1, NULL);
			return (NULL);
		}
	}
	return (list);
}
