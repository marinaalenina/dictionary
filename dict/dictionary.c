#include "dictionary.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>


dictionary* create_dict() {
	dictionary* dict = malloc(sizeof(dictionary));
	dict->dic = NULL;
	dict->size = 0;
	return dict;
}

void destruction_dict(dictionary* str) {
	for (int i = 0; i < str->size; i++) {
		destruction(str->dic[i]);
	}
	str->size = 0;
	free(str->dic);
	free(str);
}

keyvalue* create(char* key, void* value, char* type, size_t size) {
	keyvalue* kv = malloc(sizeof(keyvalue));
	kv->key = _strdup(key);
	kv->value = malloc(size);
	memcpy(kv->value, value, size);
	kv->type = _strdup(type);
	kv->size = size;

	return kv;
}

void destruction(keyvalue* arr) {
	free(arr->key);
	free(arr->value);
	free(arr->type);
	free(arr);
}

keyvalue* kv_copy(keyvalue* arr) {
	return create(arr->key, arr->value, arr->type, arr->size);
}

void add(dictionary* dict, keyvalue* arr) {
	if (dict->size == 0) {
		dict->dic = malloc(sizeof(keyvalue*));
		*(dict->dic) = arr;
		dict->size += 1;
	}
	else {
		dict->dic = realloc(dict->dic, (dict->size + 1) * sizeof(keyvalue*));
		*(dict->dic + dict->size) = arr;
		dict->size += 1;
	}
}

int compare(keyvalue* str1, keyvalue* str2) {
	return !strcmp(str1->key, str2->key);
}

void print(struct dictionary* dict) {
	if (dict->size == 0) {
		printf("Dictionary is empty!\n");
		return;
	}
	for (int i = 0; i < dict->size; i++) {
		if (!strcmp(dict->dic[i]->type, "int")) {
			printf("key = %s; value = %d\n", (char*)(*(dict->dic + i))->key, *(int*)(*(dict->dic + i))->value);
		}
		if (!strcmp(dict->dic[i]->type, "double")) {
			printf("key = %s; value = %f\n", (char*)(*(dict->dic + i))->key, *(double*)(*(dict->dic + i))->value);
		}
		if (!strcmp(dict->dic[i]->type, "float")) {
			printf("key = %s; value = %f\n", (char*)(*(dict->dic + i))->key, *(float*)(*(dict->dic + i))->value);
		}
		if (!strcmp(dict->dic[i]->type, "long int")) {
			printf("key = %s; value = %d\n", (char*)(*(dict->dic + i))->key, *(long int*)(*(dict->dic + i))->value);
		}
		if (!strcmp(dict->dic[i]->type, "long")) {
			printf("key = %s; value = %d\n", (char*)(*(dict->dic + i))->key, *(long*)(*(dict->dic + i))->value);
		}
		if (!strcmp(dict->dic[i]->type, "short")) {
			printf("key = %s; value = %d\n", (char*)(*(dict->dic + i))->key, *(short*)(*(dict->dic + i))->value);
		}
		if (!strcmp(dict->dic[i]->type, "char")) {
			printf("key = %s; value = %c\n", (char*)(*(dict->dic + i))->key, *(char**)(*(dict->dic + i))->value);
		}
	}
}

keyvalue* search(dictionary* strd, const char* key) {
	for (int i = 0; i <= strd->size; i++)
		if (!strcmp(key, strd->dic[i]->key))
			return strd->dic;
	return NULL;
}

void delete_el(dictionary* dict, const char* key) {
	for (int i = 0; i < dict->size; i++) {
		if (!strcmp(dict->dic[i]->key, key)) {
			if (i != dict->size - 1) { 
				dict->dic[i] = kv_copy(dict->dic[dict->size - 1]);
			}
			destruction(dict->dic[dict->size - 1]);
			dict->dic = realloc(dict->dic, (dict->size - 1) * sizeof(keyvalue));
			dict->size--;
		}
	}
}