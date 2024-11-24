#ifndef HUE_TOKEN
#define HUE_TOKEN
typedef struct huetoken
{
    enum
    {
        TOKEN_ID,
        TOKEN_EQUALS,
        TOKEN_STRING,
        TOKEN_LPAREN,
        TOKEN_RPAREN
    } type;

    char* value;
}token_T;

token_T* init_token(int type, char* value);
#endif