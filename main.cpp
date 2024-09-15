import <iostream>;
import CipherClassifier;

int main()
{
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    Cipher::CClassifier classifier;
    classifier.ClassifyCipher(input);
    return 0;
}
