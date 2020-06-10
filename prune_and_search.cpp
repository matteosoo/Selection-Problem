#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std::chrono;
using namespace std;

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

void swap(int &a, int &b) 
{ 
	int temp = a; 
	a = b; 
	b = temp; 
} 

int arr[100000]; //imput size only 10000 to 30000 in steps 1000

int main(int argc, char* argv[]) 
{
	freopen(argv[1], "r", stdin);
	int n, k;
	std::cin >> n >> k;
	cout << n << " " << k << endl;

    for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

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

	// screan output
	std::cout << "K-th smallest element is "	<< ps_result << endl; 
	std::cout << "Running time of the program " << std::fixed << std::setprecision(6) << ps_time << " s" << endl;
    return 0;
}