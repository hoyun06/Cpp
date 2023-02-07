#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1000001];
int res[1000001];


void merge(int start, int mid, int end)
{
	int i = start, j = mid + 1, k = start;

	for (i; i <= end; i++)
		res[i] = arr[i];

	i = start;

	while (i <= mid && j <= end)
	{
		if (res[i] <= res[j])
			arr[k++] = res[i++];
		else
			arr[k++] = res[j++];
	}

	if (i > mid)
	{
		while (j <= end)
			arr[k++] = res[j++];
	}
	else
	{
		while (i <= mid)
			arr[k++] = res[i++];
	}

	for (int i = start; i <= end; i++)
		res[i] = 0;
}

void mergeSort(int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge(start, mid, end);
	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);	

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	if (n == 1)
	{
		cout << arr[0];
		return 0;
	}

	mergeSort(0, n - 1);

	for (int i = 0; i < n; i++) cout << arr[i] << "\n";
	return 0;
}
