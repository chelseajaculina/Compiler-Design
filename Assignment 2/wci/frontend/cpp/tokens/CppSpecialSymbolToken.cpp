/**
 * @author Team Macaroni
 * CMPE 152
 * Assignment 2 - C++ Scanner
 * February 15, 2019
 */


#include "../../cpp/tokens/CppSpecialSymbolToken.h"

#include <string>
#include "../CppError.h"

#include "../../cpp/CppError.h"

namespace wci { namespace frontend { namespace cpp { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::cpp;

CppSpecialSymbolToken::CppSpecialSymbolToken(Source *source) throw (string)
    : CppToken(source)
{
    extract();
}

void CppSpecialSymbolToken::extract() throw (string)
{
    char current_ch = current_char();
    bool good_symbol = true;

    text = current_ch;

    switch (current_ch)
    {
        // Single-character special symbols.
        case '~': case '@':
        case ':': case ';': case '?': case '.': case ',':
        case '\'': case '"': case '(': case ')': case '[':  case ']': case '{': case '}':
        {
            next_char();  // consume character
            break;
        }

        // + or ++ or +=
        case '+':
        {
            current_ch = next_char();  // consume '+';

            if (current_ch == '+')
            {
                text += current_ch;
                next_char();  // consume '+'
            }
            else if (current_ch == '=')
            {
            	text += current_ch;
				next_char();  // consume '='
            }

            break;
        }

        // - or -- or -=
        case '-':
        {
            current_ch = next_char();  // consume '-';

            if (current_ch == '-')
            {
                text += current_ch;
                next_char();  // consume '-'
            }
            else if (current_ch == '=')
            {
                text += current_ch;
                next_char();  // consume '='
            }

            break;
        }

        // < or <= or << or <<=
        case '<':
		{
			current_ch = next_char();  // consume '<';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}
			else if (current_ch == '<')
			{
				text += current_ch;
				current_ch = next_char();  // consume '<'

				if (current_ch == '=')
				{
					text += current_ch;
					next_char();  // consume '='
				}
			}

			break;
		}

		// > or >= or >> or >>=
		case '>':
		{
			current_ch = next_char();  // consume '>';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}
			else if (current_ch == '>')
			{
				text += current_ch;
				current_ch = next_char();  // consume '>'

				if (current_ch == '=')
				{
					text += current_ch;
					next_char();  // consume '='
				}
			}

			break;
		}

		// * or *= or */
		case '*':
		{
			current_ch = next_char();  // consume '*';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}
			else if (current_ch == '/')
			{
				text += current_ch;
				next_char();  // consume '/'
			}

			break;
		}

		// / or /= or /* or //
		case '/':
		{
			current_ch = next_char();  // consume '/';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}
			else if (current_ch == '*')
			{
				text += current_ch;
				next_char();  // consume '*'
			}
			else if (current_ch == '/')
			{
				text += current_ch;
				next_char();  // consume '/'
			}

			break;
		}

		// = or ==
		case '=':
		{
			current_ch = next_char();  // consume '=';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}

			break;
		}

		// | or |= or ||
		case '|':
		{
			current_ch = next_char();  // consume '=';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}
			else if (current_ch == '|')
			{
				text += current_ch;
				next_char();  // consume '|'
			}

			break;
		}

		// % or %=
		case '%':
		{
			current_ch = next_char();  // consume '%';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}

			break;
		}

		// & or &= or &&
		case '&':
		{
			current_ch = next_char();  // consume '&';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}
			else if (current_ch == '&')
			{
				text += current_ch;
				next_char();  // consume '&'
			}

			break;
		}

		// ^ or ^=
		case '^':
		{
			current_ch = next_char();  // consume '^';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}

			break;
		}

		// ! or !=
		case '!':
		{
			current_ch = next_char();  // consume '!';

			if (current_ch == '=')
			{
				text += current_ch;
				next_char();  // consume '='
			}

			break;
		}

        default:
        {
            next_char();  // consume bad character
            type = (TokenType) (CT_ERROR);
            value = new DataValue((int) INVALID_CHARACTER);
            good_symbol = false;
        }
    }

    // Set the type if it wasn't an error.
    if (good_symbol) {
        type = (TokenType) (CppToken::SPECIAL_SYMBOLS[text]);
    }
}

}}}}  // namespace wci::frontend::Cpp::tokens




