#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX_INPUT_LENGTH 100

int main(){
  char str[MAX_INPUT_LENGTH];

  while (1) {

    //Display prompt                                                                                                                          
    printf("> ");

    //Read user input                                                                                                                         
    fgets(str, sizeof(str), stdin);

    //Echo input                                                                                                                              
    printf("%s\n", str);

    //tokenize input                                                                                                                          
    List* history = init_history();
    add_history(history, str);

    char **tokens = tokenize(str);
    for (int i = 0; tokens[i] != NULL; i++) {
      printf("Tokens: %s", tokens[i]);
    }

    free_tokens(tokens);
  }
  return 0;
}

