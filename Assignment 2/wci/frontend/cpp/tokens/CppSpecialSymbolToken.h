/**
 * @author Team Macaroni
 * CMPE 152
 * Assignment 2 - C++ Scanner
 * February 15, 2019
 */

#ifndef WCI_FRONTEND_CPP_TOKENS_PASCALSPECIALSYMBOLTOKEN_H_
#define WCI_FRONTEND_CPP_TOKENS_PASCALSPECIALSYMBOLTOKEN_H_

#include <string>

#include "../CppToken.h"

namespace wci { namespace frontend { namespace cpp { namespace tokens {

using namespace std;
using namespace wci::frontend::cpp;

class CppSpecialSymbolToken : public CppToken
{
public:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
	CppSpecialSymbolToken(Source *source) throw (string);

protected:
    /**
     * Extract a Pascal special symbol token from the source.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};

}}}}  // namespace wci::frontend::cpp::tokens

#endif /* WCI_FRONTEND_CPP_TOKENS_PASCALSPECIALSYMBOLTOKEN_H_ */
