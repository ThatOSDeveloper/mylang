#ifndef TOKENIZER_H
#define TOKENIZER_H

#define MAX_LINE 256

// Token types
typedef enum {
    TOKEN_PRINT,
    TOKEN_STRING_LITERAL,
    TOKEN_END_OF_LINE,
    TOKEN_UNKNOWN
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char *value;  // Holds string values for TOKEN_STRING_LITERAL
} Token;

// Function prototypes
Token *tokenize(char *line, int *token_count);
void parse(Token *tokens, int token_count);
Token create_token(TokenType type, char *value);
void free_token(Token *token);

#endif
