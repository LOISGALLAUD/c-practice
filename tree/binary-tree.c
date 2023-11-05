/*
 * C implementation of a binary tree
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} node;

typedef struct tree
{
    struct node *root;
} tree;

node *create_node(int value)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

tree *create_tree()
{
    tree *new_tree = malloc(sizeof(tree));
    new_tree->root = NULL;
    return new_tree;
}

void insert(tree *tree, int value)
{
    node *new_node = create_node(value);
    if (tree->root == NULL)
    {
        tree->root = new_node;
    }
    else
    {
        node *current = tree->root;
        node *parent = NULL;
        while (1)
        {
            parent = current;
            if (value < parent->value)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = new_node;
                    return;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = new_node;
                    return;
                }
            }
        }
    }
}

void print_inorder(node *node)
{
    if (node != NULL)
    {
        print_inorder(node->left);
        printf("%d ", node->value);
        print_inorder(node->right);
    }
}

void print_preorder(node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->value);
        print_preorder(node->left);
        print_preorder(node->right);
    }
}

void print_postorder(node *node)
{
    if (node != NULL)
    {
        print_postorder(node->left);
        print_postorder(node->right);
        printf("%d ", node->value);
    }
}

int main()
{
    tree *tree = create_tree();
    insert(tree, 5);
    insert(tree, 3);
    insert(tree, 7);
    insert(tree, 1);
    insert(tree, 4);
    insert(tree, 6);
    insert(tree, 8);
    printf("Inorder traversal: ");
    print_inorder(tree->root);
    printf("\n");
    printf("Preorder traversal: ");
    print_preorder(tree->root);
    printf("\n");
    printf("Postorder traversal: ");
    print_postorder(tree->root);
    printf("\n");
    return 0;
}
