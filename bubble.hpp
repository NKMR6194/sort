void bubble_sort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int swap_count = 0;

		for (int p = size - 1; p > i; p--) {
			if (arr[p] < arr[p - 1]) {
				int tmp = arr[p];
				arr[p] = arr[p - 1];
				arr[p - 1] = tmp;
				swap_count++;
			}
		}

		if (swap_count == 0) {
			break;
		}
	}
}
