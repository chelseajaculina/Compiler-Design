/**
 * @author Team Macaroni
 * CMPE 152
 * Assignment 2 - C++ Scanner
 * February 15, 2019
 */
#include "../../cpp/tokens/CppStringToken.h"

#include <string>
#include "../CppError.h"

#include "../../cpp/CppError.h"

namespace wci { namespace frontend { namespace cpp { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::cpp;

CppStringToken::CppStringToken(Source *source) throw (string)
    : CppToken(source)
{
    extract();
}


void CppStringToken::extract() throw (string)
{
    string value_str = "";

    char current_ch = next_char();  // consume initial quote
    text += "\"";

    // Get string characters.
    do
    {
        // Replace any whitespace character with a blank.
        if (isspace(current_ch)) current_ch = ' ';

        // Not the end of string
		if (current_ch == '\\' && peek_char() == '\"')
		{
			text += current_ch;
			value_str  += current_ch;
			current_ch = next_char();  // consume character \

			text += current_ch;
			value_str  += current_ch;
			current_ch = next_char();  // consume character "
		}
        // Grab all other characters
        if ((current_ch != '\"') && (current_ch != EOF))
        {
            text += current_ch;
            value_str  += current_ch;
            current_ch = next_char();  // consume character
        }

        // Quote?  Each pair of adjacent quotes represents a single-quote.
        if (current_ch == '\"')
        {
            while ((current_ch == '\"') && (peek_char() == '\"'))
            {
                text += "\"\"";
                value_str  += current_ch;  // append single-quote
                current_ch = next_char();  // consume pair of quotes
                current_ch = next_char();
            }
        }
    } while ((current_ch != '\"') && (current_ch != Source::END_OF_FILE));


    if (current_ch == '\"')
    {
        next_char();  // consume final quote
        text += '\"';
        type = (TokenType) CT_STRING;
        value = new DataValue(value_str);
    }
    else
    {
        type = (TokenType) CT_ERROR;
        value = new DataValue((int) UNEXPECTED_EOF);
    }
}

}}}}  // namespace wci::frontend::Cpp::tokens

