#ifndef COMMAND_CAT_H
# define COMMAND_CAT_H

# include <stdio.h>
# include <string.h>

# include "useful_func.h"
# include "iso9660.h"

void cmd_cat(struct iso_dir *root, void *ptr, char *arg);

#endif /* !COMMAND_CAT_H */
