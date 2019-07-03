/**
 * @author Team Macaroni
 * CMPE 152
 * Assignment 2 - C++ Scanner
 * February 15, 2019
 */
#ifndef WCI_FRONTEND_CPP_CPPERRORHANDLER_H_
#define WCI_FRONTEND_CPP_CPPERRORHANDLER_H_

#include "../cpp/CppError.h"
#include "../Token.h"
#include "../Parser.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;
using namespace wci::frontend;

class CppErrorHandler
{
public:
    /**
     * Getter.
     * @return the syntax error count.
     */
    int get_error_count() const;

    /**
     * Flag an error in the source line.
     * @param token the bad token.
     * @param errorCode the error code.
     * @param parser the parser.
     * @return the flagger string.
     */
    void flag(Token *token, CppErrorCode error_code, Parser *parser);

    /**
     * Abort the translation.
     * @param errorCode the error code.
     * @param parser the parser.
     */
    void abort_translation(CppErrorCode error_code, Parser *parser);

private:
    static int error_count;
    static const int MAX_ERRORS;
};

}}}  // namespace wci::frontend::cpp

#endif /* WCI_FRONTEND_CPP_CPPERRORHANDLER_H_ */
