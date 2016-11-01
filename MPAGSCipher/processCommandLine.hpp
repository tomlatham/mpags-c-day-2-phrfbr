#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include <cstddef>


bool processCommandLine(const std::vector<std::string>& args, bool& helpRequested, bool& versionRequested, std::string& inputFileName, std::string& outputFileName, size_t& key, bool& encrypt, bool& decrypt );


#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
