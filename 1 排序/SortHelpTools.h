#ifndef _DATA_STRUCTURE_SORTHELPTOOLS_H_
#define _DATA_STRUCTURE_SORTHELPTOOLS_H_
#include <string>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <iostream>

typedef void(*sortDef)(int arr[], int n);

class SortHelpTools
{
public:
	static int generateNIntRandomArray(int **arr/*out*/,int n, int l, int r);
	static int genetateNIntNearlyOrderedArray(int **arr/*out*/, int n, int swaptimes);
	static bool isSorted(int *arr, int n);
	static void SortRes(std::string sortname, sortDef sorfunc, int *arr, int n);
};

int SortHelpTools::generateNIntRandomArray(int **arr/*out*/, int n, int l, int r)
{
	assert(n > 0 && l <= r);
	if (*arr != nullptr)
		delete *arr;
	srand((unsigned int)time(NULL));

	int *arrTmp = new int[n];
	if (arrTmp == nullptr)
		return -1;
	memset(arrTmp, 0, (sizeof(int)*n));
	for (int i = 0; i < n; i++)
	{
		arrTmp[i] = rand() % (r - l + 1);
	}
	*arr = arrTmp;
	return 0;
}
int SortHelpTools::genetateNIntNearlyOrderedArray(int **arr/*out*/, int n, int swaptimes)
{
	assert(n > 0 && swaptimes >= 0);
	srand((unsigned int)time(NULL));
	if (*arr != nullptr)
		delete *arr;
	int *arrTmp = new int[n];

	if (arrTmp == nullptr)
		return -1;
	memset(arrTmp, 0, (sizeof(int)*n));

	for (int i = 0; i < n; i++)
		arrTmp[i] = i + 1;
	for (int i = 0; i < swaptimes; i++)
	{
		int posX = rand() % n;
		int posY = rand() % n;
		std::swap(arrTmp[posX], arrTmp[posY]);
	}
	*arr = arrTmp;
	return 0;
}
bool SortHelpTools::isSorted(int *arr, int n)
{
	assert(arr != nullptr && n > 0);
	for (int i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
			return false;
	return true;
}
void SortHelpTools::SortRes(std::string sortname, sortDef sorfunc, int *arr, int n)
{
	assert(!sortname.empty() && sorfunc != nullptr && arr != nullptr && n > 0);
	clock_t startTime, endTime;
	startTime = clock();
	sorfunc(arr, n);
	endTime = clock();
	if (isSorted(arr, n))
		std::cout << sortname << ": sort success... times:" << ((double)(endTime - startTime) / CLOCKS_PER_SEC) << " s." << std::endl;
	else
		std::cout << sortname << ": sort failed..." << std::endl;
}
#endif // !_DATA_STRUCTURE_SORTHELPTOOLS_H_
