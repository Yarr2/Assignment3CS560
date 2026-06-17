#pragma once
#include <iostream>
#include "Cipher.h"
class XORCipher : Cipher
{
private:
	std::string key;
public:
	XORCipher(std::string key);
	~XORCipher();
	std::string encrypt(const std::string& text);
	std::string decrypt(const std::string& text);
};

