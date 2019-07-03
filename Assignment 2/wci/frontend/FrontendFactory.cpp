/**
 * @author Team Macaroni
 * CMPE 152
 * Assignment 2 - C++ Scanner
 * February 15, 2019
 */
#include <string>
#include "FrontendFactory.h"

#include "cpp/CppParserTD.h"
#include "cpp/CppScanner.h"
#include "Parser.h"
#include "Scanner.h"
#include "Source.h"

namespace wci { namespace frontend {

using namespace wci::frontend::cpp;

Parser *FrontendFactory::create_parser(string language, string type,
                                       Source *source)
    throw (string)
{
    if ((language == "Cpp") && (type == "top-down"))
    {
        Scanner *scanner = new CppScanner(source);
        return new CppParserTD(scanner);
    }
    else if (language != "Cpp") {
        throw new string("Parser factory: Invalid language '" +
                         language + "'");
    }
    else {
        throw new string("Parser factory: Invalid type '" +
                         type + "'");
    }
}


}} // namespace wci::frontend
