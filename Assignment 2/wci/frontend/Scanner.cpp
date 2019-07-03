/**
 * @author Team Macaroni
 * CMPE 152
 * Assignment 2 - C++ Scanner
 * February 15, 2019
 */
#include "Scanner.h"
#include "Source.h"
#include "Token.h"

namespace wci { namespace frontend {

using namespace std;

Scanner::Scanner(Source *source) : source(source), token(nullptr)
{
}

Scanner::~Scanner()
{
}

Token *Scanner::current_token() { return token; }

Token *Scanner::next_token(Token *prev_token) throw (string)
{
    if (prev_token != nullptr) delete prev_token;
    token = extract_token();
    return token;
}

char Scanner::current_char() throw (string)
{
    return source->current_char();
}

char Scanner::next_char() throw (string)
{
    return source->next_char();
}

char Scanner::peek_char() throw (string)
{
	return source->peek_char();
}

}} // namespace wci::frontend
