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


#include "Tokenizer.h"


using namespace marklang;
using namespace tokenizer;


// --------------------------- //
// Token class
// --------------------------- //

// Constructor
Token::Token(TokenType type, std::string &token, int linum)
    :type(type), token(token), linum(linum){}

// Destructor
Token::~Token() { } 


// --------------------------- //
// Token class
// --------------------------- //
// Constructor
Tokenizer::Tokenizer() { }


// Destructor
Tokenizer::~Tokenizer() { } 


// Find the type of the incoming character
CharType Tokenizer::findCharType(char c)
{
    if ('0' <= c && c <= '9') {
        return NUMBER_CHAR;
    }
    
    if (('a' <= c && c <= 'z') ||
        ('A' <= c && c <= 'Z')) {
        return ALPHA_CHAR;
    }
    
    if (c == ' ' || c == '\n' ||
        c == '\r' || c == '\t') {
        return EMPTY_CHAR;
    }
    
    if (c == ';') {
        return COMMENT_CHAR;
    }

    if (c == EOF) {
        return END_CHAR;
    }
    
    return SPECIAL_CHAR;
}


// Scan the next character
int Tokenizer::scan(std::istream &file)
{
    std::string buffer;

    int linum = 1;
    char c;
    char next;

    while (file.get(c)) {
        buffer.clear();

        // NAME
        if (findCharType(c) == ALPHA_CHAR || c == '_') {
            buffer += c;
            while(file.get(next)) {
                if (findCharType(next) == ALPHA_CHAR ||
                    findCharType(next) == NUMBER_CHAR ||
                    next == '-' || next == '_' || next == '!' || next == '?') {
                    buffer += next;
                }
                else {
                    break;
                }
            }
            file.putback(next);

            token_stream.push_back(Token(NAME, buffer, linum));
            continue;
        }   

        // NUMBER tokens
        if (findCharType(c) == NUMBER_CHAR) {
            buffer += c;
            while (file.get(next)) {
                if (findCharType(next) == NUMBER_CHAR) {
                    buffer += next;
                }
                else {
                    break;
                }
            }
            file.putback(next);

            token_stream.push_back(Token(INTEGER, buffer, linum));
            continue;
        }

        // COMMENTS
        if (findCharType(c) == COMMENT_CHAR) {
            while (file.get(next)) {
                if (next == '\n' || next == '\r') {
                    break;
                }
            }
            file.putback(next);
            continue;
        }

        // SRTING
        if (c == '"') {
            while (file.get(next)) {
                if (next == '"') {
                    break;
                }
                if (next == '\\') {
                    file.get(next);
                    // Deal with special ASCII chars
                    switch (next)
                    {
                    case 'a': buffer += '\a';
                        break;
                    case 'b': buffer += '\b';
                        break;
                    case 'f': buffer += '\f';
                        break;
                    case 'n': buffer += '\n';
                        break;
                    case 't': buffer += '\t';
                        break;
                    case 'v': buffer += '\v';
                        break;
                    case '\\': buffer += '\\';
                        break;
                    case '"': buffer += '"';
                        break;
                    default: break;
                    }
                }
                else {
                    buffer += next;
                }
            }
            // file.putback(next);
            token_stream.push_back(Token(STRING, buffer, linum));
            continue;
        }
        
        // EMPTY
        if (findCharType(c) == EMPTY_CHAR) {
            if (c == '\n' || c == '\r') {
                linum++;
            }
            while (file.get(next)) {
                if (next == '\n' || c == '\r') {
                    linum++;
                }
                if (findCharType(next) != EMPTY_CHAR) {
                    break;
                }
            }
            file.putback(next);
            continue;
        }

        // SPECIAL
        if (findCharType(c) == SPECIAL_CHAR) {
            buffer += c;
            token_stream.push_back(Token(SPECIAL, buffer, linum));
            continue;
        }
                
    } // while loop
	return 0;
} // Tokenizer::scan 


// Dump token stream for debug
void Tokenizer::dump_tokens()
{
    for (std::vector<Token>::iterator i = token_stream.begin();
         i != token_stream.end();
         ++i) {
        
        std::cout << i->type 
                  << "\t"   
                  << i->token 
                  << "\t"
                  << i->linum
                  << std::endl;
    }
}

