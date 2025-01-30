#include "utils.h"
#include "vernam_cipher.h"

#include <iostream>
#include <bitset> 

void ShowMenu() {
  std::cout << "============================\n";
  std::cout << " VERNAM CIPHER\n";
  std::cout << "============================\n";
  std::cout << "1. Encrypt a message\n";
  std::cout << "2. Decrypt a message\n";
  std::cout << "3. Help\n";
  std::cout << "0. Exit\n";
  std::cout << "============================\n";
  std::cout << "Choose an option: ";
}

void ShowHelp(){
  system(CLEAR_SCREEN);
  std::cout << "============================\n";
  std::cout << " HELP\n";
  std::cout << "============================\n";
  std::cout << "Vernam cipher is a symmetric key encryption algorithm.\n";
  std::cout << "It uses a key that is as long as the message to encrypt.\n";
  std::cout << "The key is generated randomly and must be shared between\n";
  std::cout << "the sender and the receiver.\n";
  std::cout << "-----------------------------\n";
  std::cout << "This program allows you to encrypt and decrypt messages\n";
  std::cout << "using the Vernam cipher algorithm.\n";
  std::cout << "============================\n";
  std::cout << "Press ENTER to continue...";
  std::cin.get();
  system(CLEAR_SCREEN);
}

char BinToChar(const std::string& binary) {
  return static_cast<char>(std::stoi(binary, nullptr, 2));
}

void ProcessEncryption() {
  system(CLEAR_SCREEN);
  std::string message, binary_msg, key, binary_key;

  std::cout << "Enter the message: ";
  std::getline(std::cin, message);

  binary_msg = StringToBinary(message);
  std::cout << "Original message (binary): " << binary_msg << std::endl;
  std::cout << "Original message (binary) length: " << binary_msg.size() << std::endl << std::endl;

  std::cout << "Generate random key? (y/n): ";
  char key_option;
  std::cin >> key_option;
  std::cin.ignore();

  if (key_option == 'y' || key_option == 'Y') {
    key = VernamCipher::GenerateKey(binary_msg.size());
    binary_key = key;

    std::cout << std::endl << "Key: " << binary_key << std::endl;
    std::cout << "Key length: " << binary_key.size() << std::endl;
  } else if (key_option == 'n' || key_option == 'N') {
    std::cout << "Enter the key (binary): ";
    std::getline(std::cin, key);
    // Si la key no es binario dar error
    if (key.find_first_not_of("01") != std::string::npos) {
      std::cerr << "ERROR: The key must be a binary number." << std::endl;
      return;
    }
    std::cout << "Key: " << key << std::endl;
    // DEBUG
    // std::cout << "Key length: " << key.size() << std::endl;
  } else {
    std::cerr << "ERROR: Invalid option." << std::endl;
    return;
  }

  std::string cipher_text = VernamCipher::Encrypt(binary_msg, key);
  std::cout << std::endl << "Cipher text (Binary): " << cipher_text << std::endl;
  std::cout << "Cipher text (Text): " << BinaryToString(cipher_text) << std::endl;
}

void ProcessDecryption() {
  system(CLEAR_SCREEN);
  std::string cipher_text, binary_cipher, key, binary_key;
  std::cout << "Enter the cipher text: ";
  std::getline(std::cin, cipher_text);

  binary_cipher = StringToBinary(cipher_text);
  std::cout << "Cipher text (binary): " << binary_cipher << std::endl;
  std::cout << "Cipher text (binary) length: " << binary_cipher.size() << std::endl << std::endl;

  std::cout << "Enter the key (binary): ";
  std::getline(std::cin, key);

  if (key.find_first_not_of("01") != std::string::npos) {
    std::cerr << "ERROR: The key must be a binary number." << std::endl;
    return;
  } else if (key.size() != binary_cipher.size()) {
    std::cerr << "ERROR: The key and the cipher text must have the same length." << std::endl;
    return;
  }

  std::string plain_text = VernamCipher::Decrypt(binary_cipher, key);
  std::cout << std::endl << "Plain text (Binary): " << plain_text << std::endl;
  std::cout << "Plain text (Text): " << BinaryToString(plain_text) << std::endl;
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