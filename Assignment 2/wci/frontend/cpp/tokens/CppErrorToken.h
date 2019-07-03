/**
 * @author Team Macaroni
 * CMPE 152
 * Assignment 2 - C++ Scanner
 * February 15, 2019
 */
#ifndef WCI_FRONTEND_CPP_TOKENS_CPPERRORTOKEN_H_
#define WCI_FRONTEND_CPP_TOKENS_CPPERRORTOKEN_H_

#include <string>

#include "../CppError.h"
#include "../CppToken.h"

namespace wci { namespace frontend { namespace cpp { namespace tokens {

using namespace std;
using namespace wci::frontend::cpp;

class CppErrorToken : public CppToken
{
public:
    /**
     * Constructor.
     * @param source the source from where to fetch subsequent characters.
     * @param errorCode the error code.
     * @param tokenText the text of the erroneous token.
     * @throw a string message if an error occurred.
     */
	CppErrorToken(Source *source, CppErrorCode error_code,
                     string token_text)
        throw (string);

protected:
    /**
     * Do nothing.  Do not consume any source characters.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};

}}}}  // namespace wci::frontend::cpp::tokens

#endif /* WCI_FRONTEND_CPP_TOKENS_CPPERRORTOKEN_H_ */
