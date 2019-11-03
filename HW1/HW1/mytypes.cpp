#include "mytypes.h"

using namespace std;


int binarySearch(int *arr, int size, int num) //בודק אם מספר הנתון מופיע במערך
{
	int mid;
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (num == arr[mid])
			return mid;
		else if (num > arr[mid])
			low = mid + 1;
		else { high = mid - 1; }
	}
	return -1;
}

int binarySearch(uint *arr, uint size, uint num) //בודק אם מספר הנתון מופיע במערך
{
	int mid;
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (num == arr[mid])
			return mid;
		else if (num > arr[mid])
			low = mid + 1;
		else { high = mid - 1; }
	}
	return -1;
}

void delCell(int *arr, int size, int num)//delets a cell from array
{
	int *temp = new int[size - 1];
	int k = binarySearch(arr, size, num);
	for (int i = 0, j = 0; i < size - 1; i++, j++)
	{
		if (i = k)
			j++;
		temp[i] = arr[j];
	}
	arr = temp;
	delete temp;
}

void delCell(uint *arr, uint size, uint num)//delets a cell from array
{
	uint *temp = new uint[size - 1];
	int k = binarySearch(arr, size, num);
	for (int i = 0, j = 0; i < size - 1; i++, j++)
	{
		if (i = k)
			j++;
		temp[i] = arr[j];
	}
	arr = temp;
	delete temp;
}

void addCell(uint *arr, uint size, uint num)//adds a cell from array
{
	uint *temp = new uint[size + 1];
	int i = 0, j = 0;
	for (i; i < size; i++, j++)
	{
		if (num > arr[i])
			temp[i] = arr[j];
		else
			break;
	}
	if (i == size)
		temp[i + 1] = num;
	else
	{
		temp[i] = num;
		i++;
		for (i; i < size + 1; i++, j++)
			temp[i] = arr[j];
	}
	arr = temp;
	delete temp;
}

void addCell(int *arr, int size, int num)//adds a cell from array
{
	int *temp = new int[size + 1];
	int i = 0, j = 0;
	for (i; i < size; i++, j++)
	{
		if (num > arr[i])
			temp[i] = arr[j];
		else
			break;
	}
	if (i == size)
		temp[i + 1] = num;
	else
	{
		temp[i] = num;
		i++;
		for (i; i < size + 1; i++, j++)
			temp[i] = arr[j];
	}
	arr = temp;
	delete temp;
}

const char* intToString(int num)
{
	stringstream ss;
	string s;
	ss << num;
	ss >> s;
	const char* a= s.c_str();
	return a;
}