// vim: noet ts=4 sw=4
#include <stdlib.h>
#include "btree.h"

static btree_node *_btree_new_node() {
	btree_node *new_node = calloc(1, sizeof(btree_node));
	new_node->is_leaf[0] = 1;
	new_node->num_keys = 0;
	return new_node;
}

btree_node *btree_init() {
	btree_node *new_node = _btree_new_node();
	/* TODO: Write initial node to disk. */
	return new_node;
}

void btree_insert(btree_node *root, const char key[MAX_KEY_LEN], const void *value) {
}
