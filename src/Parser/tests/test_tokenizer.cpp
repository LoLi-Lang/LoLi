

#include <iostream>
#include <string>

#include "../Tokenizer.h"

using namespace marklang;
using namespace tokenizer;

int main()
{
    Tokenizer tokenizer;

    tokenizer.scan(std::cin);

    tokenizer.dump_tokens();
}

    
