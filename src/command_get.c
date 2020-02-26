#include "command_get.h"

void cmd_get(struct iso_dir *root, void *ptr, char *arg)
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
      char file_name[strlen(arg) - 1];
      name_for_get(file_name, name, strlen(arg - 1));
      FILE *new_file = fopen(file_name, "w+");
      char *file = get_file_cont(tmp, ptr);
      fprintf(new_file, "%.*s", tmp->file_size.le, file);
      fclose(new_file);
      return;
    }
    tmp = next(tmp);
  }
  printf("file not found\n");
}
