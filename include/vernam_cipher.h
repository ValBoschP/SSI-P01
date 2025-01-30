#ifndef VERNAM_CIPHER_H
#define VERNAM_CIPHER_H

#include <string>

class VernamCipher {
 public:
  static std::string Encrypt(const std::string& plain_text, const std::string& key);
  static std::string Decrypt(const std::string& cipher_text, const std::string& key);
  static std::string GenerateKey(size_t length);
};

#endif // VERNAM_CIPHER_H