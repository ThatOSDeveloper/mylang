#ifndef AST_H
#define AST_H

#include "tokenizer.h"

// AST Node Types
typedef enum {
    AST_PRINT
} ASTNodeType;

// AST Node Structure
typedef struct ASTNode {
    ASTNodeType type;
    char *value;  // Holds string values for PRINT statements
} ASTNode;

// Function prototypes
ASTNode *create_print_node(char *value);
void free_ast(ASTNode *node);
void print_ast(ASTNode *node);

#endif
