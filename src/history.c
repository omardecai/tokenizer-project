#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history() {
  List *list = (List *)malloc(sizeof(List));
  list->root = NULL;
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str) {
  Item *new_item = (Item *)malloc(sizeof(Item));
  new_item->id = 0;
  new_item->str = copy_str(str, string_length(str));
  new_item->next = NULL;

  if (list->root ==NULL) {
    list->root = new_item;
  }else{
  Item *current = list->root;
  while (current->next != NULL) {
    current = current->next;
   }
  current->next = new_item;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id) {
  Item *current = list->root;
  while (current != NULL) {
    if (current->id == id) {
      return current->str;
    }
    current = current->next;
  }
}

/*Print the entire contents of the list. */
void print_history(List *list) {
  Item *current = list->root;
  while (current != NULL) {
    printf("ID: %d, %s\n", current->id, current->str);
    current = current->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list) {
  Item *current = list->root;
  Item *next;

  while(current != NULL) {
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  free(list);
}
