#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

// Create a PRINT AST node
ASTNode *create_print_node(char *value) {
    ASTNode *node = malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    node->type = AST_PRINT;
    node->value = strdup(value);  // Copy string
    return node;
}

// Free AST memory
void free_ast(ASTNode *node) {
    if (!node) return;
    if (node->value) free(node->value);
    free(node);
}

// Print the AST (for debugging)
void print_ast(ASTNode *node) {
    if (!node) return;

    switch (node->type) {
        case AST_PRINT:
            printf("AST: PRINT \"%s\"\n", node->value);
            break;
    }
}
