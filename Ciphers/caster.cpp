#include "pch.h"
#include <iostream>
#include "Cipher.h"
#include "CeaserCipher.h"
#include "VigenereCipher.h"
typedef void* cipher_t;

cipher_t* cipher_create_caesar(int key) {
	return (cipher_t*)(new CeaserCipher(key));
}

cipher_t* cipher_create_vigenere(const char* text) {
	return (cipher_t*)(new VigenereCipher(text));
}   

char* cipher_encrypt(cipher_t* cipher, const char* text) {
	Cipher* temp_cipher = (Cipher*)cipher;
	std::string temp_string = temp_cipher->encrypt(text);
	char* encrypted_text = new char[temp_string.length() + 1];
	std::memcpy(encrypted_text, temp_string.c_str(), temp_string.length() + 1);
	return encrypted_text;
}

char* cipher_decrypt(cipher_t* cipher, const char* text) {
	Cipher* temp_cipher = (Cipher*)cipher;
	std::string temp_string = temp_cipher->decrypt(text);
	char* decrypted_text = new char[temp_string.length() + 1];
	std::memcpy(decrypted_text, temp_string.c_str(), temp_string.length() + 1);
	return decrypted_text;

}
void cipher_destroy(cipher_t* cipher){
	delete cipher;
}

void cipher_free(char* str) {
	free(str);
}