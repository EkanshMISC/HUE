#ifndef HUE_LEXER
#define HUE_LEXER
#include "token.h"  
typedef struct huelexer
{
    char a;
    unsigned int x;
    char* text;
}lexer_T;

lexer_T* init_lexer(char* text);

void lexer_nextchar(lexer_T* lexer);

void lexer_skipspace(lexer_T* lexer);

token_T* lexer_next_token(lexer_T* lexer);

token_T* lexer_collect_string(lexer_T* lexer);

token_T* lexer_collect_id(lexer_T* lexer);

token_T* lexer_nextchar_token(lexer_T* lexer, token_T* token);

char* lexer_char_to_string(lexer_T* lexer);

#endif