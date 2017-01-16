#include <bits/stdc++.h>

#include "./counting.hpp"
#include "./insertion.hpp"
#include "./quick.hpp"

using namespace std;

void sort(int arr[], int size) {
	quick_sort(arr, size);
}

void print_arr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[] = {3,4,2,5,6,1,7};
	sort(arr, 7);
	print_arr(arr, 7);
}
