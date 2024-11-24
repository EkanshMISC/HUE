#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "include/lexer.h"

lexer_T* init_lexer(char* text)
{
    lexer_T* lexer = calloc(1,sizeof(struct huelexer));
    lexer->text = text;
    lexer->x=0;
    lexer->a=text[lexer->x];

    return lexer;
}
void lexer_nextchar(lexer_T* lexer)
{
    if (lexer->a!= '\0' && lexer->x < strlen(lexer->text))
    {
        lexer->x +=1;
        lexer->a=lexer->text[lexer->x];
    }
}
void lexer_skipspace(lexer_T* lexer)
{
    while(lexer->a == ' '|| lexer->a == 10)
    {
        lexer_nextchar(lexer);
    }
}
token_T* lexer_next_token(lexer_T* lexer)
{
    while(lexer->a!= '\0' && lexer->x < strlen(lexer->text))
    {
        if(lexer->a == ' '|| lexer->a == 10)
        {
            lexer_skipspace(lexer);
        }
        if(isalnum(lexer->a))
        {
            return lexer_collect_id(lexer);
        }
        if (lexer->a == '"')
        {
            return lexer_collect_string(lexer);
        }
        switch(lexer->a)
        {
            case '=': return lexer_nextchar_token(lexer, init_token(TOKEN_EQUALS,lexer_char_to_string(lexer)));break; 
            case '(': return lexer_nextchar_token(lexer, init_token(TOKEN_LPAREN,lexer_char_to_string(lexer)));break;
            case ')': return lexer_nextchar_token(lexer, init_token(TOKEN_RPAREN,lexer_char_to_string(lexer)));break;
           
        }
    }

    return (void*)0;
}
token_T* lexer_collect_string(lexer_T* lexer)
{
    lexer_nextchar(lexer);
    char* value = calloc(1,sizeof(char));
    value[0]='\0';
    while(lexer->a != '"')
    {
        char* s = lexer_char_to_string(lexer);
        value = realloc(value,(strlen(value) + strlen(s)+1) * sizeof(char));
        strcat(value,s);
        lexer_nextchar(lexer);
    }
    lexer_nextchar(lexer);
    return init_token(TOKEN_STRING, value);
}
token_T* lexer_collect_id(lexer_T* lexer)
{
    char* value = calloc(1,sizeof(char));
    value[0]='\0';
    while(isalnum(lexer->a))
    {
        char* s = lexer_char_to_string(lexer);
        value = realloc(value,(strlen(value) + strlen(s)+1) * sizeof(char));
        strcat(value,s);
        lexer_nextchar(lexer);
    }
    return init_token(TOKEN_ID, value);
}
token_T* lexer_nextchar_token(lexer_T* lexer, token_T* token)
{
    lexer_nextchar(lexer);
    return token;
}
char* lexer_char_to_string(lexer_T* lexer)
{
    char* str = calloc(2, sizeof(char));
    str[0] = lexer->a;
    str[1] = '\0';
    return str;
}