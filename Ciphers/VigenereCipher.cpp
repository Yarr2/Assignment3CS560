#include "pch.h"
#include <iostream>
#include "Cipher.h"
#include "VigenereCipher.h"

VigenereCipher::VigenereCipher(std::string key_)
{
	key = key_;
};
VigenereCipher::~VigenereCipher(){}
std::string VigenereCipher::encrypt(const std::string& text){
	std::string encrypted_text = "";
	int counter = -1;
	for (unsigned char character : text) {
			
		if (std::isalpha(character)) {

			counter++;
			counter %= key.length();
			int lower = std::islower(character);


			character += std::tolower(key[counter]) - 'a';
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
}
std::string VigenereCipher::decrypt(const std::string& text) {
	std::string decrypted_text = "";
	int counter = -1;
	for (unsigned char character : text) {

		if (std::isalpha(character)) {

			counter++;
			counter %= key.length();
			int lower = std::islower(character);
			character += ((('a' - std::tolower(key[counter])) % 26) + 26) % 26;
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

