#ifndef _DATA_STRUCTURE_HEAPSORT_H_
#define _DATA_STRUCTURE_HEAPSORT_H_

#include <cassert>
#include <algorithm>

template <typename Item>
class MaxHeap 
{
public:
	MaxHeap(int capacity)
	{
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	MaxHeap(int *arr, int n)
	{
		data = new Item[n + 1];
		capacity = n;
		for (int i = 0; i < n; i++)
			data[i + 1] = arr[i];
		count = n;
		for (int i = count / 2; i >= 1; i--)
			shiftDown(i);
	}
	~MaxHeap()
	{
		delete[] data;
	}
	int size()
	{
		return count;
	}
	bool isEmpty()
	{
		return count == 0;
	}
	void insert(Item item)
	{
		assert(count + 1 <= capacity);
		data[count + 1] = item;
		count++;
		shiftUp(count);
	}
	Item extractMax()
	{
		assert(count > 0);
		Item ret = data[1];
		std::swap(data[1],data[count]);
		count--;
		shiftDown(1);
		return ret;
	}
	Item getMax()
	{
		assert(count > 0);
		return data[1];
	}
private:
	void shiftUp(int k) 
	{
		while (k > 1 && data[k / 2] < data[k])
		{
			std::swap(data[k / 2], data[k]);
			k /= 2;
		}
	}
	void shiftDown(int k)
	{
		while (2 * k <= count)
		{
			int j = 2 * k;
			if (j + 1 <= count && data[j + 1] > data[j])
				j++;
			if (data[k] >= data[j])
				break;
			std::swap(data[k], data[j]);
			k = j;
		}
	}
private:
	Item *data;
	int count;
	int capacity;
};

template <typename Item>
class MinHeap
{
public:
	MinHeap(int capacity)
	{
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	MinHeap(int *arr, int n)
	{
		data = new Item[n + 1];
		capacity = n;
		for (int i = 0; i < n; i++)
			data[i + 1] = arr[i];
		count = n;
		for (int i = count / 2; i >= 1; i--)
			shiftDown(i);
	}
	~MinHeap()
	{
		delete[] data;
	}
	int size()
	{
		return count;
	}
	bool isEmpty()
	{
		return count == 0;
	}
	void insert(Item item)
	{
		assert(count + 1 <= capacity);
		data[count + 1] = item;
		count++;
		shiftUp(count);
	}
	Item extractMin()
	{
		assert(count > 0);
		Item ret = data[1];
		std::swap(data[1], data[count]);
		count--;
		shiftDown(1);
		return ret;
	}
	Item getMin()
	{
		assert(count > 0);
		return data[1];
	}
private:
	void shiftUp(int k)
	{
		while (k > 1 && data[k / 2] > data[k])
		{
			std::swap(data[k / 2], data[k]);
			k /= 2;
		}
	}
	void shiftDown(int k)
	{
		while (2 * k <= count)
		{
			int j = 2 * k;
			if (j + 1 <= count && data[j + 1] < data[j])
				j++;
			if (data[k] <= data[j])
				break;
			std::swap(data[k], data[j]);
			k = j;
		}
	}
private:
	Item *data;
	int count;
	int capacity;
};
#endif // !_DATA_STRUCTURE_HEAPSORT_H_
