#include "Tokenizer.hpp"
#include <algorithm>
#include <cctype>
#include <sstream>

/**
 * Helper function to convert a string to lowercase.
 * 
 * Explanation:
 * We create a copy of the text. We then use std::transform to iterate through
 * the string, calling std::tolower on each character. Casting the character
 * to 'unsigned char' inside the lambda ensures safe behavior with std::tolower,
 * preventing any undefined behavior with negative values or standard EOF.
 */
std::string Tokenizer::toLower(const std::string& text) {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return result;
}

/**
 * Helper function to remove punctuation characters from a string.
 * 
 * Explanation:
 * We use the standard C++ "erase-remove" idiom to modify the string.
 * std::remove_if shifts all characters that are NOT punctuation to the front
 * of the string and returns an iterator to the beginning of the punctuation characters.
 * Then, result.erase removes everything from that iterator to the end of the string.
 */
std::string Tokenizer::removePunctuation(const std::string& text) {
    std::string result = text;
    result.erase(std::remove_if(result.begin(), result.end(), [](unsigned char c) {
        return std::ispunct(c);
    }), result.end());
    return result;
}

/**
 * Tokenizes the input text by converting it to lowercase, removing punctuation,
 * and splitting it into individual words.
 * 
 * Explanation:
 * 1. Normalize the string casing to lowercase to ensure the classifier is case-insensitive.
 * 2. Strip punctuation marks so they do not attach to words (e.g., "hello!" becomes "hello").
 * 3. Use std::stringstream to read words separated by whitespace and add them to a vector.
 */
std::vector<std::string> Tokenizer::tokenize(const std::string& text) {
    // Step 1: Normalize casing
    std::string lowerText = toLower(text);
    
    // Step 2: Remove punctuation
    std::string cleanText = removePunctuation(lowerText);
    
    // Step 3: Split into individual word tokens using stringstream
    std::vector<std::string> tokens;
    std::stringstream ss(cleanText);
    std::string token;
    
    while (ss >> token) {
        tokens.push_back(token);
    }
    
    return tokens;
}
