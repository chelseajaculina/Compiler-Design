/**
 * @author Team Macaroni
 * CMPE 152
 * Assignment 2 - C++ Scanner
 * February 15, 2019
 */
#include "../../cpp/tokens/CppWordToken.h"

#include <iostream>
#include <string>
#include <map>
#include "../CppError.h"

#include "../../cpp/CppError.h"

namespace wci { namespace frontend { namespace cpp { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::cpp;

CppWordToken::CppWordToken(Source *source) throw (string)
    : CppToken(source)
{
    extract();
}

/**
 * Extract a Cpp word token from the source.
 * @throws Exception if an error occurred.
 */
void CppWordToken::extract() throw (string)
{
    char current_ch = current_char();

    // Get the word characters (letter or digit). The scanner has
    // already determined that the first character is a letter.
    while (isalnum(current_ch))
    {
        text += current_ch;
        current_ch = next_char();  // consume character
    }

    // Is it a reserved word or an identifier?
    string upper_case(text);

    if (CppToken::RESERVED_WORDS.find(upper_case)
            != CppToken::RESERVED_WORDS.end())
    {
        // Reserved word.
        type = (TokenType) CppToken::RESERVED_WORDS[upper_case];
        transform(upper_case.begin(), upper_case.end(),
				  upper_case.begin(), ::toupper);
        value = new DataValue(upper_case);
    }
    else
    {
        // Identifier.
        type = (TokenType) CT_IDENTIFIER;
    }
}

}}}}  // namespace wci::frontend::Cpp::tokens
