#include <iostream>
#include "Tokenizer.hpp"

int main()
{
    Tokenizer tokenizer;

    std::string message =
        "Congratulations!!! You won FREE Lottery.";

    std::vector<std::string> tokens =
        tokenizer.tokenize(message);

    std::cout << "Tokens:\n";

    for (const auto& word : tokens)
    {
        std::cout << word << std::endl;
    }

    return 0;
}