/**
 * @author Team Macaroni
 * CMPE 152
 * Assignment 2 - C++ Scanner
 * February 15, 2019
 */
#ifndef WCI_FRONTEND_FRONTENDFACTORY_H_
#define WCI_FRONTEND_FRONTENDFACTORY_H_

#include <string>
#include "Parser.h"
#include "Source.h"

namespace wci { namespace frontend {

class FrontendFactory
{
public:
    /**
     * Create a parser.
     * @param language the name of the source language (e.g., "Pascal").
     * @param type the type of parser (e.g., "top-down").
     * @param source the source object.
     * @return the parser.
     * @throws a string message if an error occurred.
     */
    static Parser *create_parser(string language, string type,
                                 Source *source)
        throw (string);
};

}} // namespace wci::frontend

#endif /* WCI_FRONTEND_FRONTENDFACTORY_H_ */
