#ifndef _DATA_STRUCTURE_SORTFUNCTIONS_H_
#define _DATA_STRUCTURE_SORTFUNCTIONS_H_

#include "HeapSort.h"

class SortFunctions
{
public:
	static void Bubble(int *arr, int n);
	static void Selection(int *arr, int n);
	static void Insertion(int *arr, int n);
	static void MergeSort(int *arr, int n);
	static void MergeBU(int *arr, int n);
	static void Quick(int *arr, int n);
	static void MaxHeapSort(int *arr, int n);
	static void MinHeapSort(int *arr, int n);

private:
	void __MergeSort(int *arr, int l, int r);
	void __Merge(int *arr, int l, int mid, int r);
	void __Quick(int *arr, int l, int r);
	int __patitions(int *arr, int l, int r);
	int __patitions2(int *arr, int l, int r);
};

void SortFunctions::Bubble(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j+1])
				std::swap(arr[j], arr[j+1]);
}

void SortFunctions::Selection(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[minIndex] > arr[j])
				minIndex = j;
		}
		std::swap(arr[i], arr[minIndex]);
	}
}
void SortFunctions::Insertion(int *arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int e = arr[i];
		int j = i;;
		for (; j > 0 && (e < arr[j - 1]); j--)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
}
void SortFunctions::MergeSort(int *arr, int n)
{
	assert(arr != nullptr && n > 0);
	SortFunctions s;
	s.__MergeSort(arr, 0, n - 1);
}
void SortFunctions::MergeBU(int *arr, int n)
{
	SortFunctions s;
	for (int sz = 1; sz <= n; sz += sz)
	{
		for (int i = 0; i < n - sz; i += sz + sz)
		{
			if (arr[i + sz - 1] > arr[i + sz])
				s.__Merge(arr, i, i + sz - 1, std::min(sz + sz + i - 1, n - 1));
		}
	}
}
void SortFunctions::Quick(int *arr, int n)
{
	assert(arr != nullptr && n > 0);
	srand((unsigned int)time(NULL));
	SortFunctions s;
	s.__Quick(arr, 0, n - 1);
}
void SortFunctions::MaxHeapSort(int *arr, int n)
{
	MaxHeap<int> maxHeap(arr,n);
	for (int i = n - 1; i >= 0; i--)
	{
		arr[i] = maxHeap.extractMax();
	}

}
void SortFunctions::MinHeapSort(int *arr, int n)
{
	MinHeap<int> minHeap(arr, n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = minHeap.extractMin();
	}
}

void SortFunctions::__MergeSort(int *arr, int l, int r)
{
	if (l >= r)
		return;
	int mid = l + (r - l) / 2;
	__MergeSort(arr, l, mid);
	__MergeSort(arr, mid+1, r);
	__Merge(arr, l, mid, r);
}
void SortFunctions::__Merge(int *arr, int l, int mid, int r)
{
	int *aux = new int[r - l + 1];
	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > mid)
		{
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r)
		{
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] > aux[j - l])
		{
			arr[k] = aux[j - l];
			j++;
		}
		else
		{
			arr[k] = aux[i - l];
			i++;
		}
	}
	delete[] aux;
}
void SortFunctions::__Quick(int *arr, int l, int r)
{
	if (l >= r)
		return;
	int p = __patitions2(arr, l, r);
	__Quick(arr, l, p - 1);
	__Quick(arr, p + 1, r);
}
int SortFunctions::__patitions(int *arr, int l, int r)
{
	std::swap(arr[l], arr[rand() % (r - l + 1)+l]);
	int j = l;
	int v = arr[l];
	for (int i = l; i <= r; i++)
	{
		if (arr[i] < v)
		{
			j++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[l], arr[j]);
	return j;
}

int SortFunctions::__patitions2(int *arr, int l, int r)
{
	std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
	int i = l + 1, j = r;
	int v = arr[l];
	while (true)
	{
		while (arr[i] < v && i <= r)
			i++;
		while (arr[j] > v && j >= l + 1)
			j--;
		if (i >= j)
			break;
		std::swap(arr[i], arr[j]);
		i++;
		j--;
	}
	std::swap(arr[l], arr[j]);
	return j;
}
#endif // !_DATA_STRUCTURE_SORTFUNCTIONS_H_
