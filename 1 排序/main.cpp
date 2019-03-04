#include "SortHelpTools.h"
#include "SortFunctions.h"

int main()
{
	int *arr1 = nullptr;
	int n = 300000, l = 0, r = 100;
	SortHelpTools::generateNIntRandomArray(&arr1, n, l, r);
	SortHelpTools::SortRes("Bubble Sort", SortFunctions::MinHeapSort, arr1, n);
	return 0;
}