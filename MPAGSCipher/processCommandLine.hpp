#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include <cstddef>


bool processCommandLine(const std::vector<std::string>& args, bool& helpRequested, bool& versionRequested, std::string& inputFileName, std::string& outputFileName, size_t& key, bool& useCaesarCipher, bool& encrypt );


#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
