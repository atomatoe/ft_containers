/* red-black tree */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <iostream>

typedef int T;
typedef enum { BLACK, RED } nodeColor;

typedef struct Node_
{
    struct Node_ *left;         /* left child */
    struct Node_ *right;        /* right child */
    struct Node_ *parent;       /* parent */
    nodeColor color;            /* node color (BLACK, RED) */
    T data;                     /* data stored in node */
} Node;

#define NIL &sentinel           /* all leafs are sentinels */
Node sentinel = { NIL, NIL, 0, BLACK, 0};

Node *root = NIL;               /* root of Red-Black tree */

void rotateLeft(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NIL)
        y->left->parent = x;
    if (y != NIL)
        y->parent = x->parent;
    if (x->parent)
    {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    } 
    else
    {
        root = y;
    }
    y->left = x;
    if (x != NIL) x->parent = y;
}

void rotateRight(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    if (y->right != NIL)
        y->right->parent = x;
    if (y != NIL)
        y->parent = x->parent;
    if (x->parent)
    {
        if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
    } 
    else
        root = y;
    y->right = x;
    if (x != NIL)
        x->parent = y;
}

void insertFixup(Node *x)
{
    while (x != root && x->parent->color == RED)
    {
        if (x->parent == x->parent->parent->left)
        {
            Node *y = x->parent->parent->right;
            if (y->color == RED)
            {
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            } 
            else
            {
                if (x == x->parent->right)
                {
                    x = x->parent;
                    rotateLeft(x);
                }
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                rotateRight(x->parent->parent);
            }
        } 
        else
        {
            Node *y = x->parent->parent->left;
            if (y->color == RED)
            {
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            } 
            else
            {
                if (x == x->parent->left) {
                    x = x->parent;
                    rotateRight(x);
                }
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                rotateLeft(x->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

Node *insertNode(T data)
{
    Node *current, *parent, *x;
    current = root;
    parent = 0;
    while (current != NIL)
    {
        if (data == current->data)
            return (current);
        parent = current;
        if(data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    x = new Node_;
    x->data = data;
    x->parent = parent;
    x->left = NIL;
    x->right = NIL;
    x->color = RED;
    if(parent)
    {
        if(data < parent->data)
            parent->left = x;
        else
            parent->right = x;
    } 
    else
    {
        root = x;
    }
    insertFixup(x);
    return(x);
}

void deleteFixup(Node *x)
{
    while (x != root && x->color == BLACK)
    {
        if (x == x->parent->left)
        {
            Node *w = x->parent->right;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft (x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            } 
            else
            {
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    rotateRight (w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                rotateLeft (x->parent);
                x = root;
            }
        } 
        else
        {
            Node *w = x->parent->left;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight (x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    rotateLeft (w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rotateRight (x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void deleteNode(Node *z) {
    Node *x, *y;
    if (!z || z == NIL)
        return;
    if (z->left == NIL || z->right == NIL)
        y = z;
    else
    {
        y = z->right;
        while (y->left != NIL)
            y = y->left;
    }
    if (y->left != NIL)
        x = y->left;
    else
        x = y->right;
    x->parent = y->parent;
    if (y->parent)
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    else
        root = x;
    if (y != z)
        z->data = y->data;
    if (y->color == BLACK)
        deleteFixup (x);
    delete y;
}

Node *findNode(T data)
{
    Node *current = root;
    while(current != NIL)
        if(data == current->data)
            return (current);
        else
        {
            if(data < current->data)
                current = current->left;
            else
                current = current->right;
        }
    return(0);
}

int main(int argc, char **argv)
{
    int a, maxnum, ct;
    Node *t;
    maxnum = atoi(argv[1]);

    for (ct = maxnum; ct; ct--) {
        a = rand() % 9 + 1;
        if ((t = findNode(a)) != NULL)
        {
            deleteNode(t);
            
        } 
        else
        {
            insertNode(a);
        }
    }
    return(0);
}