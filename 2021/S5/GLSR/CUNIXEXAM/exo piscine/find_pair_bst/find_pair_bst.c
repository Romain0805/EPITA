#include <err.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "node.h"
int *arr;

size_t size_rec(struct bst_node *node)
{
    if (node == NULL)
        return 0;
    return (size_rec(node->left) + 1 + size_rec(node->right));
}
void build_array(int *arr, struct bst_node *node, int i)
{
    if (node == NULL)
        return;
    arr[i] = node->data;
    i += 1;
    if (node->left)
        build_array(arr, node->left, i);
    if (node->right)
        build_array(arr, node->right, i);
}

int find_pair(struct bst_node *root, int k)
{
    size_t size = size_rec(root);
    int check = 0;
    build_array(arr, root, 0);
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i + 1; j < size - 1; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                check = 1;
                printf("%d %d\n", arr[i], arr[j]);
            }
        }
    }
    if (check == 0)
        return 0;
    return 1;
}
