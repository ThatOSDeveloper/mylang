#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "ast.h"

// Parse tokens into an AST
ASTNode *parse(Token *tokens, int token_count) {
    if (token_count < 2) {
        fprintf(stderr, "Syntax Error: Incomplete statement\n");
        return NULL;
    }

    if (tokens[0].type == TOKEN_PRINT && tokens[1].type == TOKEN_STRING_LITERAL) {
        return create_print_node(tokens[1].value);
    } else {
        fprintf(stderr, "Syntax Error: Invalid statement structure\n");
        return NULL;
    }
}

// Main function for testing
int main() {
    char line[MAX_LINE];
    printf("Enter BASIC-like code:\n");

    if (fgets(line, sizeof(line), stdin)) {
        int token_count;
        Token *tokens = tokenize(line, &token_count);

        ASTNode *ast = parse(tokens, token_count);
        if (ast) {
            print_ast(ast);
            free_ast(ast);
        }

        // Free token memory
        for (int i = 0; i < token_count; i++) {
            free_token(&tokens[i]);
        }
        free(tokens);
    }

    return 0;
}
