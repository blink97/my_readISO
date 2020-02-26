#ifndef COMMAND_CD_H
# define COMMAND_CD_H

# include <stdio.h>

# include "iso9660.h"
# include "useful_func.h"
# include "commands.h"

struct iso_dir *cmd_cd(struct iso_dir *root, void *ptr, char *arg,
                        struct iso_prim_voldesc *map);

#endif /* !COMMAND_CD_H */
