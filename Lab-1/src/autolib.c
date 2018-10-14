#include "../include/extralib.h"
#include "../include/autolib.h"

int automatic_processing(char* data, int choice)
{
  int result = 0;
  switch (choice) {
    case 1:
      printf("First automatic was choosen\n");
      unsigned_automatic(data, 0, &result);
      break;
    case 2:
      printf("Second automatic was choosen\n");
      fiveletter_automatic(data, 0, &result);
      break;
    case 3:
      printf("Third automatic was choosen\n");
      ordered_automatic(data, 0, &result);
      break;
    case 4:
      printf("Fourth automatic was choosen\n");
      evenodd_automatic(data, 0, &result);
      break;
    case 5:
      printf("Fifth automatic was choosen\n");
      excludeSubstring_automatic(data, 0, &result);
      break;
    case 6:
      printf("Sixth automatic was choosen\n");
      excludeSubsequence_automatic(data, 0, &result);
      break;
  }
  return result;
}

void unsigned_automatic(char* data, int position, int* result)
{
  char *tokens[14] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "-", ".", "E"};
  printf("Scanning %d position\n", position+1);

  if (position == 0) {
    if (data[position] == *tokens[position]) {
      printf(">   %c\n", *tokens[position]);
      if (data[position + 1] == *tokens[12]) {
        unsigned_automatic(data, ++position, result);
        return;
      } else {
        --*result;
        return;
      }
    }
    for (int i = 1; i < 10; ++i) {
      if (data[position] == *tokens[i]) {
        printf(">   %c\n", *tokens[i]);
        unsigned_automatic(data, ++position, result);
        return;
      }
    }
    --*result;
  }
  if (data[position] == '\n' || data[position] == '\0') {
    printf(">   EOF\n");
    return;
  }
  for (int i = 0; i < 14; ++i) {
    if (data[position] == *tokens[i]) {
      if ((i > 9) && (i < 12)) {
        printf(">   %c\n", *tokens[i]);
        if (data[position - 1] == *tokens[13]) {
          unsigned_automatic(data, ++position, result);
          return;
        } else {
          --*result;
          return;
        }
      } else if (i == 13) {
        printf(">   %c\n", *tokens[i]);
        for (int j = 0; j < 10; ++j) {
          if (data[position - 1] == *tokens[j]) {
            unsigned_automatic(data, ++position, result);
            return;
          }
        }
        --*result;
      } else if (i == 12) {
        printf(">   %c\n", *tokens[i]);
        if (*result <= 0) {
          ++*result;
          unsigned_automatic(data, ++position, result);
          --*result;
          return;
        } else {
          --*result;
          break;
        }
      } else {
        printf(">   %c\n", *tokens[i]);
        unsigned_automatic(data, ++position, result);
        return;
      }
    }
  }
  --*result;
}

void fiveletter_automatic(char* data, int position, int* result)
{
  --*result;
}

void ordered_automatic(char* data, int position, int* result)
{
  --*result;
}

void evenodd_automatic(char* data, int position, int* result)
{
  --*result;
}

void excludeSubstring_automatic(char* data, int position, int* result)
{
  --*result;
}

void excludeSubsequence_automatic(char* data, int position, int* result)
{
  --*result;
}
