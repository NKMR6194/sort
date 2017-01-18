void list_sort(int arr[], int size) {
	int copy[size + 1];
	int link[size + 1];

	link[0] = size;
	link[size] = 0;

	memcpy(&copy[1], arr, sizeof(int) * size);

	for (int i = size - 1; i > 0; i--) {
		int x = copy[i];
		int p = 0;
		while (1) {
			if (link[p] == 0) {
				break;
			}
			if (copy[link[p]] >= x) {
				break;
			}

			p = link[p];
		}

		link[i] = link[p];
		link[p] = i;
	}

	for (int i = 0, p = 0; i < size; i++) {
		arr[i] = copy[link[p]];
		p = link[p];
	}
}
