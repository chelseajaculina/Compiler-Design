/**
 * @author Team Macaroni
 * CMPE 152
 * Assignment 2 - C++ Scanner
 * February 15, 2019
 */
#include "CppCharacterToken.h"

#include <string>
#include "../CppError.h"

namespace wci { namespace frontend { namespace cpp { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::cpp;

CppCharacterToken::CppCharacterToken(Source *source) throw (string)
        : CppToken(source)
{
    extract();
}

void CppCharacterToken::extract() throw (string)
{
    string value_str = "";

    char current_ch = next_char();  // consume initial quote
    text += "'";

    // Replace any whitespace character with a blank.
    if (isspace(current_ch)) current_ch = ' ';

    // Handles single forward slash
    if (current_ch == '\\') {
        text += current_ch;
        value_str += current_ch;
        current_ch = next_char();  // consume character
    }

    // Handles All other characters
    if ((current_ch != '\'') && (current_ch != EOF))
    {
        text += current_ch;
        value_str  += current_ch;
        current_ch = next_char();  // consume character
    }

    // Handles single quote next to single quote
    if (current_ch == '\'' && (peek_char() == '\''))
    {
        text += current_ch;
        value_str  += current_ch;
        current_ch = next_char();  // consume character

        text += current_ch;
        type = (TokenType) CT_CHAR;
        value = new DataValue(value_str);

        next_char(); // consume final quote
    }
    else if (current_ch == '\'')
    {
        next_char();  // consume final quote
        text += '\'';
        type = (TokenType) CT_CHAR;
        value = new DataValue(value_str);
    }
    else
    {
        type = (TokenType) CT_ERROR;
        value = new DataValue((int) UNEXPECTED_EOF);
    }
}

}}}}  // namespace wci::frontend::java::tokens
