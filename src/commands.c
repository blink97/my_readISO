#include "commands.h"

void cmd_pwd(struct iso_dir *root)
{
  char *name = get_name(root, 2);
  printf("%s/\n", name);
}

char *get_argument(char *command, size_t len)
{
  int started = 0;
  char *arg = NULL;
  size_t size = strlen(command);
  for (size_t i = len; i < size; i++)
  {
    if (command[i] > ' ')
    {
      if (!started)
      {
        started = 1;
        arg = command + i;
        return arg;
      }
    }
  }
  return "";
}

struct iso_dir *exec_command(char *command, struct iso_prim_voldesc *map,
                             struct iso_dir *root, void *ptr)
{
  if (strncmp(command, "info", 4) == 0)
    cmd_info(map);
  else if (strncmp(command, "help", 4) == 0)
    cmd_help();
  else if (strncmp(command, "ls", 2) == 0)
    cmd_ls(root);
  else if (strncmp(command, "quit", 4) == 0)
    exit(0);
  else if (strncmp(command, "cat", 3) == 0)
  {
    char *arg = get_argument(command, 3);
    cmd_cat(root, ptr, arg);
  }
  else if (strncmp(command, "cd", 2) == 0)
  {
    char *arg = get_argument(command, 2);
    return cmd_cd(root, ptr, arg, map);
  }
  else if (strncmp(command, "get", 3) == 0)
  {
    char *arg = get_argument(command, 3);
    cmd_get(root, ptr, arg);
  }
  else if (strncmp(command, "pwd", 3) == 0)
    cmd_pwd(root);
  else if (strncmp(command, "tree", 4) == 0)
    cmd_tree(root, ptr);
  else
  {
    int size = strlen(command) - 1;
    if (size > 0)
      printf("my_read_iso: %.*s: unknown command\n", size, command);
  }
  return root;
}

void enter_shell(struct iso_prim_voldesc *map, void *ptr)
{
  struct iso_path_table_le *table = get_path_table(map, ptr);
  struct iso_dir *root = get_root(table, ptr);
  waiting_commands(map, root, ptr);
}

void waiting_commands(struct iso_prim_voldesc *map, struct iso_dir *root,
                      void *ptr)
{
  int b = 1;
  int tty = isatty(0);
  struct iso_dir *tmp = root;
  while (b)
  {
    char command[4096];
    if (tty > 0)
      printf("> ");
    if ((fgets(command, 4096, stdin) == NULL))
      b = 0;
    else
    {
      char *true_command = get_argument(command, 0);
      tmp = exec_command(true_command, map, tmp, ptr);
    }
  }
}
