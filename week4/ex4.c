#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define SEP_TOK " \t\r\n\a"
#define BUFFER_LEN  256

int launch(char **args) {
  pid_t pid, wpid;
  int signal;

  pid = fork();
  printf("|%d|", pid);
  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      perror("shell");
    }
    exit(1);
  } else if (pid < 0) {
    perror("shell");
  } else {
    do {
      wpid = waitpid(pid, &signal, WUNTRACED);
    } while (!WIFEXITED(signal) && !WIFSIGNALED(signal));
  }

  return 1;
}

int execute(char **args) {
  int i;

  if (args[0] == NULL) {
    return 1;
  }

  if (strcmp(args[0], "exit") == 0) {
    return 1;
  } else if (strcmp(args[0], "cd") == 0) {
    if (args[1] == NULL) {
      fprintf(stderr, "shell: expected argument to \"cd\"\n");
    } else {
      if (chdir(args[1]) != 0) {
        perror("shell");
      }
    }
    return 1;
  } else {
    return launch(args);
  }
}

char **split_line(char *line) {
  int bufsize = BUFFER_LEN, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  token = strtok(line, SEP_TOK);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += SEP_TOK;
      tokens = realloc(tokens, bufsize * sizeof(char*));
    }

    token = strtok(NULL, SEP_TOK);
  }
  tokens[position] = NULL;
  return tokens;
}

int main() {
  char *line;
  char **args;
  int status;

  do {
    printf(">> ");
    if (!fgets(line, BUFFER_LEN, stdin)) { break; }
    args = split_line(line);
    status = execute(args);
  } while (status);

  return 0;
}
