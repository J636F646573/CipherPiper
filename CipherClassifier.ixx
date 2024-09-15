//
// Created by jeben on 9/15/24.
//

export module CipherClassifier;
import <map>;
import <string>;
import <vector>;

namespace Cipher
{
    export enum class CipherType
    {
        caesar,
        vigenere,
        substitution
    };

    export class CClassifier
    {
    public:
        CipherType ClassifyCipher(std::string& cipherText)
        {
            for (char& it : cipherText)
            {
                if (std::find(_testedChars.begin(),
                              _testedChars.end(),
                              static_cast<char>(std::tolower(it))) == _testedChars.end()
                    && IsLetter(it))
                {
                    _testedChars.push_back(static_cast<char>(std::tolower(it)));
                    double freq = FindFrequency(it, cipherText);
                }
            }

            return CipherType::caesar;
        }

        CClassifier() = default;
        virtual ~CClassifier() = default;

    private:
        static double FindFrequency(const char& character, std::string& cipherText)
        {
            int total = 0;
            int count = 0;
            for (const char& it : cipherText)
            {
                if (it == character)
                {
                    count++;
                }
                total++;
            }

            return static_cast<double>(count) / static_cast<double>(total);
        }

        static bool IsLetter(const char& character)
        {
            return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
        }

        std::vector<char> _testedChars;
    };
}
