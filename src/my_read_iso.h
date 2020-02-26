#ifndef MY_READ_ISO_H
# define MY_READ_ISO_H

#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

# include "commands.h"
# include "iso9660.h"
# include "my_read_iso.h"

void *get_super_block(void *img);

#endif /* !MY_READ_ISO_H */
