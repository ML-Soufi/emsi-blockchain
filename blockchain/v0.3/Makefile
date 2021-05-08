# Crypto functions for Blockchain project

CC = gcc
# CC = clang
CFLAGS = $(LIBS) -Wall -Werror -Wextra -pedantic -ggdb3  -ftrapv -Wconversion -Wunreachable-code --std=gnu90
LIBS = -I. -Itransaction/ -Iprovided/ -I../../crypto -L../../crypto -lhblk_crypto -lllist -lssl -lcrypto -pthread
PROVIDED = provided/_blockchain_print.c provided/_blockchain_destroy.c provided/_endianness.c provided/_print_hex_buffer.c provided/_transaction_print.c

TASK0 = blockchain_create
TASK1 = block_create
TASK2 = block_destroy
TASK3 = blockchain_destroy
TASK4 = block_hash
TASK5 = blockchain_serialize
TASK6 = blockchain_deserialize
TASK7 = block_is_valid
TASK10 = hash_matches_difficulty
TASK11 = block_mine
TASK12 = blockchain_difficulty
TASK13 = tx_out_create
TASK14 = unspent_tx_out_create
TASK15 = tx_in_create
TASK16 = transaction_hash
TASK17 = tx_in_sign
TASK17 = tx_in_sign
TASK18 = transaction_create
TASK19 = transaction_is_valid
TASK20 = coinbase_create
TASK21 = coinbase_is_valid
TASK22 = transaction_destroy


STATIC_LIB = libhblk_blockchain.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TX_SRC = $(wildcard transaction/*.c)
TX_OBJ = $(TX_SRC:.c=.o)

all: $(STATIC_LIB)

$(STATIC_LIB): $(OBJ) $(TX_OBJ)
	ar ru $@ $^
	ranlib $@

$(TASK22): transaction/$(TASK22).c transaction/$(TASK21).c transaction/$(TASK20).c transaction/$(TASK18).c transaction/$(TASK17).c transaction/$(TASK16).c transaction/$(TASK15).c transaction/$(TASK14).c transaction/$(TASK13).c transaction/test/$(TASK22)-main.c provided/_print_hex_buffer.c provided/_transaction_print.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)
$(TASK21): transaction/$(TASK21).c transaction/$(TASK20).c transaction/$(TASK18).c transaction/$(TASK17).c transaction/$(TASK16).c transaction/$(TASK15).c transaction/$(TASK14).c transaction/$(TASK13).c transaction/test/$(TASK21)-main.c provided/_print_hex_buffer.c provided/_transaction_print.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK20): transaction/$(TASK20).c transaction/$(TASK18).c transaction/$(TASK17).c transaction/$(TASK16).c transaction/$(TASK15).c transaction/$(TASK14).c transaction/$(TASK13).c transaction/test/$(TASK20)-main.c provided/_print_hex_buffer.c provided/_transaction_print.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK19): transaction/$(TASK19).c transaction/$(TASK18).c transaction/$(TASK17).c transaction/$(TASK16).c transaction/$(TASK15).c transaction/$(TASK14).c transaction/$(TASK13).c transaction/test/$(TASK19)-main.c provided/_print_hex_buffer.c provided/_transaction_print.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK18): transaction/$(TASK18).c transaction/$(TASK17).c transaction/$(TASK16).c transaction/$(TASK15).c transaction/$(TASK14).c transaction/$(TASK13).c transaction/test/$(TASK18)-main.c provided/_print_hex_buffer.c provided/_transaction_print.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK17): transaction/$(TASK17).c transaction/$(TASK16).c transaction/$(TASK15).c transaction/$(TASK14).c transaction/$(TASK13).c transaction/test/$(TASK17)-main.c provided/_print_hex_buffer.c provided/_transaction_print.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK16): transaction/$(TASK16).c transaction/$(TASK15).c transaction/$(TASK14).c transaction/$(TASK13).c transaction/test/$(TASK16)-main.c provided/_print_hex_buffer.c provided/_transaction_print.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK15): transaction/$(TASK15).c transaction/$(TASK14).c transaction/$(TASK13).c transaction/test/$(TASK15)-main.c provided/_print_hex_buffer.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK14): transaction/$(TASK14).c transaction/$(TASK13).c transaction/test/$(TASK14)-main.c provided/_print_hex_buffer.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK13): transaction/$(TASK13).c transaction/test/$(TASK13)-main.c provided/_print_hex_buffer.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK12): $(TASK12).c test/$(TASK12)-main.c $(TASK11).c $(TASK10).c $(TASK7).c $(TASK4).c $(TASK3).c $(TASK2).c $(TASK1).c $(TASK0).c $(PROVIDED)
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK11): $(TASK11).c test/$(TASK11)-main.c $(TASK10).c $(TASK7).c $(TASK4).c $(TASK3).c $(TASK2).c $(TASK1).c $(TASK0).c $(PROVIDED)
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK10): $(TASK10).c test/$(TASK10)-main.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK7): $(TASK7).c $(TASK6).c $(TASK5).c $(TASK4).c $(TASK3).c $(TASK2).c $(TASK1).c $(TASK0).c test/$(TASK7)-main.c $(PROVIDED)
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK6): $(TASK6).c $(TASK5).c $(TASK4).c $(TASK3).c $(TASK2).c $(TASK1).c $(TASK0).c test/$(TASK6)-main.c $(PROVIDED)
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK5): $(TASK5).c $(TASK4).c $(TASK3).c $(TASK2).c $(TASK1).c $(TASK0).c test/$(TASK5)-main.c $(PROVIDED)
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK4): $(TASK4).c $(TASK3).c $(TASK2).c $(TASK1).c $(TASK0).c test/$(TASK4)-main.c provided/_blockchain_print.c provided/_blockchain_destroy.c transaction/$(TASK22).c transaction/$(TASK21).c transaction/$(TASK20).c transaction/$(TASK18).c transaction/$(TASK17).c transaction/$(TASK16).c transaction/$(TASK15).c transaction/$(TASK14).c transaction/$(TASK13).c transaction/test/$(TASK22)-main.c provided/_print_hex_buffer.c provided/_transaction_print.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK3): $(TASK3).c $(TASK2).c $(TASK1).c $(TASK0).c test/$(TASK3)-main.c provided/_blockchain_print.c provided/_blockchain_destroy.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK2): $(TASK2).c $(TASK1).c $(TASK0).c test/$(TASK2)-main.c provided/_blockchain_print.c provided/_blockchain_destroy.c provided/_print_hex_buffer.c provided/_transaction_print.c provided/_transaction_print_brief.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK1): $(TASK1).c $(TASK2).c  $(TASK0).c test/block_create-main.c provided/_blockchain_print.c blockchain_destroy.c provided/_print_hex_buffer.c provided/_transaction_print.c provided/_transaction_print_brief.c transaction/transaction_destroy.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK0): $(TASK0).c test/blockchain_create-main.c provided/_blockchain_print.c provided/_blockchain_destroy.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

.PHONY: clean, check

clean:
	rm $(OBJ) $(TASK0) $(TASK1) $(TASK2) $(TASK3) $(TASK4) $(TASK5) $(TASK6) $(TASK7)

check:
	betty *.c *.h
