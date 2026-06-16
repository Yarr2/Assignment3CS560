
#include "pch.h"
#include <iostream>
#include <string>
#include "Cipher.h"
#include "CeaserCipher.h"


CeaserCipher::CeaserCipher(int key_) {
	key = ((key_ % 26) + 26) % 26;
}
CeaserCipher::~CeaserCipher() {}
std::string CeaserCipher::encrypt(const std::string& text){
	std::string encrypted_text = "";
	for (unsigned char character : text) {
		if (std::isalpha(character)) {
			int lower = std::islower(character);
			character += key;
			if (lower == 0) {
				while (!std::isalpha(character) || std::islower(character) != 0) {
					character -= 26;
				}
			}
			else {
				while (!std::isalpha(character) || std::islower(character) == 0) {
					character -= 26;
				}
			}
			
		}
		encrypted_text += character;

	}
	return encrypted_text;
};
std::string CeaserCipher::decrypt(const std::string& text) {
	int decrypt_key = ((-key % 26) + 26) % 26;
	std::string decrypted_text = "";
	for (unsigned char character : text) {
		if (std::isalpha(character)) {
			int lower = std::islower(character);
			character += decrypt_key;
			if (lower == 0) {
				while (!std::isalpha(character) || std::islower(character) != 0) {
					character -= 26;
				}
			}
			else {
				while (!std::isalpha(character) || std::islower(character) == 0) {
					character -= 26;
				}
			}
		}
		decrypted_text += character;
	}
	return decrypted_text;
}