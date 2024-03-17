#include <stdio.h>

#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"

int main(int argc, char **argv) {
  printf("OPTIONS?\n");
  initVM();
  Chunk chunk;

  initChunk(&chunk);
  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 1);
  writeChunk(&chunk, constant, 1);
  writeChunk(&chunk, OP_RETURN, 1);

  disassembleChunk(&chunk, "test chunk");
  interpret(&chunk);

  printf("=========");
  freeVM();
  freeChunk(&chunk);
  return 0;
}
