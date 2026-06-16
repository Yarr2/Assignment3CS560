#pragma once
#include "Cipher.h"

class CeaserCipher : Cipher {
private:
	int key;
public:
	CeaserCipher(int key);
	~CeaserCipher();
	std::string encrypt(const std::string& text);
	std::string decrypt(const std::string& text);
};