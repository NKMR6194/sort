#include <bits/stdc++.h>

#include "./counting.hpp"
#include "./insertion.hpp"
#include "./quick.hpp"
#include "./bubble.hpp"

using namespace std;

#define ARRAY_ASC {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100}
#define ARRAY_ASC_SIZE 100

#define ARRAY_DESC {100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}
#define ARRAY_DESC_SIZE 100

#define ARRAY_SAMPLE {78,23,44,25,6,72,95,31,21,89,5,99,60,91,71,37,93,43,57,90,84,97,42,4,100,65,27,68,2,29,70,17,54,16,10,62,80,75,79,51,63,3,73,22,24,67,86,66,59,47,1,35,87,34,15,19,58,52,69,13,45,39,32,14,81,49,26,61,77,38,8,40,7,88,28,74,18,12,56,30,94,76,20,82,11,83,64,85,48,53,46,50,36,9,96,92,98,33,55,41}
#define ARRAY_SAMPLE_SIZE 100

int fail;

void print_fail() {
	cout << "fail: " << fail << endl;
	if (fail == 0) {
		cout << "Pass all cases." << endl;
	}
}

void print_arr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

bool is_sorted(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		if (arr[i - 1] > arr[i]) {
			return false;
		}
	}
	return true;
}

void test_case(string name, void (*sort)(int [], int), int array[], int size) {
	int arr[size];

	memcpy(arr, array, sizeof(int) * size);
	(*sort)(arr, size);

	if (is_sorted(arr, size)) {
		cout << name << ":\tpass" << endl;
	}
	else {
		fail++;
		cout << name << ":\tfail" << endl;
		cout << "  input: "; print_arr(array, size);
		cout << "  output: "; print_arr(arr, size);
	}
}

void gen_random_array(int array[], int size) {
	std::random_device rnd;
	std::mt19937 random(rnd());
	for (int i = 0; i < size; i++) {
		array[i] = random();
	}
}

void test(string name, void (*sort)(int [], int)) {
	int asc[]    = ARRAY_ASC;
	int desc[]   = ARRAY_DESC;
	int sample[] = ARRAY_SAMPLE;
	int rand_arr[100];

	gen_random_array(rand_arr, 100);

	cout << name << " sort" << endl;
	test_case(   "ARRAY_ASC", sort,      asc,    ARRAY_ASC_SIZE);
	test_case(  "ARRAY_DESC", sort,     desc,   ARRAY_DESC_SIZE);
	test_case("ARRAY_SAMPLE", sort,   sample, ARRAY_SAMPLE_SIZE);
	test_case("random_array", sort, rand_arr,               100);

	int arr[] = {3,4,2,5,6,1,7};
	(*sort)(arr, 7);
	print_arr(arr, 7);

	cout << endl;
}

int main() {
	test("counting", counting_sort);
	test("insertion", insertion_sort);
	test("quick", quick_sort);
	test("bubble", bubble_sort);

	print_fail();
}
