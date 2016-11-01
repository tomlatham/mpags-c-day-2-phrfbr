#ifndef MPAGSCIPHER_RUNCAESERCIPHER_HPP
#define MPAGSCIPHER_RUNCAESERCIPHER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>

std::string runCaesarCipher( std::string& inputText, const size_t& key, const bool encrypt, const bool decrypt );

#endif // MPAGSCIPHER_RUNCAESERCIPHER_HPP
