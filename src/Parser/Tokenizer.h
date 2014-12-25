// --*- C++ -*-------------------------------------//
// 
//                 The Mark Toy Language
//
//
// filename: Tokenizer.h
// descript: The tokens definition and tokenizer
//           implementation
// author  : Kevin Hu
// email   : hxy9243 AT gmail DOT com
// note: 
//
//-------------------------------------------------//


#include <iostream>
#include <fstream>
#include <string>
#include <vector>


namespace marklang {
namespace tokenizer {

    // --------------------------- //
    // Typedefs and constants
    // --------------------------- //
    enum CharType
    {
        ALPHA_CHAR,
        NUMBER_CHAR,
        EMPTY_CHAR,
        COMMENT_CHAR,
        SPECIAL_CHAR,
        END_CHAR
    };

    enum TokenType
    {
        NAME,
        INTEGER,
        FLOAT,
        STRING,
        EMPTY,
        SPECIAL,
        END
    };
    

    // --------------------------- //
    // Token class
    // --------------------------- //
    class Token
    {
    public:
        // Constructor and Destructor
        Token(TokenType type, std::string &token, int linum);
        ~Token();
        
        TokenType type;
        std::string token;
        int linum;
    };


    // --------------------------- //
    // Tokenizer class
    // --------------------------- //
    class Tokenizer 
    {
    public:
        // The vector containing all tokens
        typedef std::vector<Token> TokenStream_t; 
        TokenStream_t token_stream;

        // Constructor and Destructor
        Tokenizer();
        ~Tokenizer();
        
        // Scan the next character
        int scan(std::istream &file);

        // Dump the token stream
        void dump_tokens();

    private:
        // find type of character
        CharType findCharType(char c);

        // find if character matches 
        bool match(char c);
    };

} // namespace tokenizer
} // namespace marklang
