#include "vector.h"

typedef struct Lexeme
{
	union
	{
		char* identifier;
		char character;
	} value;

	enum 
	{
		LEXEME_IDENTIFIER,
		LEXEME_CHARACTER
	} type;
} Lexeme;

Vector* lex(const char*);  //découpe la chaine de caractère en une liste de lexemes (identifier les identifiants/characteres)
void lexeme_free(Lexeme*);
Lexeme* lexeme_new(char*, int);
