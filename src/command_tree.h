#ifndef COMMAND_TREE_H
# define COMMAND_TREE_H

# include <stdio.h>

# include "iso9660.h"
# include "useful_func.h"

void cmd_tree_rec(struct iso_dir *root, int lev, void *ptr, int *nb_dir,
                  int *nb_file);

void cmd_tree(struct iso_dir *root, void *ptr);

#endif /* !COMMAND_TREE_H */
