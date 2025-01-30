#include "utils.h"
#include "vernam_cipher.h"

#include <iostream>
#include <bitset> 

void ShowMenu() {
  std::cout << BOLD << YELLOW << "============================\n";
  std::cout << " VERNAM CIPHER\n";
  std::cout << "============================\n" << RESET;
  std::cout << BOLD << BLUE << "1. Encrypt a message\n";
  std::cout << "2. Decrypt a message\n";
  std::cout << "3. Help\n";
  std::cout << RED << "0. Exit\n";
  std::cout << YELLOW << "============================\n" << RESET;
  std::cout << "Choose an option: ";
}

void ShowHelp(){
  system(CLEAR_SCREEN);
  std::cout << BOLD << BLUE << "============================\n";
  std::cout << " HELP\n";
  std::cout << "============================\n" << RESET;
  std::cout << "Vernam cipher is a symmetric key encryption algorithm.\n";
  std::cout << "It uses a key that is as long as the message to encrypt.\n";
  std::cout << "The key is generated randomly and must be shared between\n";
  std::cout << "the sender and the receiver.\n";
  std::cout << BOLD << "-----------------------------\n" << RESET;
  std::cout << "This program allows you to encrypt and decrypt messages\n";
  std::cout << "using the Vernam cipher algorithm.\n";
  std::cout << BLUE << "============================\n" << RESET;
  std::cout << "Press ENTER to continue...";
  std::cin.get();
  system(CLEAR_SCREEN);
}

char BinToChar(const std::string& binary) {
  return static_cast<char>(std::stoi(binary, nullptr, 2));
}

void ProcessEncryption() {
  system(CLEAR_SCREEN);
  std::string message, key, binary_message;
  
  std::cout << BOLD << "Enter the message: " << RESET;
  std::getline(std::cin, message);

  binary_message = StringToBinary(message);
  std::cout << GREEN << "Original message (binary): " << RESET << binary_message << std::endl;
  std::cout << "Original message (binary) length: " << binary_message.size() << "\n\n";

  std::cout << "Generate random key? (y/n): ";
  char key_option;
  std::cin >> key_option;
  std::cin.ignore();

  if (key_option == 'y' || key_option == 'Y') {
    key = VernamCipher::GenerateKey(binary_message.size());
    std::cout << BOLD << "Generated Key: " << RESET << key << "\n";
  } else {
    std::cout << "Enter the key (binary): ";
    std::getline(std::cin, key);
  }

  std::string encrypted_binary = VernamCipher::Encrypt(binary_message, key);
  std::cout << std::endl << BLUE << "Cipher text (Binary): " << RESET << encrypted_binary << std::endl;
  std::cout << BOLD << "Cipher text (Text): " << RESET << BinaryToString(encrypted_binary) << std::endl;
}

void ProcessDecryption() {
  system(CLEAR_SCREEN);
  std::string encrypted_message, key, binary_encrypted_message;
  
  std::cout << BOLD << "Enter the cipher text: " << RESET;
  std::getline(std::cin, encrypted_message);

  binary_encrypted_message = StringToBinary(encrypted_message);
  std::cout << RED << "Cipher text (binary): " << RESET << binary_encrypted_message << std::endl;
  std::cout << "Cipher text (binary) length: " << binary_encrypted_message.size() << "\n\n";

  std::cout << "Enter the key: ";
  std::getline(std::cin, key);

  std::string decrypted_binary = VernamCipher::Decrypt(binary_encrypted_message, key);
  std::cout << GREEN << "Decrypted message (binary): " << RESET << decrypted_binary << std::endl;
  std::cout << BOLD << "Decrypted message (Text): " << RESET << BinaryToString(decrypted_binary) << std::endl;
}

void PrintBinary(const std::string& text) {
  for (char character : text) {
    std::cout << std::bitset<8>(character);
  }
  std::cout << std::endl;
}

std::string StringToBinary(const std::string& text) {
  std::string binary;
  for (char character : text) {
    binary += std::bitset<8>(character).to_string();
  }
  return binary;
}

std::string BinaryToString(const std::string& binary) {
  std::string text;
  for (size_t i = 0; i < binary.size(); i += 8) {
    std::string byte = binary.substr(i, 8);
    text += static_cast<char>(std::stoi(byte, nullptr, 2));
  }
  return text;
}