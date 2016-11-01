#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include "runCaeserCipher.hpp"

std::string runCaesarCipher( std::string& inputText, const size_t& key, const bool encrypt, const bool decrypt ) {

int j{0};


typedef std::vector<std::string>::size_type size_type;
const size_type inputsize {inputText.size()};

// Create the alphabet container and output string
const std::vector<char> alphabet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

std::string cipherout {""};


// Loop over the input text  
const std::vector<char> elem(inputText.begin(), inputText.end());


	for (unsigned int e=0; e<inputsize; ++e) {

		// Apply the shift (+ve or –ve depending on encrypt/decrypt)
		for (int l=0;l < 26;++l) {

			// For each character find the corresponding position in the alphabet
			if  (elem[e] == alphabet[l]) {

				// Apply the shift (+ve or –ve depending on encrypt/decrypt)
				if (encrypt){
         			j = l + key;

				// to the position, handling correctly potential wrap - around
       	 			j = j % 26;

				// Determine the new character and add it to the output string
         			cipherout += alphabet[j];

         			}

				// Same as above but for decrypting
       				else if (decrypt){
         			j = l - key;
  
         			j = (26 + j) % 26;

         			cipherout += alphabet[j];
         			}

			// If no option is chosen
       			else {
       			cipherout += alphabet[l];
       			}

     			}

   		}

 	}


inputText = cipherout;


// Finally (after the loop), return the output string

return cipherout;

}


