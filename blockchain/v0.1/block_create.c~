#include "blockchain.h"
blockchain_t *blockchain_create(void){
int i=0;
char *st =  "Holberton School";
char * blk_hash = "\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf\x2a\x97\xd4\x8d\x0c\x8e\x00\x09\xc8\x17\xf2\xb1\xd3\xd7\xff\x2f\x04\x51\x58\x03";
block_t node ;
block_info_t infoNode;
infoNode.index = 0;
infoNode.difficulty = 0;
infoNode.timestamp = 1537578000;
infoNode.nonce = 0;
for(i=0; i <= 32 ; i++)
{
	infoNode.prev_hash[i] = (uint8_t) 0;
	node.hash[i] = (uint8_t)blk_hash[i];
}
block_data_t dataNode;
for(i=0; i <= 16 ; i++)
	dataNode.buffer[i] = (int8_t) st[i];
dataNode.len = 16;
node.info = infoNode;
node.data = dataNode;

}
   
