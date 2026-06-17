#pragma once

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif

#ifdef CIPHERS_EXPORTS
#define CIPHERS_API __declspec(dllexport)
#else
#define CIPHERS_API __declspec(dllimport)
#endif

typedef void* cipher_t;
extern "C" CIPHERS_API void testing();
extern "C" CIPHERS_API cipher_t* cipher_create_caesar(int key);
extern "C" CIPHERS_API cipher_t* cipher_create_vigenere(const char* key);
extern "C" CIPHERS_API char* cipher_encrypt(cipher_t* cipher, const char* text);
extern "C" CIPHERS_API char* cipher_decrypt(cipher_t* cipher, const char* text);
extern "C" CIPHERS_API void cipher_destroy(cipher_t cipher);
extern "C" CIPHERS_API void cipher_free(char* str);