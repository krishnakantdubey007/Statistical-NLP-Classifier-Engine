#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <vector>

/**
 * @class Tokenizer
 * @brief A simple, beginner-friendly helper class to clean and split text into tokens (words).
 * 
 * This class is designed to process raw text for a Statistical NLP Classifier.
 * It provides functionality to:
 * 1. Convert text to lowercase for case insensitivity.
 * 2. Remove all punctuation marks.
 * 3. Split the cleaned text into individual word tokens based on whitespace.
 */
class Tokenizer {
public:
    /**
     * @brief Tokenizes the input text by converting it to lowercase, removing punctuation,
     *        and splitting it into individual words.
     * 
     * @param text The input string to tokenize.
     * @return A vector of tokenized strings.
     */
    std::vector<std::string> tokenize(const std::string& text);

private:
    /**
     * @brief Helper function to convert a string to lowercase.
     * 
     * @param text The string to be converted.
     * @return The lowercase version of the string.
     */
    std::string toLower(const std::string& text);

    /**
     * @brief Helper function to remove punctuation characters from a string.
     * 
     * @param text The string to clean.
     * @return The string with all punctuation characters removed.
     */
    std::string removePunctuation(const std::string& text);
};

#endif // TOKENIZER_HPP
