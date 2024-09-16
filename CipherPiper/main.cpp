#include <iostream>
#include "Cipher/Classifier.h"

int main()
{
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    Cipher::CClassifier classifier;
    Cipher::CipherType type = classifier.ClassifyCipher(input);

    std::cout << std::to_string(static_cast<int>(type)) << "\n";

    return 0;
}
