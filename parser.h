#include "lexer.h"

typedef struct ASTNode
{
	union
	{
		float number;

		struct
		{
		} function_call;

		struct
		{
		} assignement;

		Vector* v;
		char* variable;
	} value;

	enum
	{
		PARSER_NUMBER,
		PARSER_FUNCTION_CALL,
		PARSER_ASSIGNEMENT,
		PARSER_VECTOR,
		PARSER_VARIABLE,
		PARSER_BLOCK //Utilise v
	} type;
} ASTNode;

ast_node parse(Vector*);
