#include "command_cat.h"

void cmd_cat(struct iso_dir *root, void *ptr, char *arg)
{
  if (*arg == '\0')
  {
    printf("need argument\n");
    return;
  }
  struct iso_dir *tmp = root;
  while (tmp->dir_size > 0)
  {
    char *name = get_name(tmp, 2);
    if (strncmp(name, arg, strlen(arg) - 1) == 0)
    {
      char *file = get_file_cont(tmp, ptr);
      printf("%.*s", tmp->file_size.le, file);
      return;
    }
    tmp = next(tmp);
  }
  printf("file not found\n");
}
