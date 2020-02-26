#ifndef COMMANDS_H
# define COMMANDS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "command_tree.h"
# include "command_cat.h"
# include "command_info.h"
# include "command_cd.h"
# include "command_ls.h"
# include "command_get.h"
# include "iso9660.h"
# include "my_read_iso.h"
# include "useful_func.h"

struct iso_dir *exec_command(char *command, struct iso_prim_voldesc *map,
                             struct iso_dir *root, void *ptr);
void enter_shell(struct iso_prim_voldesc *map, void *ptr);
void waiting_commands(struct iso_prim_voldesc *map, struct iso_dir *root,
                      void *ptr);

#endif /* !COMMANDS_H */
