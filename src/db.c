// vim: noet ts=4 sw=4
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include "db.h"
#include "sha3api_ref.h"

int hash_image(const char *file_path, char outbuf[128]) {
	int fd = open(file_path, O_RDONLY);
	unsigned char *data_ptr = NULL;

	struct stat st = {0};
	if (stat(file_path, &st) == -1) {
		goto error;
	}

	data_ptr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	unsigned char hash[IMAGE_HASH_SIZE/8] = {0};

	if (Hash(IMAGE_HASH_SIZE, data_ptr, st.st_size, hash) != 0) {
		goto error;
	}

	int j = 0;
	for (j=0; j<(IMAGE_HASH_SIZE/8); j++)
		sprintf(outbuf + (j * 2), "%02X", hash[j]);
	munmap(data_ptr, st.st_size);
	close(fd);

	return 1;
error:
	if (data_ptr != NULL)
		munmap(data_ptr, st.st_size);
	close(fd);
	return 0;
}
