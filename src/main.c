#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX_INPUT_LENGTH 100

int main()
{
  int input = 1;
  List *history = init_history();
  char str[MAX_INPUT_LENGTH];

  while (input != 0)
  {
    printf("Select an option: tokenizer: 1, history: 2, quit: 0\n");
    
    // Read user input
    scanf("%d", &input);
    getchar();
    switch (input)
    {
    case 1:
      printf("> ");                   // Display prompt
      fgets(str, sizeof(str), stdin); // Read user input
      printf("%s\n", str);            // Echo input

      // Tokenize the input
      char **tokens = tokenize(str);
      print_tokens(tokens);
      free_tokens(tokens);

      // Add input to history
      add_history(history, str);
      break;

    case 2:
      print_history(history);
      free_history(history);
      break;

    case 0:
      printf("Goodbye...");
      break;
    }
  }
  return 0;
}
