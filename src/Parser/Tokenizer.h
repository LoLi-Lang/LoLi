// --*- C++ -*-------------------------------------//
// 
//                 The Loli Language
//
//
// filename: Tokenizer.h
// descript: The tokens definition and tokenizer
//           implementation
// author  : Kevin Hu <hxy9243@gmail.com>
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
    SPECIAL_IDEN,
    SPECIAL_CHAR,
    END_CHAR
};

enum TokenType
{
    NAME,
    NUMBER,
    STRING,
    BOOLEAN,
    LEFTPAREN,
    RIGHTPAREN,
    SINGLEQUOTE,
    ACUTE,
    COMMA,
    DOT,
    // SHARP_LEFTPAREN
    // COMMA_AT
    EMPTY,
    ERRORTOKEN
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
    void scan(std::istream &file);

    // Dump the token stream
    void dump_tokens();

private:
    // find type of character
    CharType findCharType(char c);
};


} // namespace tokenizer
} // namespace marklang
