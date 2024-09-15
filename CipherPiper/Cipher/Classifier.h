#pragma once
#include <map>
#include <string>
#include <vector>

namespace Cipher
{
    enum class CipherType
    {
        caesar,
        vigenere,
        substitution
    };

    class CClassifier final
    {
    public:
        CipherType ClassifyCipher(std::string& cipherText);

        CClassifier() = default;
        virtual ~CClassifier() = default;

    private:
        static double FindFrequency(const char& character, std::string& cipherText);
        static bool IsLetter(const char& character);
        static double FindFrequencyError(std::map<char, double> textFrequency);

        std::vector<char> _testedChars;
        std::map<char, double> _frequencyMap;
    };
}
