/**
 * @author Team Macaroni
 * CMPE 152
 * Assignment 2 - C++ Scanner
 * February 15, 2019
 */
#include <iostream>

#include "../cpp/CppError.h"
#include "../cpp/tokens/CppErrorToken.h"
#include "../cpp/tokens/CppNumberToken.h"
#include "../cpp/tokens/CppSpecialSymbolToken.h"
#include "../cpp/tokens/CppStringToken.h"
#include "../cpp/tokens/CppWordToken.h"
#include "../Source.h"
#include "CppScanner.h"
#include "CppToken.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::cpp::tokens;

CppScanner::CppScanner(Source *source) : Scanner(source)
{
}

Token *CppScanner::extract_token() throw (string)
{
    skip_white_space();

    Token *token;
    char current_ch = current_char();
    string string_ch = " ";

    string_ch[0] = current_ch;

    // Construct the next token.  The current character determines the
    // token type.
    if (current_ch == Source::END_OF_FILE)
    {
        token = nullptr;
    }
    else if (isalpha(current_ch))
    {
        token = new CppWordToken(source);
    }
    else if (isdigit(current_ch))
    {
        token = new CppNumberToken(source);
    }
    else if (current_ch == '\'')
    {
        token = new CppStringToken(source);
    }
    else if(current_ch == '\"')
        {
            token = new CppStringToken(source);
        }
    else if (CppToken::SPECIAL_SYMBOLS.find(string_ch)
                != CppToken::SPECIAL_SYMBOLS.end())
    {
        token = new CppSpecialSymbolToken(source);
    }
    else
    {
        token = new CppErrorToken(source, INVALID_CHARACTER, string_ch);
        next_char();  // consume character
    }

    return token;
}

void CppScanner::skip_white_space() throw (string)
{
	char current_ch = current_char();
	    bool block_comment_finish = false;

	    while (isspace(current_ch) || (current_ch == '/')) {

	        // Start of a comment?
	        if (current_ch == '/')
	        {
	        	char peek_ch = peek_char();

	        	// One line comment
	        	if (peek_ch == '/')
	        	{
	        		// Consume whole line
	        		do
					{
	        			current_ch = next_char();  // consume comment characters
					} while (current_ch != Source::END_OF_LINE);
	        	}
	        	// Block comment
	        	else if (peek_ch == '*')
	        	{
	        		// Consume /*
	        		current_ch = next_char();
	        		current_ch = next_char();
	        		do
					{
	        			if (block_comment_finish)
						{
	        				// Look for final /
							if (current_ch == '/')
							{
								current_ch = next_char();
								break;
							}
							// check end of block again
							else if (current_ch != '*')
							{
								block_comment_finish = false;
							}
							current_ch = next_char();
						}
	        			// Block comment might be ending
	        			if (current_ch == '*' && !block_comment_finish)
	        			{
	        				block_comment_finish = true;
	        			}
						current_ch = next_char();  // consume comment characters
					} while (current_ch != Source::END_OF_FILE);
	        	}
	        	else
	        	{
	        		// It is not a comment, it is only a single '/'
	        		break;
	        	}
	        }

	        // Not a comment.
	        else current_ch = next_char();  // consume whitespace character
	    }
}

}}} // namespace wci::frontend::cpp
