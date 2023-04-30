#include <iostream>

void bubble(int arr[], int size)
{
	bool b = false;

	while (!b)
	{
		b = true;
		for (int i = 0; i < size - 1; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				b = false;
				arr[i] += arr[i + 1];
				arr[i + 1] = arr[i] - arr[i + 1];
				arr[i] -= arr[i + 1];
			}
		}
	}
}

void selection(int arr[], int size)
{
	int min = arr[0];
	int minIndex = 0;

	for (int j = 0; j < size - 1; ++j)
	{
		for (int i = j + 1; i < size; ++i)
		{
			if (min > arr[i])
			{
				minIndex = i;
				min = arr[i];
			}
		}
		if (j != minIndex)
		{
			arr[j] += arr[minIndex];
			arr[minIndex] = arr[j] - arr[minIndex];
			arr[j] -= arr[minIndex];
		}
		min = arr[j + 1];
	}
}

void bubbleRec(int arr[], int size)
{
	bool b = true;

	for (int i = 0; i < size - 1; ++i)
	{
		if (arr[i] > arr[i + 1])
		{
			b = false;
			arr[i] += arr[i + 1];
			arr[i + 1] = arr[i] - arr[i + 1];
			arr[i] -= arr[i + 1];
		}
	}
	if (!b)
		bubbleRec(arr, size);
}

void selectionRec(int arr[], int size, int min)
{
	int minIndex = 0;

	for (int i = 0; i < size; ++i)
	{
		if (min > arr[i])
		{
			minIndex = i;
			min = arr[i];
		}
	}
	if (minIndex)
	{
		arr[0] += arr[minIndex];
		arr[minIndex] = arr[0] - arr[minIndex];
		arr[0] -= arr[minIndex];
	}
	min = arr[1];
	if (size - 1)
		selectionRec(arr + 1, size - 1, min);
}

void insertion(int arr[], int size)
{
	if (size < 2)
		return;
	for (int i = 1, j = i; i < size; ++i, j = i)
	{
		while (arr[i] < arr[i - 1])
		{
			arr[i] += arr[i - 1];
			arr[i - 1] = arr[i] - arr[i - 1];
			arr[i] -= arr[i - 1];
			--i;
			if (i < 1)
				break;
		}
		i = j;
	}
}

void insertionRec(int arr[], int size)
{
	if (size < 2)
		return;
	insertionRec(arr, size - 1);

	int i = size - 1;
	while (arr[i] < arr[i - 1])
	{
		arr[i] += arr[i - 1];
		arr[i - 1] = arr[i] - arr[i - 1];
		arr[i] -= arr[i - 1];
		--i;
		if (i < 1)
			break;
	}
}

int main()
{
	int arr[]{ 5, 3, 7, 6, 9, 2, 1, 5, 8, 9 };

	bubble(arr, 10);

	for (int i = 0; i < 10; ++i)
		std::cout << arr[i] << ' ';
	std::cout << '\n';

	int arr2[]{ 5, 3, 7, 6, 9, 2, 1, 5, 8, 9 };

	selection(arr2, 10);

	for (int i = 0; i < 10; ++i)
		std::cout << arr2[i] << ' ';
	std::cout << '\n';

	int arr3[]{ 5, 3, 7, 6, 9, 2, 1, 5, 8, 9 };

	bubbleRec(arr3, 10);

	for (int i = 0; i < 10; ++i)
		std::cout << arr3[i] << ' ';
	std::cout << '\n';

	int arr4[]{ 5, 3, 7, 6, 9, 2, 1, 5, 8, 9 };

	selectionRec(arr4, 10, INT_MAX);

	for (int i = 0; i < 10; ++i)
		std::cout << arr4[i] << ' ';
	std::cout << '\n';

	int arr5[]{ 5, 3, 7, 6, 9, 2, 1, 5, 8, 9 };

	insertion(arr5, 10);

	for (int i = 0; i < 10; ++i)
		std::cout << arr5[i] << ' ';
	std::cout << '\n';

	int arr6[]{ 5, 3, 7, 6, 9, 2, 1, 5, 8, 9 };

	insertionRec(arr6, 10);

	for (int i = 0; i < 10; ++i)
		std::cout << arr6[i] << ' ';
	std::cout << '\n';

	return 0;
}