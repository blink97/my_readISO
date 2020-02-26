#include "my_read_iso.h"

void *get_super_block(void *img)
{
  char *ptr = img;
  return ptr + ISO_BLOCK_SIZE * ISO_PRIM_VOLDESC_BLOCK;
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    fprintf(stderr, "usage: ./my_read_iso FILE\n");
    return 1;
  }
  int fd = open(argv[1], O_RDONLY);
  if (fd < 0)
  {
    fprintf(stderr, "%s: %s: %s\n", argv[0], argv[1], strerror(errno));
    return 1;
  }
  struct stat stat;
  if (fstat(fd, &stat) != 0)
  {
    fprintf(stderr, "%s\n", strerror(errno));
    return 1;
  }
  off_t size_index = ISO_BLOCK_SIZE * ISO_PRIM_VOLDESC_BLOCK;
  size_index += sizeof(struct iso_prim_voldesc);
  if (stat.st_size < size_index)
  {
    fprintf(stderr, "%s: %s: invalid ISO9660 file\n", argv[0], argv[1]);
    return 1;
  }
  void *ptr = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (ptr == MAP_FAILED)
  {
    fprintf(stderr, "%s\n", strerror(errno));
    return 1;
  }
  if (close(fd) != 0)
  {
    fprintf(stderr, "%s\n", strerror(errno));
    return 1;
  }
  struct iso_prim_voldesc *super = get_super_block(ptr);
  if (strncmp(super->std_identifier, "CD001", 5) != 0)
  {
    fprintf(stderr, "%s: %s: invalid ISO9660 file\n", argv[0], argv[1]);
    return 1;
  }
  enter_shell(super, ptr);
  if ((munmap(super, stat.st_size) < 0))
  {
    fprintf(stderr, "%s\n", strerror(errno));
    return 1;
  }
  return 0;
}
