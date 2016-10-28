#ifndef MPAGSCIPHER_RUNCAESERCIPHER_HPP
#define MPAGSCIPHER_RUNCAESERCIPHER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>

std::string runCaesarCipher( const std::string& inputText, const size_t key, const bool encrypt );

#endif // MPAGSCIPHER_RUNCAESERCIPHER_HPP
