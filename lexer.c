#include "lexer.h"

enum state
{
	STATE_IDENTIFIER,
	STATE_DELIMITER,
	STATE_NUMBER,
	STATE_SYMBOLS,
	STATE_WHITESPACE
};

static int estDiff(enum state s1, enum state s2)
{
	if (s1 != s2)
		return 0;
	else
		return s1 == STATE_WHITESPACE ||
			s1 == STATE_IDENTIFIER ||
			s1 == STATE_NUMBER;
}

static int get_new_state(const char* c, enum state s)
{
	if (c[0] == ' ' || c[0] == '\n' || c[0] == '\t' || c[0] == '\r')
	{
		return STATE_WHITESPACE;
	}
	else if ( c[0] == '(' || c[0] == ')' || c[0] == ','  || c[0] == ';' )
	{
		return STATE_DELIMITER;
	}
	else if ('0' <= c[0] && c[0] <= '9')
	{
		return s == STATE_IDENTIFIER ? STATE_INDENTIFIER : STATE_NUMBER;
	}
	else
	{
		return STATE_IDENTIFIER;
	}
}

Vector* lex(const char* input)
{
	Vector* lexemes = vector_new();
	enum state s = STATE_WHITESPACE; //Ancien état
	int start = 0;
	enum state new_state;

	for (int i = 0 ; input[i] != '\0' ; i++) //i = offset
	{
		new_state = get_new_state(input + i, s);

		if (estDiff(s, new_state))
		{

			if (s != STATE_WHITESPACE)
			{
				vector_push(lexemes, lexeme_new(input + start, i - start));
			}
			start = i;
			s = new_state;
		}
	}

	return lexemes;
}

void lexeme_free(Lexeme* lex)
{
	if (lex->type == LEXEME_IDENTIFIER)
	{
		free(lex->value.identifier);
	}

	free(lex);
	return;
}

Lexeme* lexeme_new(char* c, int t)
{
	Lexeme* lex;
	lex = malloc(sizeof(lex));

	if (t == 1)
	{
		lex->value.character = c[0];
		lex->type = LEXEME_CHARACTER;
	}
	else
	{
		lex->value.identifier = malloc(t);

		for (int i = 0 ; i < t ; i++)
		{
			lex->value.identifier[i] = c[i];
		}
		
		lex->value.identifier = c;
		lex->type = LEXEME_IDENTIFIER;
	}

	return lex;
}
