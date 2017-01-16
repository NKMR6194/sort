void quick_sort(int arr[], int size) {
	int piv = arr[0];
	int i = 1;
	int p = size - 1;

	if (size <= 1) {
		return;
	}

	while (true) {
		while (arr[i] < piv) {
			i++;
		}
		while (arr[p] > piv) {
			p--;
		}

		if (i < p) {
			int tmp = arr[i];
			arr[i] = arr[p];
			arr[p] = tmp;
		}
		else {
			break;
		}
	}

	arr[0] = arr[p];
	arr[p] = piv;
	quick_sort(arr, p);
	quick_sort(&arr[p + 1], size - p - 1);
}
