#include "command_info.h"

void cmd_info(struct iso_prim_voldesc *map)
{
  printf("System Identifier: %.*s\n", ISO_SYSIDF_LEN, map->syidf);
  printf("Volume Identifier: %.*s\n", ISO_VOLIDF_LEN, map->vol_idf);
  printf("Block count: %d\n", map->vol_blk_count.le);
  printf("Block size: %d\n", map->vol_blk_size.le);
  printf("Creation date: %.*s\n", ISO_LDATE_LEN, map->date_creat);
  printf("Application Identifier: %.*s\n", ISO_APP_LEN, map->app_idf);
}

void cmd_help()
{
  printf("help: display command help\n");
  printf("info: display volume info\n");
  printf("ls: display the content of a directory\n");
  printf("cd: change current directory\n");
  printf("tree: display the tree of a directory\n");
  printf("get: copy file to local directory\n");
  printf("cat: display file content\n");
  printf("pwd: print current path\n");
  printf("quit: program exit\n");
}
