#include <cstring>
#include <algorithm>

void counting_sort(int arr[], int size) {
	int count[size];
	int copy[size];

	std::fill(count, count + size, 0);

	for (int i = 0; i < size; i++) {
		for (int p = i + 1; p < size; p++) {
			if (arr[i] > arr[p]) {
				count[i]++;
			}
			else {
				count[p]++;
			}
		}
	}

	memcpy(copy, arr, sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		arr[count[i]] = copy[i];
	}
}
