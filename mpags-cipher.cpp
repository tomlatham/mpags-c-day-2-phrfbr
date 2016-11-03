// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Our project Headers
#include "TransformChar.hpp"
#include "processCommandLine.hpp"
#include "runCaeserCipher.hpp"


// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};
  size_t key{5};
  bool useCaesarCipher {false};
  bool encrypt {false};

  bool cmdLineProcessedOK { processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile, key, useCaesarCipher, encrypt ) };

  // If there was a problem processing the command line arguments we should not proceed further
  if ( !cmdLineProcessedOK ) {
    std::cerr << "ERROR: Problem parsing command line arguments" << std::endl;
    return 1;
  }
  

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n"
      << "  -k KEY           Define key to be used in cipher (e.g. -k 5)\n"
      << "                   Note: To minimise errors this should be between 1 and 25\n"
      << "  -caeserencrypt   Encrypt using caeser cipher\n\n"
      << "  -caeserdecrypt   Decrypt using caeser cipher\n\n"
      << "                   NOTE: Can only perform one of either encrypt or decrypt\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  if (!inputFile.empty()) {
    std::ifstream in_file {inputFile};
    bool ok_to_read = in_file.good();
    if (ok_to_read){
      while(in_file >> inputChar)
      {
        inputText += transformChar(inputChar);
      } 
    }
    else {
      std::cout << "ERROR: Infile not ok to write\n" << std::endl; 
    }   
  }

  else {

  // Loop over each character from user input
  // (until Return then CTRL-D (EOF) pressed)
    while(std::cin >> inputChar)
    {
      inputText += transformChar(inputChar);
    } 

  }
  // Output the transliterated text

  // Run Caeser Cipher 
  std::string outputText {""};
  if ( useCaesarCipher ) {
    outputText = runCaesarCipher(inputText, key, encrypt);
  } else {
    outputText = inputText;
  }

  // Warn that output file option not yet implemented
  if (!outputFile.empty()) {
    std::ofstream out_file {outputFile};
    bool ok_to_write = out_file.good();
    if (ok_to_write) {
      out_file << outputText << std::endl;
    }
    else {
      std::cerr << "ERROR: Outfile not ok to write\n" << std::endl;
      std::cout << outputText << std::endl;
    }
  }
  else {
    std::cout << outputText << std::endl;
  }

  


  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;

}



