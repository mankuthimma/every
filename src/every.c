
//
// every.c
//
// Copyright (c) 2012 TJ Holowaychuk <tj@vision-media.ca>
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "commander.h"
#include "ms.h"

/*
 * Version.
 */

#define VERSION "0.0.1"

/*
 * Output error `msg`.
 */

void
error(char *msg) {
  fprintf(stderr, "Error: %s\n", msg);
  exit(1);
}

/*
 * Concat an array of `strs`.
 */

char *
concat(int len, char **strs) {
  int bytes = len; // ' ' + null
  for (int i = 0; i < len; ++i) bytes += strlen(strs[i]);
  char *str = malloc(bytes);
  if (!str) return NULL;
  for (int i = 0; i < len; ++i) {
    if (i) strcat(str, " ");
    strcat(str, strs[i]);
  }
  str[bytes] = 0;
  return str;
}

/*
 * [options] <interval> <cmd>
 */

int
main(int argc, char **argv){
  command_t program;
  command_init(&program, "every", VERSION);
  program.usage = "<interval> <cmd ...>";
  command_parse(&program, argc, argv);

  // required args
  if (!program.argc) error("<interval> required");
  if (program.argc < 2) error("<cmd> required");

  // interval
  long long sec = string_to_seconds(argv[1]);
  if (-1 == sec) error("invalid <interval>");

  // cmd
  char *cmd = concat(argc - 2, argv + 2);

  // exec
  while (1) {
    sleep(sec);
    system(cmd);
  }

  return 0;
}