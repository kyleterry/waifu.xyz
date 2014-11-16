// vim: noet ts=4 sw=4
#pragma once

#define MAX_KEY_LEN 64
/* Picked via rigorous "I liked this number" process: */
#define MAX_CHILDREN_PER_NODE 256

#define PRETEND_BOOL unsigned char

typedef struct btree_node {
	unsigned int num_keys;
	unsigned char children_keys[MAX_CHILDREN_PER_NODE][MAX_KEY_LEN];
	PRETEND_BOOL is_leaf[MAX_CHILDREN_PER_NODE];
	struct btree_node *children[MAX_CHILDREN_PER_NODE];
	const void *value;
} btree_node;

btree_node *btree_init();
void btree_insert(btree_node *root, const char key[MAX_KEY_LEN], const void *value);
void btree_destroy(btree_node *root);
