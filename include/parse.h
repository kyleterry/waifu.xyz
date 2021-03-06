// vim: noet ts=4 sw=4
#pragma once
#include "stack.h"
#include "models.h"

typedef struct thread_match {
	char board[MAX_BOARD_NAME_SIZE];
	int thread_num;
} thread_match;

typedef struct post_match {
	char board[MAX_BOARD_NAME_SIZE];
	char filename[32];
	char file_ext[6];
	char post_number[32];
	size_t size;
} post_match;

/* FUCK THE MUTEABLE STATE */
ol_stack *parse_catalog_json(const char *all_json, const char board[MAX_BOARD_NAME_SIZE]);
ol_stack *parse_thread_json(const char *all_json, const thread_match *match);
