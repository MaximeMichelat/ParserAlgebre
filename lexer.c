#include "lexer.h"

static enum
{
	STATE_IDENTIFIER,
	STATE_DELIMITER,
	STATE_NUMBER,
	STATE_SYMBOLS,
	STATE_WHITESPACE
} state;

static Lexemes* get_value(char* input, int start, int cursor, int state)
{

}

static int get_new_state(char* c, int state)
{
	if (c[0] == ' ')
	{
		return STATE_WHITESPACE;
	}

	else
	{
		return STATE_IDENTIFIER;
	}
}

Vector* lex(const char* input)
{
	Vector* lexemes = vector_new();
	int state = STATE_WHITESPACE; //Ancien état
	int start;

	for (int i = 0 ; input[i] != '\0' ; i++) //i = offset
	{
		new_state = get_new_state(input + i, state);

		if (state == STATES_DELIMITER || state != new_state)
		{
			start = i;
			vector_push(lexemes, get_value(input, start, i, state));
		}
	}

	return v;
}

void lexeme_free(Lexeme* lex)
{

}

Lexeme* lexeme_new_character(char c)
{

}

Lexeme* lexeme_new_identifier(char* c)
{

}
