/*
--- ---
time: 04:30:48+06:00
date: Sun 17, Nov 2024
author: Mostafijul Islam
problem: `N/A`

*INPUT*
- ???

*QUESTION*
- This is not a question. This is a practice problem. Where Im traversing the array and adding/removing the elements.
  And it runs constantly until the user inputs 0. It's like a simple command-line application. It's just a practice problem.
--- ---
*/

#include <iostream>

// This function clears the console!
void clear() { printf("\e[1;1H\e[2J"); }

int main() {
  clear();
  int length;
  int initial_length;
  printf("Enter the length of the array: ");
  scanf("%d", &initial_length);
  length = initial_length;
  // Initiate and populate the array!
  int array[length];
  clear();
  printf("Let's populate your array!\n\n");
  for (int i = 0; i < length; i++) {
    printf("Enter the element at index %d: ", i);
    scanf("%d", &array[i]);
  }
  clear();
  printf("\nYour array is ready to proceed!\n\n\n");

  int input = 1;
  int clear_screen = 0;
  char control_msg[] = "\n\n0:exit  1:status  2:insert  3:remove \ninput: ";

  while (input) {
    if (clear_screen) {
      clear();
    }

    if (input == 1) {
      printf("Array status : \n");
      printf("length: %d\n", length);
      printf("max_length: %d\n", initial_length);
      printf("items: *");
      for (int j = 0; j < length; j++) {
        printf("| %d |", array[j]);
      }
      printf("*\n");
    } else if (input == 2) { //** INSERT!!


      clear();
      printf("Array Length: %d\n", length);
      printf("Enter the position to insert: ");
      int pos;
      scanf("%d", &pos);
      if (pos > initial_length || pos < 0) {
        clear();
        printf("Position out of bounds!\n\n");
        input = 1;
        continue;
      } else {
        printf("Enter the element to insert: ");
        int element;
        scanf("%d", &element);
        for (int k = length; k >= pos; k--) {
          array[k] = array[k - 1];
        }
        array[pos - 1] = element;
        if (length < initial_length) {
          length++;
        }

        clear();
        printf("Inserted value(%d) at position(%d).\n\n", element, pos);
        input = 1;
        continue;
      }


    } else if (input == 3) { //** DELETE!!



      clear();
      printf("Array Length: %d\n", length);
      printf("Enter the position to remove: ");
      int pos;
      scanf("%d", &pos);
      if (pos > initial_length || pos < 0) {
        clear();
        printf("Position out of bounds!\n\n");
        input = 1;
        continue;
      } else {
        int temp = array[pos - 1];
        for (int k = pos - 1; k < length; k++) {
          array[k] = array[k + 1];
        }
        length--;
        clear();
        printf("Removed value(%d) from position(%d).\n\n", temp, pos);
        input = 1;
        continue;
      }


      

    } else {
      printf("You've entered an unsupported input!\n"
             "Please pick one of the supported inputs!\n\n");
      input = 1;
      continue;
    }

    // Prompt user!
    printf("%s", control_msg);
    scanf("%d", &input);
    clear();
  }

  return 0;
}
