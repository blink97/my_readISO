#include "command_tree.h"

void cmd_tree_rec(struct iso_dir *root, int lev, void *ptr, int *nb_dir,
                  int *nb_file)
{
  struct iso_dir *tmp = root;
  int cpt = 0;
  while (tmp->dir_size > 0)
  {
    if (cpt > 1)
    {
      char *name = get_name(tmp, cpt);
      for (int i = 0; i < lev; i++)
      {
        printf("|   ");
      }
      int len = get_size(tmp, name);
      printf("|-- %.*s", len, name);
      struct iso_dir *new_dir = get_file_cont(tmp, ptr);
      if (new_dir->type == 2)
      {
        (*nb_dir)++;
        printf("/\n");
        cmd_tree_rec(new_dir, lev + 1, ptr, nb_dir, nb_file);
      }
      else
      {
        (*nb_file)++;
        printf("\n");
      }
    }
    cpt++;
    tmp = next(tmp);
  }
}

void cmd_tree(struct iso_dir *root, void *ptr)
{
  printf(".\n");
  int nb_dir = 0;
  int nb_file = 0;
  cmd_tree_rec(root, 0, ptr, &nb_dir, &nb_file);
  printf("\n%d directories, %d files\n", nb_dir, nb_file);
}
