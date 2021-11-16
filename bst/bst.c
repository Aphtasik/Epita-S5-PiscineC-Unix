#include "bst.h"

#include <stdlib.h>

struct bst_node *create_node(int value)
{
    struct bst_node *new = malloc(sizeof(struct bst_node));
    if (!new)
        return NULL;

    new->data = value;
    new->left = NULL;
    new->right = NULL;

    return new;
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    if (!tree)
    {
        struct bst_node *root = create_node(value);
        return root;
    }
    else
    {
        struct bst_node *tmp = create_node(value);
        struct bst_node *curr = NULL;
        struct bst_node *parent = NULL;

        while (1)
        {
            parent = curr;

            if (value < parent->data)
            {
                curr = curr->left;
                if (!curr)
                {
                    parent->left = tmp;
                    return tree;
                }
            }
            else
            {
                curr = curr->right;

                if (!curr)
                {
                    parent->right = tmp;
                    return tree;
                }
            }
        }
    }
}

struct bst_node *delete_node_rec(struct bst_node *tree, int value)
{
    if (!tree)
        return tree;

    if (value > tree->data)
        tree->left = delete_node(tree->left, value);
    else if (value < tree->data)
        tree->right = delete_node(tree->right, value);
    else
    {
        if (!tree->left && !tree->right)
            return NULL;
        else if (!tree->left)
        {
            struct bst_node *tmp = tree->right;
            free(tree);
            return tmp;
        }
        else
        {
            struct bst_node *tmp = tree->left;
            free(tree);
            return tmp;
        }

        struct bst_node *tmp = NULL;

        if (tree->left->left->data > tree->left->right->data)
            tmp = tree->left;
        else
            tmp = tree->right;

        tree->data = tmp->data;
        tree->left = delete_node(tree->left, tmp->data);
    }
    return tree;
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    if (!tree)
        return tree;
    delete_node_rec(tree, value);
    return tree;
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (!tree || tree->data == value)
        return tree;
    else if (value < tree->data)
        return find(tree->left, value);
    else
        return find(tree->right, value);
}

void free_bst_rec(struct bst_node *tree, struct bst_node *first_node)
{
    if (!tree)
        return;
    else if (!tree->left && !tree->right)
    {
        free(tree);
        free_bst_rec(first_node, first_node);
    }
    else
    {
        free_bst_rec(tree->left, first_node);
        free_bst_rec(tree->right, first_node);
    }
}

void free_bst(struct bst_node *tree)
{
    if (!tree)
        return;
    else
        free_bst_rec(tree, tree);
}
