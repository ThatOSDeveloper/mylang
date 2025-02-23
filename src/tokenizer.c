#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "tokenizer.h"

// Function to create a new token
Token create_token(TokenType type, char *value) {
    Token token;
    token.type = type;
    token.value = value ? strdup(value) : NULL; // Duplicate string for safety
    return token;
}

// Function to free token memory
void free_token(Token *token) {
    if (token->value) {
        free(token->value);
    }
}

// Tokenizer function
Token *tokenize(char *line, int *token_count) {
    Token *tokens = malloc(2 * sizeof(Token)); // At most two tokens (PRINT, STRING)
    *token_count = 0;

    while (isspace((unsigned char)*line)) line++; // Skip leading spaces

    // Check for PRINT keyword
    if (strncmp(line, "PRINT", 5) == 0 && isspace(line[5])) {
        tokens[(*token_count)++] = create_token(TOKEN_PRINT, "PRINT");
        line += 5; // Move past "PRINT"
        while (isspace((unsigned char)*line)) line++; // Skip spaces

        // Expect a quoted string
        if (*line == '"') {
            line++; // Move past the opening quote
            char *end_quote = strchr(line, '"'); // Find closing quote
            
            if (end_quote) {
                *end_quote = '\0'; // Null-terminate the string
                tokens[(*token_count)++] = create_token(TOKEN_STRING_LITERAL, line);
            } else {
                tokens[(*token_count)++] = create_token(TOKEN_UNKNOWN, "Missing closing quote");
            }
        } else {
            tokens[(*token_count)++] = create_token(TOKEN_UNKNOWN, "Expected string after PRINT");
        }
    } else {
        tokens[(*token_count)++] = create_token(TOKEN_UNKNOWN, "Unknown statement");
    }

    return tokens;
}
