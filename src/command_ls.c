#include "command_ls.h"

void cmd_ls(struct iso_dir *root)
{
  int cpt = 0;
  int size = 0;
  char *name = NULL;
  struct iso_dir *tmp = root;
  while (tmp->dir_size > 0)
  {
    name = get_name(tmp, cpt);
    size = get_size(tmp, name);
    printf("%c%c %9u %04d/%02d/%02d %02d:%02d %.*s\n",
            (tmp->type & 2) ? 'd' : '-',
            (tmp->type & 1) ? 'h' : '-',
            tmp->file_size.le,
            1900 + tmp->date[0],
            tmp->date[1],
            tmp->date[2],
            tmp->date[3],
            tmp->date[4],
            (cpt == 1 ) ? 2 : size,
            name);
    tmp = next(tmp);
    cpt += 1;
  }
}
