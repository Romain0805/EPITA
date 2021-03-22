#include "ast.h"

#include <stdio.h>

struct node *ast_build(const char *filename)
{
    FILE *fd = fopen(filename, "r");
    if (!fd)
        return NULL;
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    while ((linelen = getline(&line, &linecap, fd)) > 0)
        fwrite(line, linelen, 1, stdout);

}
void ast_delete(struct node *root)
{
    free(root);
}