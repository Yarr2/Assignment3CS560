#pragma once
#include <iostream>
#include "Cipher.h"


class VigenereCipher : Cipher
{
private:
	std::string key;
public:
	VigenereCipher(std::string key_);
	~VigenereCipher();
	std::string encrypt(const std::string& text) override;
	std::string decrypt(const std::string& text) override;
};