void insertion_sort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int tmp = arr[i];
		int p = i;

		while (p > 0 && arr[p - 1] > tmp) {
			arr[p] = arr[p - 1];
			p--;
		}

		arr[p] = tmp;
	}
}
