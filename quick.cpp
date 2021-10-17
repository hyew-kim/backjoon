#include <iostream>
#include <algorithm>

using namespace std;

int arr[] = { -1, 3, 0,2,16,-4 };
int n = 6;

int main(void)
{
	int r = n - 1;
	int l = 0;
	int pivot = arr[0];

	while (l <= r)
	{
		while (arr[r] >= pivot)
			r--;
		while (arr[l] <= pivot)
			l++;
		swap(arr[r], arr[l]);
	}
	swap(arr[0], arr[r]);
}