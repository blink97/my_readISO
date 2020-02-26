#ifndef USEFUL_FUNC_H
# define USEFUL_FUNC_H

# include <stddef.h>

# include "iso9660.h"

void *get_path_table(struct iso_prim_voldesc *map, void *ptr);
void *get_root(struct iso_path_table_le *table, void *ptr);
void *next(struct iso_dir *root);
void *get_name(struct iso_dir *root, int cpt);
int get_size(struct iso_dir *root, char *name);
void *get_file_cont(struct iso_dir *root, void *ptr);
void name_for_get(char *newname, char *arg, size_t len);

#endif /* !USEFUL_FUNC_H */
