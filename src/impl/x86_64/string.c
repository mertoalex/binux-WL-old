// source: https://gitlab.com/sortie/meaty-skeleton and https://wiki.osdev.org/Meaty_Skeleton
#include "string.h"

int memcmp(const void* aptr, const void* bptr, size_t size) {
	const unsigned char* a = (const unsigned char*) aptr;
	const unsigned char* b = (const unsigned char*) bptr;
	for (size_t i = 0; i < size; i++) {
		if (a[i] < b[i])
			return -1;
		else if (b[i] < a[i])
			return 1;
	}
	return 0;
}

void* memcpy(void* restrict dstptr, const void* restrict srcptr, size_t size) {
	unsigned char* dst = (unsigned char*) dstptr;
	const unsigned char* src = (const unsigned char*) srcptr;
	for (size_t i = 0; i < size; i++)
		dst[i] = src[i];
	return dstptr;
}

void* memmove(void* dstptr, const void* srcptr, size_t size) {
	unsigned char* dst = (unsigned char*) dstptr;
	const unsigned char* src = (const unsigned char*) srcptr;
	if (dst < src) {
		for (size_t i = 0; i < size; i++)
			dst[i] = src[i];
	} else {
		for (size_t i = size; i != 0; i--)
			dst[i-1] = src[i-1];
	}
	return dstptr;
}

void* memset(void* bufptr, int value, size_t size) {
	unsigned char* buf = (unsigned char*) bufptr;
	for (size_t i = 0; i < size; i++)
		buf[i] = (unsigned char) value;
	return bufptr;
}


size_t strlen(const char* str) {
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

/*

void examples(){
	//memory copy
	char* some = "buggy";
	char somethings[strlen(some)];

	memcpy(somethings, some, strlen(some));

	print_str(somethings);

	//memory set

	int hmm = 1;
	char any[16];

	memset(any, hmm, 8);

	print_str(any);

	//memory compare

	char* idkfe = "ad";
	char* idk = "ab";
	int cmp = memcmp(idkfe,idk,strlen(idk));

	if (cmp == 0) print_str(idk);
	if (cmp > 0) print_str("idkfe > idk");
	if (cmp < 0) print_str("idkfe < idk");

	//memory move

	char* string = "damn you nvidia";

	memmove(string+4,string,4);
	memmove(string,"    ",4);
	
	print_str(string);
}
*/