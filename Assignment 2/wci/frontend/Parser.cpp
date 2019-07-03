/**
 * @author Team Macaroni
 * CMPE 152
 * Assignment 2 - C++ Scanner
 * February 15, 2019
 */
#include "Parser.h"
#include "../intermediate/SymTab.h"
#include "../intermediate/ICode.h"
#include "../message/Message.h"
#include "../message/MessageListener.h"

namespace wci { namespace frontend {

Parser::Parser(Scanner *scanner)
    : scanner(scanner), symtab(nullptr), icode(nullptr)
{
}

Parser::~Parser()
{
}

MessageHandler Parser::message_handler;

Scanner *Parser::get_scanner() const { return scanner; }

SymTab *Parser::get_symtab() const { return symtab; }

ICode *Parser::get_icode() const { return icode; }

MessageHandler& Parser::get_message_handler() const
{
    return message_handler;
}

Token *Parser::current_token()
{
    return scanner->current_token();
}

Token *Parser::next_token(Token *prev_token) throw (string)
{
    return scanner->next_token(prev_token);
}

void Parser::add_message_listener(MessageListener *listener)
{
    message_handler.add_listener(listener);
}

void Parser::send_message(Message& message) const
{
    message_handler.send_message(message);
}

}} // namespace wci::frontend

