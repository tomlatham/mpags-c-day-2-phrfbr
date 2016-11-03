#include <string>
#include <vector>
#include <cstddef>
#include "runCaeserCipher.hpp"

std::string runCaesarCipher( const std::string& inputText, const size_t key, const bool encrypt )
{

	// Create the alphabet container and output string
	const std::vector<char> alphabet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	typedef std::vector<char>::size_type size_type;
	const size_type alphabetSize { alphabet.size() };

	std::string cipherout {""};

	// Loop over the input text  
	for ( const auto& elem : inputText ) {

		// Apply the shift (+ve or –ve depending on encrypt/decrypt)
		for (size_type l{0}; l < alphabetSize; ++l) {

			// For each character find the corresponding position in the alphabet
			if  (elem == alphabet[l]) {

				size_type j {l};

				// Apply the shift (+ve or –ve depending on encrypt/decrypt)
				if (encrypt){
					// to the position, handling correctly potential wrap - around
					j = (l + key) % alphabetSize;
				}
				// Same as above but for decrypting
				else {
					// to the position, handling correctly potential wrap - around
					j = (l + 26 - key) % 26;
				}

				// Add the new character to the output string
				cipherout += alphabet[j];

				break;
			}

		}

	}

	// Finally (after the loop), return the output string
	return cipherout;
}


