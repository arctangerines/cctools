#ifndef PL_LIST_UTIL
#define PL_LIST_UTIL
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#define READ_ACCESS 0x1
#define WRITE_ACCESS 0x2
#define STAT_ACCESS 0x4
#define CREATE_ACCESS 0x8
#define DELETE_ACCESS 0x16
#define LIST_ACCESS 0x32

/// Singly linked list containing our paths with their permission
/// In a text file Read and Write as true get dumped as +
/// TODO: Change name
struct path_access {
	/// Pathname in absolute form, ideally it should never be relative
	char *pathname;
	/// Flag for read
	bool read;
	/// Flag for write
	bool write;
	/// Flag for stat
	bool stat;
};

/// Add a path_access node to our cctools list
void new_path_access_node(struct list *c,
		char *path,
		uint8_t access_fl);
void destroy_path_node(void *x);
void destroy_contract_list(struct list *c);
struct path_access *
find_path_in_list(struct list *c,
		char *path);
#endif
