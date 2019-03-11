#include "Sort.h"

// Pauses for a specified number of milliseconds.
void do_sleep(clock_t wait)
{
	clock_t goal;
	goal = wait + clock();
	while (goal > clock())
		;
}


void selection_sort(int arr[], int n)
{
	int i, j, index, temp = 0;

	for (i = 0; i < n - 1; i++)
	{
		index = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[index] > arr[j])
			{
				index = j;
			}
		}
		SWAP(arr[i], arr[index], temp);
	}
}

void selection_sort_recursive(int arr[], int i, int n)
{
	int j, index, temp = 0;

	if(i < n - 1)
	{
		index = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[index] > arr[j])
			{
				index = j;
			}
		}
		SWAP(arr[i], arr[index], temp);
		selection_sort_recursive(arr, i + 1, n);
	}
}

void bubble_sort(int arr[], int n)
{
	int i, j, temp = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < (n - i) - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				SWAP(arr[j], arr[j + 1], temp);
			}
		}
	}
}

void insertion_sort(int arr[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int partition(int arr[], int start, int end)
{
	int pivot = arr[(start + end) / 2];
	int temp = 0;

	while (start <= end)
	{
		while (arr[start] < pivot) start++;
		while (arr[end] > pivot) end--;

		if (start <= end)
		{
			SWAP(arr[start], arr[end], temp);
			start++;
			end--;
		}
	}
	return start;
}

void quick_sort(int arr[], int start, int end)
{
	int part2 = partition(arr, start, end);

	if (part2 - 1 > start)
	{
		quick_sort(arr, start, part2 - 1);
	}
	if (part2 < end)
	{
		quick_sort(arr, part2, end);
	}
}

void merge(int arr[], int temp[], int start, int mid, int end)
{
	int i;
	int part1, part2;
	int index;

	/*�ӽ� ����ҿ� ������ �� �迭�� �ʿ��� ��ŭ ���縦 ���ش�.*/
	for (i = start; i <= end; i++)
	{
		temp[i] = arr[i];
	}

	//part1 : 1��° �迭�� ���� ��ġ[���� �迭�� 1��° ����� ���� ��ġ][����: start ~ mid]
	//part2 : 2��° �迭�� ���� ��ġ[���� �迭�� 2��° ����� ���� ��ġ][����: mid + 1 ~ end]
	//index : �迭�� ���� ��ġ�� ����Ű�� ����
	part1 = start;
	part2 = mid + 1;
	index = start;

	//�ΰ��� �迭�ȿ��� ����� ���� ���� ���� ���� ���Ͽ� ���Ľ�ų �迭�� �����Ѵ�.
	while (part1 <= mid && part2 <= end)
	{
		if (temp[part1] < temp[part2])
		{
			arr[index++] = temp[part1++];
		}
		else
		{
			arr[index++] = temp[part2++];
		}
	}

	if (part1 > mid)
	{
		//������ �������� ���� �迭�� �����Ͱ� ���� �ִ� ��� �迭�� �ٿ��ش�.
		for (i = part2; i <= end; i++)
		{
			arr[index++] = temp[i];
		}
	}
	else
	{
		//������ �������� ���� �迭�� �����Ͱ� ���� �ִ� ��� �迭�� �ٿ��ش�.
		for (i = part1; i <= mid; i++)
		{
			arr[index++] = temp[i];
		}
	}
}

void merge_sort_implement(int arr[], int temp[], int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		merge_sort_implement(arr, temp, start, mid);
		merge_sort_implement(arr, temp, mid + 1, end);
		merge(arr, temp, start, mid, end);
	}
}

void merge_sort(int arr[], int start, int end)
{
	int temp[MAX_SIZE] = { 0, };
	merge_sort_implement(arr, temp, 0, MAX_SIZE - 1);
	//merge_sort_u(arr, temp, 0, MAX_SIZE - 1);

}


void Test(const char* sort_type)
{
	int arr[MAX_SIZE] = { 0, };
	int i;
	clock_t start, end;
	double duration;

	srand((unsigned int)time(NULL));

	for (i = 0; i < MAX_SIZE; i++)
	{
		arr[i] = rand() % MAX_SIZE;
	}

	printf("[Before]\n");
	for (i = 0; i < MAX_SIZE; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n\n");

	if (strcmp(sort_type, "Selection sort") == 0)
	{
		start = clock();
		selection_sort(arr, MAX_SIZE);
		end = clock();

		duration = (double)(end - start) / CLOCKS_PER_SEC;
		printf("[After :: \"Selection Sort\"]\n");
		for (i = 0; i < MAX_SIZE; i++)
		{
			printf("%d, ", arr[i]);
		}
		//do_sleep((clock_t)3 * CLOCKS_PER_SEC);
		printf("\n\n[Sort Time : %2.5lf second]\n", duration);
	}	
	else if (strcmp(sort_type, "Bubble sort") == 0)
	{
		start = clock();
		bubble_sort(arr, MAX_SIZE);
		end = clock();

		duration = (double)(end - start) / CLOCKS_PER_SEC;
		printf("[After :: \"Bubble Sort\"]\n");
		for (i = 0; i < MAX_SIZE; i++)
		{
			printf("%d, ", arr[i]);
		}
		//do_sleep((clock_t)3 * CLOCKS_PER_SEC);
		printf("\n\n[Sort Time : %2.5lf second]\n", duration);
	}	
	else if (strcmp(sort_type, "Insertion Sort") == 0)
	{
		start = clock();
		insertion_sort(arr, MAX_SIZE);
		end = clock();

		duration = (double)(end - start) / CLOCKS_PER_SEC;
		printf("[After :: \"Insertion Sort\"]\n");
		for (i = 0; i < MAX_SIZE; i++)
		{
			printf("%d, ", arr[i]);
		}
		//do_sleep((clock_t)3 * CLOCKS_PER_SEC);
		printf("\n\n[Sort Time : %2.5lf second]\n", duration);
	}	
	else if (strcmp(sort_type, "Quick sort") == 0)
	{
		start = clock();
		quick_sort(arr, 0, MAX_SIZE - 1);
		end = clock();

		duration = (double)(end - start) / CLOCKS_PER_SEC;
		printf("[After :: \"Quick Sort\"]\n");
		for (i = 0; i < MAX_SIZE; i++)
		{
			printf("%d, ", arr[i]);
		}
		//do_sleep((clock_t)3 * CLOCKS_PER_SEC);
		printf("\n\n[Sort Time : %2.5lf second]\n", duration);
	}	
	else if (strcmp(sort_type, "Merge sort") == 0)
	{
		start = clock();
		merge_sort(arr, 0, MAX_SIZE - 1);
		end = clock();

		duration = (double)(end - start) / CLOCKS_PER_SEC;
		printf("[After :: \"Merge Sort\"]\n");
		for (i = 0; i < MAX_SIZE; i++)
		{
			printf("%d, ", arr[i]);
		}
		//do_sleep((clock_t)3 * CLOCKS_PER_SEC);
		printf("\n\n[Sort Time : %2.5lf second]\n", duration);
	}	
}