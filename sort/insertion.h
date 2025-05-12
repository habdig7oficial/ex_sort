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




int bin_search(int arr[], int len, int key) {
  int min = 0;
  int max = len - 1;

  while (min <= max) {
    int mid = (max + min) / 2;

    if (arr[mid] < key) {
      min = mid + 1;
    } else {
      max = mid - 1;
    }
  }

  return min;
}

void insertion_sort_bin(int arr[], int len) {
  for (int i = 1; i < len; i++) {
    int key = arr[i];
    int j = bin_search(arr, i, key);

    // Deslocar os elementos para a direita
    for (int k = i; k > j; k--) {
      arr[k] = arr[k - 1];
    }

    arr[j] = key;
  }
}

