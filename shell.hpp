// Sedgewick Gap sequences, Worst-case O(n^(4/3))
int __shell_h(int s) {
	if (s % 2 == 0) {
		return 9 * pow(2, s) - 9 * pow(2, s/2) + 1;
	}
	else {
		return 8 * pow(2, s) - 6 * pow(2, (s+1)/2) + 1;
	}
}

void shell_sort(int arr[], int size) {
	int s = 0;
	while (__shell_h(s+1) < size) {
		s++;
	}

	while (s >= 0) {
		int h = __shell_h(s);

		for (int p = h; p < size; p++) {
			int i = p - h;
			int tmp = arr[p];
			while (i >= 0 && tmp < arr[i]) {
				arr[i + h] = arr[i];
				i -= h;
			}

			arr[i + h] = tmp;
		}
		s--;
	}
}
