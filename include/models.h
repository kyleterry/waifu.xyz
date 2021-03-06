// vim: noet ts=4 sw=4
#pragma once
#include <time.h>

#define MAX_IMAGE_FILENAME_SIZE 512
#define MAX_BOARD_NAME_SIZE 16

typedef struct webm {
	char filename[MAX_IMAGE_FILENAME_SIZE];
	char board[MAX_BOARD_NAME_SIZE];
	struct tm created_at;
	size_t size;
} webm;
