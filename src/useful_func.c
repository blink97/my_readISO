#include "useful_func.h"

void *get_path_table(struct iso_prim_voldesc *map, void *ptr)
{
  char *table = ptr;
  return table + ISO_BLOCK_SIZE * map->le_path_table_blk;
}

void *get_root(struct iso_path_table_le *table, void *ptr)
{
  char *root = ptr;
  return root + ISO_BLOCK_SIZE * table->data_blk;
}

void *next(struct iso_dir *root)
{
  void *tmp = root;
  char *next = tmp;
  return next + root->dir_size;
}

void *get_name(struct iso_dir *root, int cpt)
{
  if (cpt == 0)
    return ".";
  else if (cpt == 1)
    return "..";
  else
  {
    void *tmp = root + 1;
    char *name = tmp;
    return name;
  }
}

int get_size(struct iso_dir *root, char *name)
{
  int size = 0;
  while (size < root->idf_len)
  {
    if (name[size] == ';')
      return size;
    size++;
  }
  return size;
}

void *get_file_cont(struct iso_dir *root, void *ptr)
{
  char *file = ptr;
  return file + root->data_blk.le * ISO_BLOCK_SIZE;
}

void name_for_get(char *newname, char *name, size_t len)
{
  for (size_t i = 0; i < len; i++)
  {
    if (name[i] == ';')
    {
      newname[i] = '\0';
      return;
    }
    newname[i] = name[i];
  }
}
