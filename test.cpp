#include <iostream>
#include <cassert>
#include <iostream>
#include "tokenizer.h"

std::string fileName = "testName.txt";

void test_tokenization(){
    std::vector<std::string> expected = {"Alex", "Mary"};
    assert(tokenizeName(fileName) == expected);
    std::cout << "Tokenizer is able to parse sample" << std::endl;
}