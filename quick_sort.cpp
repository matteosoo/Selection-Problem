// CPP program for implementation of QuickSelect 
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std::chrono;
using namespace std;

// Standard partition process of QuickSort(). 
// It considers the last element as pivot 
// and moves all smaller element to left of 
// it and greater elements to right 
int partition(vector<int>& arr, int l, int r) 
{ 
	int x = arr[r], i = l; 
	for (int j = l; j <= r - 1; j++) { 
		if (arr[j] <= x) { 
			swap(arr[i], arr[j]); 
			i++; 
		} 
	} 
	swap(arr[i], arr[r]); 
	return i; 
} 

// This function returns k'th smallest 
// element in arr[l..r] using QuickSort 
// based method. ASSUMPTION: ALL ELEMENTS 
// IN ARR[] ARE DISTINCT 
int kthSmallest(vector<int>& arr, int l, int r, int k) 
{ 
	// If k is smaller than number of 
	// elements in array 
	if (k > 0 && k <= r - l + 1) { 

		// Partition the array around last 
		// element and get position of pivot 
		// element in sorted array 
		int index = partition(arr, l, r); 

		// If position is same as k 
		if (index - l == k - 1) 
			return arr[index]; 

		// If position is more, recur 
		// for left subarray 
		if (index - l > k - 1) 
			return kthSmallest(arr, l, index - 1, k); 

		// Else recur for right subarray 
		return kthSmallest(arr, index + 1, r, 
							k - index + l - 1); 
	} 

	// If k is more than number of 
	// elements in array 
	return INT_MAX; 
} 

// Driver program to test above methods 
int main(int argc, char* argv[]) 
{ 
	freopen(argv[1], "r", stdin);
	int n, k;
	std::cin >> n >> k;
	cout << n << " " << k << endl;

	vector<int> arr(n); 
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	
	// check out array
	// for (int i = 0; i < n; i++)
	// 	std::cout << arr[i] << " " << std::ends;
	// cout << endl;

	// quick sort method (qs)
	auto qs_start = high_resolution_clock::now();
	int qs_result = kthSmallest(arr, 0, n - 1, k);
	auto qs_stop = high_resolution_clock::now();
	auto qs_duration = duration_cast<nanoseconds>(qs_stop - qs_start);
	
	// write file to QS.txt
	ofstream qs_output_file("QS.txt");
	qs_output_file << qs_result << endl;
	float qs_time = (qs_duration.count())/(1e+9);
	qs_output_file << std::fixed << std::setprecision(6) << qs_time;
	qs_output_file.close();

	// screan output
	cout << "K-th smallest element is "	<< qs_result << endl; 
	cout << "Running time of the program " << std::fixed << std::setprecision(6) << qs_time << endl;
	return 0; 
} 

