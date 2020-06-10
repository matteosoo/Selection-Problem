// C++ implementation of worst case linear time algorithm 
// to find k'th smallest element 
#include<iostream> 
#include<climits> 

#include <vector>
#include <fstream>
#include <iomanip>
using namespace std::chrono;
using namespace std;

int partition(vector<int>& arr, int l, int r, int k);

// A simple function to find median of arr[]. This is called 
// only for an array of size 5 in this program. 
void merge(vector<int>& arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(vector<int>& arr, int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
int findMedian(vector<int>& arr, int start_indx, int n) 
{ 
	mergeSort(arr, start_indx, n - 1);
	return arr[n/2]; // Return middle element 
} 

// Returns k'th smallest element in arr[l..r] in worst case 
// linear time. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT 
int kthSmallest(vector<int>& arr, int l, int r, int k) 
{
	// If k is smaller than number of elements in array 
	if (k > 0 && k <= r - l + 1) 
	{ 
		int n = r-l+1; // Number of elements in arr[l..r] 

		// Divide arr[] in groups of size 5, calculate median 
		// of every group and store it in median[] array. 
		int i;
		vector<int> median((n+4)/5); // There will be floor((n+4)/5) groups; 
		// vector<int>::const_iterator first = arr.begin() + l+i*5;

		for (i=0; i<n/5; i++) 
		{
			// vector<int> sub_arr(first, first+5);
			// median[i] = findMedian(sub_arr, 5); 
			median[i] = findMedian(arr, l+i*5, 5);
		}
		if (i*5 < n) //For last group with less than 5 elements 
		{ 
			// vector<int> sub_arr(first, first+(n%5));
			// median[i] = findMedian(sub_arr, n%5); 
			median[i] = findMedian(arr, l+i*5, n%5);
			i++; 
		}

		// Find median of all medians using recursive call. 
		// If median[] has only one element, then no need 
		// of recursive call 
		int medOfMed = (i == 1)? median[i-1]: 
								kthSmallest(median, 0, i-1, i/2); 
		
		// Partition the array around a random element and 
		// get position of pivot element in sorted array 

		int pos = partition(arr, l, r, medOfMed);

		// If position is same as k 
		if (pos-l == k-1) 
			return arr[pos]; 
		if (pos-l > k-1) // If position is more, recur for left 
			return kthSmallest(arr, l, pos-1, k); 

		// Else recur for right subarray 
		return kthSmallest(arr, pos+1, r, k-pos+l-1); 
	} 

	// If k is more than number of elements in array 
	return INT_MAX; 
} 

void swap(int &a, int &b) 
{ 
	int temp = a; 
	a = b; 
	b = temp; 
} 

// It searches for x in arr[l..r], and partitions the array 
// around x. 
int partition(vector<int>& arr, int l, int r, int x) 
{ 
	// Search for x in arr[l..r] and move it to end 
	int i; 
	for (i=l; i<r; i++) 
		if (arr[i] == x) 
		break; 
	swap(arr[i], arr[r]); 

	// Standard partition algorithm 
	i = l; 
	for (int j = l; j <= r - 1; j++) 
	{ 
		if (arr[j] <= x) 
		{ 
			swap(arr[i], arr[j]); 
			i++; 
		} 
	} 
	swap(arr[i], arr[r]); 
	return i; 
} 

// Driver program to test above methods 
int main(int argc, char* argv[]) 
{ 
	freopen(argv[1], "r", stdin);
	int n, k;
	std::cin >> n >> k;
	std::cout << n << " " << k << endl;

	vector<int> arr(n); 
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	// prune & search method (ps)
	auto ps_start = high_resolution_clock::now();
	int ps_result = kthSmallest(arr, 0, n - 1, k);
	auto ps_stop = high_resolution_clock::now();
	auto ps_duration = duration_cast<nanoseconds>(ps_stop - ps_start);
	
	// write file to PS.txt
	ofstream ps_output_file("PS.txt");
	ps_output_file << ps_result << endl;
	float ps_time = (ps_duration.count())/(1e+9);
	ps_output_file << std::fixed << std::setprecision(6) << ps_time;
	ps_output_file.close();

	// screan output
	std::cout << "K-th smallest element is "	<< ps_result << endl; 
	std::cout << "Running time of the program " << std::fixed << std::setprecision(6) << ps_time << " s" << endl;
	return 0; 
} 

