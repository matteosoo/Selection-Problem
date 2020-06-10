#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std::chrono;
using namespace std;

// Standard partition process of QuickSort(). 
// It considers the last element as pivot 
// and moves all smaller element to left of 
// it and greater elements to right 
int partition(int arr[], int l, int r) 
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

void swap(int &a, int &b) 
{ 
	int temp = a; 
	a = b; 
	b = temp; 
} 

// This function returns k'th smallest 
// element in arr[l..r] using QuickSort 
// based method. ASSUMPTION: ALL ELEMENTS 
// IN ARR[] ARE DISTINCT 
int kthSmallest(int arr[], int l, int r, int k) 
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

// prune and search
int selectionAlgorithm(int[], int, int, int);
int medianOfMedians(int[], int, int);
void swap (int &a, int &b);

int selectionAlgorithm(int a[], int l, int r, int k) {
/*
 * k = 0, 1, 2, ...
 * return k-th smallest value.
 */
    if(r-l+1 <= 5) {// insert sort.
        int i, j, v;
        for(i = l+1; i <= r; i++) {
            v = a[i], j = i;
            while(j-1 >= l && a[j-1] > v)
                a[j] = a[j-1], j--;
            a[j] = v;
        } 
        return l+k;
    }
    //printf("%d %d\n", l, r);
    int pivot = medianOfMedians(a, l, r);

    // partition begin.
    swap(a[l], a[pivot]);
    int i, j, t = a[l];
    for(i = l, j = l+1; j <= r; j++) {
        if(a[j] <= t)
            i++, swap(a[i], a[j]);
    }
    swap(a[l], a[i]);
    // partition end.

    int position = i;

    if(position-l == k)    
		return position;
    if(position-l < k)
        return selectionAlgorithm(a, position+1, r, k-(position-l+1));
    else
        return selectionAlgorithm(a, l, position, k);
}

int medianOfMedians(int a[], int l, int r) 
{
    int numMedians = (r-l+4)/5;
    int i, subl, subr;
    int medianIdx;

    for(i = 0; i < numMedians; i++) 
	{
        subl = l + i*5;
        subr = subl + 4;
        if(subr > r)    
			subr = r;
        medianIdx = selectionAlgorithm(a, subl, subr, (subr-subl)/2);
        swap(a[l+i], a[medianIdx]);
    }
    //printf("median %d %d\n", l, r);
    return selectionAlgorithm(a, l, l+numMedians, numMedians/2);
}

int arr[100000]; //imput size only 10000 to 30000 in steps 1000

int main() 
{
	std::ifstream input_file("input.txt");

	int n, k;
	input_file >> n >> k;

    for (int i = 0; i < n; i++)
	{
		input_file >> arr[i];
	}

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

    // prune & search method (ps)
	auto ps_start = high_resolution_clock::now();
	int idx = selectionAlgorithm(arr, 0, n-1, k-1);
	int ps_result = arr[idx];
	auto ps_stop = high_resolution_clock::now();
	auto ps_duration = duration_cast<nanoseconds>(ps_stop - ps_start);

	// write file to PS.txt
	ofstream ps_output_file("PS.txt");
	ps_output_file << ps_result << endl;
	float ps_time = (ps_duration.count())/(1e+9);
	ps_output_file << std::fixed << std::setprecision(6) << ps_time;
	ps_output_file.close();

	
	return 0; 
} 