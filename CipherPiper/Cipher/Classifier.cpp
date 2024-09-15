#include "Classifier.h"

#include <algorithm>
#include <ranges>

namespace Cipher
{

    CipherType CClassifier::ClassifyCipher(std::string& cipherText)
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
                _frequencyMap[it] = freq;
            }
        }

        return CipherType::caesar;
    }

    double CClassifier::FindFrequency(const char& character, std::string& cipherText)
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

    bool CClassifier::IsLetter(const char& character)
    {
        return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
    }

    double CClassifier::FindFrequencyError(std::map<char, double> textFrequency)
    {
        std::vector<double> frequencies;
        std::vector<double> errors;
    	//initialize with standard letter frequencies
        static const std::map<char, double> expectedFull =
        {
            {'e', 0.127},
            {'t', 0.091},
            {'a', 0.082},
            {'o', 0.075},
            {'i', 0.07},
            {'n', 0.067},
            {'s', 0.063},
            {'h', 0.061},
            {'r', 0.060},
            {'d', 0.043},
            {'l', 0.04},
            {'c', 0.028},
            {'u', 0.028},
            {'m', 0.024},
            {'w', 0.024},
            {'f', 0.022},
            {'g', 0.02},
            {'y', 0.02},
            {'p', 0.019},
            {'b', 0.015},
            {'v', 0.0098},
            {'k', 0.0077},
            {'x', 0.0015},
            {'j', 0.0015},
            {'q', 0.00095},
            {'z', 0.00074},
        };
        static const std::vector expectedDoubles =
        {
        	0.127,
	        0.091,
	        0.082,
	        0.075,
	        0.07,
	        0.067,
	        0.063,
	        0.061,
	        0.060,
	        0.043,
	        0.04,
	        0.028,
	        0.028,
	        0.024,
	        0.024,
	        0.022,
	        0.02,
	        0.02,
	        0.019,
	        0.015,
	        0.0098,
	        0.0077,
	        0.0015,
	        0.0015,
	        0.00095,
	        0.00074
        };

        for (auto& val : textFrequency | std::views::values)
	    {
            frequencies.push_back(val);
	    }

        std::sort(frequencies.begin(), frequencies.end());

        errors.reserve(26);
        for (int i = 0; i < 26; i++)
        {
            errors.push_back(abs(expectedDoubles[i] - frequencies[i]));
        }

        double final = 0.0;
        for (auto error : errors)
        {
            final += error;
        }

        final = final / 26.0;

        return final;
    }

}
