#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <assert.h>
#include <string.h>

size_t getFilesize(const char* filename) {
  struct stat st;
  stat(filename, &st);
  return st.st_size;
  
}

int main(int argc, char** argv) {
  size_t filesize = getFilesize(argv[1]);

  int fd = open(argv[1], O_RDWR, 0);
  assert(fd != -1);

  void* mmappedData = mmap(NULL, filesize, PROT_WRITE , MAP_SHARED, fd, 0);
  assert(mmappedData != MAP_FAILED);

  (void)strcpy((char *)(mmappedData), "Hello, World!\n");

  int rc = munmap(mmappedData, filesize);
  assert(rc == 0);
  close(fd);
  
}
