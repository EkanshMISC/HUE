#ifndef HUE_AST
#define HUE_AST

typedef struct hue_ast
{
    enum{
        AST_VARIABLE_DEFINITION,
        AST_VARIABLE,
        AST_FUNCTION_CALL,
        AST_STRING
    }type;

    char* variable_definition_variable_name;
    struct hue
}AST_T;
#endif