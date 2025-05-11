#include "stdlib.h"
#include "stdbool.h"


void insertion_sort(int arr[], int len) {
  for (int i = 1; i < len; i++) {
    int key = arr[i];
    int j;
    for (j = i - 1; j >= 0 && arr[j] > key; j--) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = key;
  }
}
