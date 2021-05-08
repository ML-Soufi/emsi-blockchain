#ifndef HEADER_BLOCKCHAIN
#define HEADER_BLOCKCHAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <llist.h>
#include <stdint.h>
#include <openssl/sha.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include "provided/endianness.h"


#define GNS_DATA "Holberton School"
#define GNS_DATA_LEN 16
#define GNS_HASH "\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf\x2a\x97\xd4\x8d\x0c\x8e\x00\x09\xc8\x17\xf2\xb1\xd3\xd7\xff\x2f\x04\x51\x58\x03"
#define GNS_TIMESTAMP 1537578000
#define HBLK_MAGIC "HBLK"
#define HBLK_VERSION "0.2"
#define CHECK_ENDIAN(x) (endianness ? SWAPENDIAN(x) : (void)0)
#define GNS_BLOCK { \
	{ /* info */ \
		0 /* index */, \
		0, /* difficulty */ \
		1537578000, /* timestamp */ \
		0, /* nonce */ \
		{0} /* prev_hash */ \
	}, \
	{ /* data */ \
		"Holberton School", /* buffer */ \
		16 /* len */ \
	}, \
	"\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf\x2a\x97\xd4\x8d" \
	"\x0c\x8e\x00\x09\xc8\x17\xf2\xb1\xd3\xd7\xff\x2f\x04\x51\x58\x03" \
}
#define DIFFICULTY_ADJUSTMENT_INTERVAL	5
#define BLOCK_GENERATION_INTERVAL	1

/**
 * struct blockchain_s - Blockchain structure
 *
 * @chain: Linked list of pointers to block_t
 */
typedef struct blockchain_s
{
	llist_t     *chain;
} blockchain_t;

/**
 * struct block_info_s - Block info structure
 *
 * @index:      Index of the Block in the Blockchain
 * @difficulty: Difficulty of proof of work (hash leading zero bits)
 * @timestamp:  Time the Block was created at (UNIX timestamp)
 * @nonce:      Salt value used to alter the Block hash
 * @prev_hash:  Hash of the previous Block in the Blockchain
 */
typedef struct block_info_s
{
	uint32_t    index;
	uint32_t    difficulty;
	uint64_t    timestamp;
	uint64_t    nonce;
	uint8_t     prev_hash[SHA256_DIGEST_LENGTH];
} block_info_t;

#define BLOCKCHAIN_DATA_MAX 1024

/**
 * struct block_data_s - Block data
 *
 * @buffer: Data buffer
 * @len:    Data size (in bytes)
 */
typedef struct block_data_s
{
	int8_t      buffer[BLOCKCHAIN_DATA_MAX];
	uint32_t    len;
} block_data_t;

/**
 * struct block_s - Block structure
 *
 * @info: Block info
 * @data: Block data
 * @hash: 256-bit digest of the Block, to ensure authenticity
 */
typedef struct block_s
{
	block_info_t    info; /* This must stay first */
	block_data_t    data; /* This must stay second */
	uint8_t     hash[SHA256_DIGEST_LENGTH];
} block_t;

/**
 * blockchain_create - function create a new blockchain
 *
 * Return: this function return the created blockchain
 *
*/
blockchain_t *blockchain_create(void);
/**
 * block_create - function create a new block and initializes it
 *
 * @prev: pointet to the previous block in the chain
 * @data: the data to be stored in the block
 * @data_len: the length of data
 * Return: the created block
 */
block_t *block_create(block_t const *prev, int8_t const *data,
			 uint32_t data_len);
/**
 * block_destroy - function destroy a block
 *
 * @block: pointer to the block to be destroied
 */
void block_destroy(block_t *block);
/**
 * blockchain_destroy - function destroy a blockchain
 *
 * @blockchain: pointet to the blockchain to be destroied
 */
void blockchain_destroy(blockchain_t *blockchain);
/**
 * block_hash - function compute the block hash
 *
 * @block: the bloch to be hashed
 * @hash_buf: the hash of the block
 * Return: the hash of the block
 */
uint8_t *block_hash(block_t const *block,
		uint8_t hash_buf[SHA256_DIGEST_LENGTH]);
/**
 * blockchain_serialize - function serializes a Blockchain into a file
 * @blockchain: pointer to blockchain to be serialized
 * @path: the path to a file
 *
 * Return: 0 upon success, -1 upon failure
 */
int blockchain_serialize(blockchain_t const *blockchain, char const *path);
/**
 * blockchain_deserialize - deserializes blockchain from file
 * @path: path to file
 * Return: pointer to blockchain
 */
blockchain_t *blockchain_deserialize(char const *path);
/**
 * deserialize_blocks - deserializes blocks from the file
 * @file: open file to save file
 * @size: number of blocks in the file
 * @endianness: if endianess needs switching
 * Return: pointer to list of blocks or NULL
 */
llist_t *deserialize_blocks(int file, uint32_t size, uint8_t endianness);
/**
 * block_is_valid - checks if this and previous block are valid
 * @block: pointer to the block
 * @prev_block: pointer to previous block
 * Return: 0 if valid else 1 if invalid
 */
int block_is_valid(block_t const *block, block_t const *prev_block);
/**
 * hash_matches_difficulty - checks whether a given hash matches
 *                           a given difficulty
 * @hash: hash to check
 * @difficulty: minimum difficulty the hash should match
 * Return: 1 if difficulty is respected or 0 otherwise
 */
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
	uint32_t difficulty);
/**
 * block_mine - a function that mines
 * a Block in order to insert it in the Blockchain
 * it finds a hash for block that matches its difficulty
 * @block: points to the Block to be mined
 *
 * Void
 */
void block_mine(block_t *block);
/**
 * blockchain_difficulty - compute difficulty of the next block in a blockchain
 *
 * @blockchain: pointer to the blockchain to analyze
 *
 * Return: difficulty to be assigned to the next block in @blockchain
 */
uint32_t blockchain_difficulty(blockchain_t const *blockchain);
#endif
