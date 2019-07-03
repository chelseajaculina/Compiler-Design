/**
 * @author Team Macaroni
 * CMPE 152
 * Assignment 2 - C++ Scanner
 * February 15, 2019
 */

#include <string>
#include <vector>
#include <map>
#include "CppToken.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;

map<string, CppTokenType> CppToken::RESERVED_WORDS;
map<string, CppTokenType> CppToken::SPECIAL_SYMBOLS;
map<CppTokenType, string> CppToken::SPECIAL_SYMBOL_NAMES;

bool CppToken::INITIALIZED = false;

void CppToken::initialize()
{
    if (INITIALIZED) return;

    vector<string> rw_strings =
    {
		"auto", "break", "case", "char", "class", "const", "continue", "do",
		"double", "else", "enum", "extern", "float", "for", "goto", "if"
		"int", "long", "namespace","operator", "protected", "public", "return", "static", "struct",
		"switch", "template", "this", "throw", "union", "void", "while",

    };

    vector<CppTokenType> rw_keys =
    {
		CppTokenType::AUTO, // change
		CppTokenType::BREAK,
		CppTokenType::CASE,
		CppTokenType::CHAR,
		CppTokenType::CLASS,
		CppTokenType::CONST,
		CppTokenType::CONTINUE,
		CppTokenType::DO,

		CppTokenType::DOUBLE,
		CppTokenType::ELSE,
		CppTokenType::ENUM,
		CppTokenType::EXTERN,// change
		CppTokenType::FLOAT,
		CppTokenType::FOR,
		CppTokenType::GOTO,
		CppTokenType::IF,

		CppTokenType::INT,
		CppTokenType::LONG,
		CppTokenType::NAMESPACE, // change
		CppTokenType::OPERATOR, // change
		CppTokenType::PROTECTED,
		CppTokenType::PUBLIC,
		CppTokenType::RETURN,
		CppTokenType::STATIC,

		CppTokenType::BIT_COMPLEMENT,


		CppTokenType::STRUCT,
		CppTokenType::SWITCH,
		CppTokenType::TEMPLATE,
		CppTokenType::THIS,
		CppTokenType::THROW,
		CppTokenType::UNION,
		CppTokenType::VOID,
		CppTokenType::WHILE
		//CppTokenType:: NAMESPACE
		//CppTokenType:: PUBLIC
    };

    for (int i = 0; i < rw_strings.size(); i++)
    {
        RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
    }

    vector<string> ss_strings =
    {
		"~", "!", "@", "%", "^", "&", "*", "-", "+", "=", "|", "/", ":",
		";", "?", "<", ">", ".", ",", "'", "\"", "(", ")", "[", "]", "{", "}",
		"++", "--", "<<", ">>", "<=", ">=", "+=", "-=", "*=", "/=", "==", "|=",
		"%=", "&=", "^=", "!=", "<<=", ">>=", "||", "&&", "//", "/*", "*/"
    };

    vector<CppTokenType> ss_keys =
    {
		CppTokenType::BIT_COMPLEMENT,
		CppTokenType::NOT,
		CppTokenType::ANNOTATION,
		CppTokenType::MOD,
		CppTokenType::HAT,
		CppTokenType::BIT_AND,

		CppTokenType::MULT,
		CppTokenType::MINUS,
		CppTokenType::PLUS,
		CppTokenType::EQUALS,
		CppTokenType::BIT_INLCUSIVE_OR,
		CppTokenType::SLASH,
		CppTokenType::COLON,

		CppTokenType::SEMICOLON,
		CppTokenType::QUESTION_MARK,
		CppTokenType::LESS_THAN,
		CppTokenType::GREATER_THAN,
		CppTokenType::DOT,
		CppTokenType::COMMA,

		CppTokenType::QUOTE,
		CppTokenType::DOUBLE_QUOTE,
		CppTokenType::LEFT_PAREN,
		CppTokenType::RIGHT_PAREN,
		CppTokenType::LEFT_BRACKET,
		CppTokenType::RIGHT_BRACKET,

		CppTokenType::LEFT_BRACE,
		CppTokenType::RIGHT_BRACE,
		CppTokenType::PLUS_PLUS,
		CppTokenType::MINUS_MINUS,
		CppTokenType::SIGNED_LEFT_SHIFT,

		CppTokenType::SIGNED_RIGHT_SHIFT,
		CppTokenType::LESS_EQUALS,
		CppTokenType::GREATER_EQUALS,
		CppTokenType::PLUS_EQUALS,
		CppTokenType::MINUS_EQUALS,

		CppTokenType::MULT_EQUALS,
		CppTokenType::SLASH_EQUALS,
		CppTokenType::EQUAL_EQUALS,
		CppTokenType::EXCLUSIVE_OR_EQUALS,

		CppTokenType::MOD_EQUALS,
		CppTokenType::AND_EQUALS,
		CppTokenType::INCLUSIVE_OR_EQUALS,
		CppTokenType::NOT_EQUALS,
		CppTokenType::LSHIFT_EQUALS,

		CppTokenType::RSHIFT_EQUALS,
		CppTokenType::LOGIC_OR,
		CppTokenType::LOGIC_AND,
		CppTokenType::SLASH_SLASH,
		CppTokenType::SLASH_STAR,
		CppTokenType::STAR_SLASH
    };

    for (int i = 0; i < ss_strings.size(); i++)
    {
        SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
    }

    vector<string> ss_names =
    {
		"BIT_COMPLEMENT", "NOT", "ANNOTATION", "MOD", "HAT", "BIT_AND",
		"MULT", "MINUS", "PLUS", "EQUALS", "BIT_INLCUSIVE_OR", "SLASH", "COLON",
		"SEMICOLON", "QUESTION_MARK", "LESS_THAN", "GREATER_THAN", "DOT", "COMMA",
		"QUOTE", "DOUBLE_QUOTE", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET",
		"LEFT_BRACE", "RIGHT_BRACE", "PLUS_PLUS", "MINUS_MINUS", "SIGNED_LEFT_SHIFT",
		"SIGNED_RIGHT_SHIFT", "LESS_EQUALS", "GREATER_EQUALS", "PLUS_EQUALS", "MINUS_EQUALS",
		"MULT_EQUALS", "SLASH_EQUALS", "EQUAL_EQUALS", "EXCLUSIVE_OR_EQUALS",
		"MOD_EQUALS", "AND_EQUALS", "INCLUSIVE_OR_EQUALS", "NOT_EQUALS", "LSHIFT_EQUALS",
		"RSHIFT_EQUALS", "LOGIC_OR", "LOGIC_AND", "SLASH_SLASH", "SLASH_STAR", "STAR_SLASH"
    };

    for (int i = 0; i < ss_names.size(); i++)
    {
        SPECIAL_SYMBOL_NAMES[ss_keys[i]] = ss_names[i];
    }

    INITIALIZED = true;
}

CppToken::CppToken(Source *source) throw (string)
    : Token(source)
{
    initialize();
}

}}}  // namespace wci::frontend::Cpp






