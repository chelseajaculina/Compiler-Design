/**
 * @author Team Macaroni
 * CMPE 152
 * Assignment 2 - C++ Scanner
 * February 15, 2019
 */
#include "../../cpp/tokens/CppErrorToken.h"

#include "../../Token.h"
#include "../CppToken.h"

namespace wci { namespace frontend { namespace cpp { namespace tokens {

using namespace std;
using namespace wci::frontend::cpp;

CppErrorToken::CppErrorToken(Source *source, CppErrorCode error_code,
                                   string token_text)
    throw (string)
    : CppToken(source)
{
    type = (TokenType) CT_ERROR;
    text = token_text;
    value = new DataValue ((int) error_code);
}

void CppErrorToken::extract() throw (string)
{
    // do nothing
}

}}}}  // namespace wci::frontend::cpp::tokens
