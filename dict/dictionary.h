#pragma once
#include <stdbool.h>
#include <string.h>


typedef struct keyvalue {
	char* key;
	void* value;
	char* type;
	size_t size;
}keyvalue;

typedef struct dictionary {
	struct keyvalue** dic;
	int size;
}dictionary;


dictionary* create_dict();

void destruction_dict(dictionary* str);

keyvalue* create(char* key, void* value, const char* type, size_t size);

void destruction(keyvalue* arr);

keyvalue* kv_copy(keyvalue* arr);

void add(dictionary* dict, keyvalue* arr);

int compare(keyvalue* str1, keyvalue* str2);

void print(dictionary* dict);

keyvalue* search(dictionary* strd, const char* key);

void delete_el(dictionary* dict, const char* key);

#pragma once