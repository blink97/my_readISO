#include "command_cd.h"

struct iso_dir *cmd_cd(struct iso_dir *root, void *ptr, char *arg,
                        struct iso_prim_voldesc *map)
{
  if (*arg == '\0')
  {
    struct iso_path_table_le *new_table = get_path_table(map, ptr);
    struct iso_dir *new_dir = get_root(new_table, ptr);
    printf("Changing to '/' directory\n");
    return new_dir;
  }
  struct iso_dir *new_dir = root;
  struct iso_dir *tmp = root;
  int cpt = 0;
  while (tmp->dir_size > 0)
  {
    char *name = get_name(tmp, cpt);
    int size = strlen(arg) - 1;
    if (strncmp(name, arg, size) == 0)
    {
      new_dir = get_file_cont(tmp, ptr);
      printf("Changing to '%.*s' directory\n", size, name);
      return new_dir;
    }
    cpt++;
    tmp = next(tmp);
  }
  return new_dir;
}
