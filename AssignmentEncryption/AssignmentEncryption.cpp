// AssignmentEncryption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "Ciphers.h"
#include <string>
#include <windows.h>
#include "Imports.h"

void process_command(int command, cipher_t*& cipher) {

	char* text = new char[100];
	switch (command) {
	case 0:
		printf("Help\n");
		cipher_free_dll(text);
		break;
	case 1:
	{
		printf("Create cipher:\n");
		printf("Choose cipher:\n\n");
		printf("1. Ceaser cipher\n");
		printf("2. Vigener cipher\n");
		printf("3. XOR cipher \n\n");
		printf("Choose your cipher > ");
		int variant = 0;
		std::cin >> variant;
		switch (variant) {
		case 1:
		{
			printf("Input key for Ceaser cipher > ");
			int key = 0;
			std::cin >> key;
			cipher_destroy_dll(cipher);
			cipher = cipher_create_caesar_dll(key);
			break;
		}
		case 2:
		{
			printf("Vigener cipher\n");
			std::string key;
			printf("Enter key for Vigenere cipher > ");
			std::cin >> key;
			cipher_destroy_dll(cipher);
			cipher = cipher_create_vigenere_dll(key.c_str());
			break;
			}
		case 3: {
			printf("XOR cipher\n");
			std::string key;
			printf("Enter key for XOR cipher > ");
			std::cin >> key;
			cipher_destroy_dll(cipher);
			cipher = cipher_create_xor_dll(key.c_str());
		}
		}
		cipher_free_dll(text);
		break;
	}
	case 2:
	{
		if (cipher[0] == NULL) {
			printf("There is no cipher set up\n");
			return;
		}
		printf("Encrypt message\n");
		printf("Message > ");
		std::cin.getline(text, 100);
		char* encrypted_text = cipher_encrypt_dll(cipher, text);
		std::cout << "Encrypted text - " << encrypted_text << "\n";
		cipher_free_dll(encrypted_text);
		break;
	}
	case 3:
	{
		if (cipher[0] == NULL) {
			printf("There is no cipher set up\n");
			return;
		}
		printf("Decrypt message\n");
		printf("Message > ");
		std::cin.getline(text, 100);
		char* decrypted_text = cipher_decrypt_dll(cipher, text);
		std::cout << "Decrypted text - " << decrypted_text << "\n";
		cipher_free_dll(decrypted_text);
		break;
	}
	default:
		printf("There is no such command\n");
		break;
	}
}


int main()
{

	printf("Welcome to our ciphers\n");
	cipher_t* cipher = new cipher_t;
	cipher[0] = NULL;
	while (1) {

		printf("Enter command you want to execute(0 for help) > ");
		int command = -1;
		scanf_s("%d", &command);
		char character;
		scanf_s("%c", &character, 1);
		if (character == 'P') {
			cipher_destroy_dll(cipher);
			printf("Program exited\n");
			return 0;
		}
		while (character != '\n')
		{
			scanf_s("%c", &character, 1);
		}

		process_command(command, cipher);
	}
	cipher_destroy_dll(cipher);
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
