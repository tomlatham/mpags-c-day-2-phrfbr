#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>

std::string runCaesarCipher( const std::string& inputText, const size_t key, const bool encrypt ) {


// Create the alphabet container and output string

 typedef std::vector<std::string>::size_type size_type;
 const size_type textSize {inputText.size()};

 const std::vector<std::char> alphabet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

 std::string cipherout {""};

 // Loop over the input text

 for (const auto& elem : inputText) {
   std::cout << elem << "\n";

   for (i=0;i < 26,i++) {


     if  (elem == alphabet[i]) {
  
     int j = i + key;
  
     j = j % 26;

     std::cout << alphabet[j] << std::endl; 

     cipherout += alphabet[j];

     }


 }

 

// For each character find the corresponding position in the alphabet

// Apply the shift (+ve or –ve depending on encrypt/decrypt)

// to the position, handling correctly potential wrap - around

// Determine the new character and add it to the output string



// Finally (after the loop), return the output string

return cipherout;


}

