#include "pch.h"
#include "XORCipher.h"
#include <format>

XORCipher::XORCipher(std::string key_) 
{
	key = key_;
}
XORCipher::~XORCipher() {}

std::string XORCipher::encrypt(const std::string& text) {
	std::string encrypted_text;
	int counter = -1;
	for (unsigned char character : text) {
		counter++;
		counter %= key.length();
		encrypted_text += std::format("{:02x}", (key[counter] ^ character));
	}
	return encrypted_text;
}
std::string XORCipher::decrypt(const std::string& text) {
	std::string decrypted_text;
	std::string block = "";
	int counter = -1;
	for (unsigned char character : text) {
		block += character;
		if (block.length() != 2) {
			continue;
		}
		counter++;
		counter %= key.length();
		// we have 2 chars, each in "123456789ABCDEF" 2 * char -> uint8 -> unsigned char -> character using ^
		// "AB" -> "A", "B" -> 1010 , 1011 -> 10101011 -> xor -> unsigned char
		std::string hex_numbers = "0123456789abcdef";
		int first_char = 0;
		int second_char = 0;
		for (int i = 0; i < 16; i++) {
			if (block[0] == hex_numbers[i]) {
				first_char = i;
			}
			if (block[1] == hex_numbers[i]) {
				second_char = i;
			}
		}
		int character = (first_char << 4) + second_char;
		character ^= key[counter];
		decrypted_text += character;
		block = "";
	}
	return decrypted_text;

}