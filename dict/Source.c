#define __CRTDBG_MAP_ALLOC
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW


#define _CRT_SECURE_NO_WARNINGS
#include "dictionary.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



int main() {
	char a[] = "one";
	int b = 1;
	keyvalue* kv1 = create(a, &b, "int", sizeof(int));
	keyvalue* copy = kv_copy(kv1);
	printf("%d\n", compare(kv1, copy));
	copy->key[0] = 't';
	copy->key[1] = 'w';
	copy->key[2] = 'o';

	dictionary* dictionary = create_dict();
	printf("%d\n\n", compare(kv1, copy));

	print(dictionary);

	add(dictionary, kv1);
	print(dictionary);

	printf("----------------------------------------\n");

	add(dictionary, copy);
	print(dictionary);

	printf("----------------------------------------\n");

	delete_el(dictionary, kv1->key);
	print(dictionary);

	printf("----------------------------------------\n");

	destruction_dict(dictionary);
	print(dictionary);

	printf("----------------------------------------\n");

	return 0;
}
