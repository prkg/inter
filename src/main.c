#include "chunk.h"
#include "common.h"
#include "debug.h"

int main(int argc, char **argv) {
  printf("OPTIONS\n");
  Chunk chunk;
  initChunk(&chunk);
  writeChunk(&chunk, OP_RETURN);
  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);
  return 0;
}
