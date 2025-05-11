#include "stdbool.h"
#include "stdlib.h"
#include "time.h"

int partition(int arr[], int begin, int end) {
  int pivo = arr[end - 1];
  int i = begin - 1;
  for (int j = begin; j < end - 1; j++) {
    if (arr[j] <= pivo) {
      i++;
      int aux = arr[i];
      arr[i] = arr[j];
      arr[j] = aux;
    }
  }
  int aux = arr[i + 1];
  arr[i + 1] = arr[end - 1];
  arr[end - 1] = aux;
  return i + 1;
}

void quick_sort(int arr[], int begin, int end, bool is_rand) {
  if (begin >= end - 1)
    return;

  if (is_rand) {
    srand(time(NULL));
    int random_index = begin + rand() % (end - begin);
    int aux = arr[random_index];
    arr[random_index] = arr[end - 1];
    arr[end - 1] = aux;
  }

  int pivo_index = partition(arr, begin, end);
  quick_sort(arr, begin, pivo_index, is_rand);
  quick_sort(arr, pivo_index + 1, end, is_rand);
}