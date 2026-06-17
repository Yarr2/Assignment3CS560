#include "Imports.h"
#include <windows.h>
#include <iostream>


cipher_t* cipher_create_caesar_dll(int key) {
	typedef cipher_t* (*create_cipher_t)(int);

	HMODULE cipherLib = LoadLibrary(L"Ciphers.dll");
	if (cipherLib == NULL) {
		printf("Failed to load library\n");
		return NULL;
	}
	create_cipher_t cipher_create_caesar = (create_cipher_t)GetProcAddress(cipherLib, "cipher_create_caesar");
	if (cipher_create_caesar == NULL) {
		printf("Failed to find function 'cipher_create_caesar' \n");
		FreeLibrary(cipherLib);
		return NULL;
	}
	cipher_t* cipher = cipher_create_caesar(key);


	FreeLibrary(cipherLib);
	return cipher;

}
cipher_t* cipher_create_vigenere_dll(const char* key) {
	typedef cipher_t* (*create_cipher_t)(const char* key);

	HMODULE cipherLib = LoadLibrary(L"Ciphers.dll");
	if (cipherLib == NULL) {
		printf("Failed to load library\n");
		return NULL;
	}
	create_cipher_t cipher_create_vigenere = (create_cipher_t)GetProcAddress(cipherLib, "cipher_create_vigenere");
	if (cipher_create_vigenere == NULL) {
		printf("Failed to find function 'cipher_create_vigenere' \n");
		FreeLibrary(cipherLib);
		return NULL;
	}
	cipher_t* cipher = cipher_create_vigenere(key);


	FreeLibrary(cipherLib);
	return cipher;

}
cipher_t* cipher_create_xor_dll(const char* key) {
	typedef cipher_t* (*create_cipher_t)(const char*);

	HMODULE cipherLib = LoadLibrary(L"Ciphers.dll");
	if (cipherLib == NULL) {
		printf("Failed to load library\n");
		return NULL;
	}
	create_cipher_t cipher_create_xor = (create_cipher_t)GetProcAddress(cipherLib, "cipher_create_xor");
	if (cipher_create_xor == NULL) {
		printf("Failed to find function 'cipher_create_xor' \n");
		FreeLibrary(cipherLib);
		return NULL;
	}
	cipher_t* cipher = cipher_create_xor(key);


	FreeLibrary(cipherLib);
	return cipher;

}

char* cipher_encrypt_dll(cipher_t* cipher, const char* text) {
	typedef char* (*cipher_transform)(cipher_t*, const char*);

	HMODULE cipherLib = LoadLibrary(L"Ciphers.dll");
	if (cipherLib == NULL) {
		printf("Failed to load library\n");
		return NULL;
	}
	cipher_transform cipher_encrypt = (cipher_transform)GetProcAddress(cipherLib, "cipher_encrypt");
	if (cipher_encrypt == NULL) {
		printf("Failed to find function 'cipher_encrypt' \n");
		FreeLibrary(cipherLib);
		return NULL;
	}
	char* encrypted_text = cipher_encrypt(cipher, text);


	FreeLibrary(cipherLib);
	return encrypted_text;

}
char* cipher_decrypt_dll(cipher_t* cipher, const char* text) {
	typedef char* (*cipher_transform)(cipher_t*, const char*);

	HMODULE cipherLib = LoadLibrary(L"Ciphers.dll");
	if (cipherLib == NULL) {
		printf("Failed to load library\n");
		return NULL;
	}
	cipher_transform cipher_decrypt = (cipher_transform)GetProcAddress(cipherLib, "cipher_decrypt");
	if (cipher_decrypt == NULL) {
		printf("Failed to find function 'cipher_decrypt' \n");
		FreeLibrary(cipherLib);
		return NULL;
	}
	char* decrypted_text = cipher_decrypt(cipher, text);


	FreeLibrary(cipherLib);
	return decrypted_text;

}
void cipher_destroy_dll(cipher_t cipher) {

	typedef void (*destroy)(cipher_t);

	HMODULE cipherLib = LoadLibrary(L"Ciphers.dll");
	if (cipherLib == NULL) {
		printf("Failed to load library\n");
		return;
	}

	destroy cipher_destroy = (destroy)GetProcAddress(cipherLib, "cipher_destroy");
	
	if (cipher_destroy == NULL) {
		printf("Failed to find function 'cipher_destroy' \n");
		FreeLibrary(cipherLib);
		return;
	}
	cipher_destroy(cipher);


	FreeLibrary(cipherLib);
	return;
}
void cipher_free_dll(char* str) {

	typedef void (*destroy)(char*);

	HMODULE cipherLib = LoadLibrary(L"Ciphers.dll");
	if (cipherLib == NULL) {
		printf("Failed to load library\n");
		return;
	}

	destroy cipher_free = (destroy)GetProcAddress(cipherLib, "cipher_free");

	if (cipher_free == NULL) {
		printf("Failed to find function 'cipher_free' \n");
		FreeLibrary(cipherLib);
		return;
	}
	cipher_free(str);


	FreeLibrary(cipherLib);
	return;

}