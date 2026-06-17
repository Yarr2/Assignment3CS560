#pragma once

typedef void* cipher_t;

cipher_t* cipher_create_caesar_dll(int key);
cipher_t* cipher_create_vigenere_dll(const char* key);
cipher_t* cipher_create_xor_dll(const char* key);
char* cipher_encrypt_dll(cipher_t* cipher, const char* text);
char* cipher_decrypt_dll(cipher_t* cipher, const char* text);
void cipher_destroy_dll(cipher_t cipher);
void cipher_free_dll(char* str);