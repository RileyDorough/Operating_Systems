#include "types.h"
#include "stat.h"
#include "user.h"

char buf[1];

void
hex(int fd)
{
  int n;
  int memoryLocation = 0;
  int cursor = 0;

  while((n = read(fd, buf, sizeof(buf))) > 0) {

    if (cursor == 0 && memoryLocation == 0) {
      printf(0, "0%x", memoryLocation);
      printf(0, "%s", ":   ");
    }
    if (cursor == 0 && memoryLocation != 0){
      printf(0, "%x", memoryLocation);
      printf(0, "%s", ":   ");
    }
    if (buf[0] > 15) {
      printf(0, "%x ", buf[0]);
    }
    else {
      printf(0, "0%x ", buf[0]);
    }

    cursor += 1;

    if (cursor == 16) {
      printf(0, "\n");
      memoryLocation += cursor;
      cursor = 0;
    }
  }
  if(n < 0){
    printf(1, "\nhex: read error\n");
    exit();
  }
  printf(0, "\n");
}

int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){
    hex(0);
    exit();
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "cat: cannot open %s\n", argv[i]);
      exit();
    }
    hex(fd);
    close(fd);
  }
  exit();
}
