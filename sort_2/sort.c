#include "sort.h"

void tic()
{
	tstart = clock();
}

double toc()
{
	return (clock() - tstart) / CLOCKS_PER_SEC;
}

void bubble_sort(int arr[], int N)
{
	int i, j;

	/*N-1번의 패스 수행*/
	for (i = 1; i < N; i++)
	{
		/*배열 내에서 교환 작업을 수행*/
		for(j = 0; j < N - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				SWAP(arr[j], arr[j + 1])
			}
		}
	}
}

void selection_sort(int arr[], int N)
{
	int i;
	int index;

	for (i = 0; i < N - 1; i++)
	{
		index = find_min(arr, i, ARR_RANGE);
		SWAP(arr[index], arr[i]);
	}
}

void insertion_sort_2(int arr[], int N)
{
	int i, j;
	int key;

	for (i = 1; i < N; i++)
	{
		j = i;
		key = arr[j];

		while (j >= 1 && arr[j - 1] > key)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
	}
}

void insertion_sort(int arr[], int N)
{
	int i, j;
	int key;

	//i: 배열의 정렬된 부분의 가장 바깥쪽 값의 위치
	//j: 배열의 정렬되지 않은 부분의 가장 위쪽 부분의 위치
	//key: 정렬된 배열에 새로 삽입될 값(이미 정렬된 배열 내에서 정렬된 순서에 따라 해당 위치로 찾아감)

	/*바깥쪽 for문 :: 이미 정렬된 배열의 부분*/
	//for문이 한번 끝나고 첨자가 하나 증가했을 때 이미 그 범위에 해당하는 부분은 정렬이
	//되어 있는 상태이여야 함.
	for (i = 1; i < N; i++)
	{
		j = i - 1;
		key = arr[i];

		//key값의 위치를 찾아가는 구문
		//아래의 조건들은 1번째, 해당 배열 내의 끝 부분까지 다다랐을때와
		//2번째, 새로이 넣고자 하는 값이 기존의 정렬된 부분의 맨 끝자락, 즉 정렬된 부분에서 가장 큰 값보다 
		//더 큰값일 경우이다.
		while (j >= 0 && arr[j] > key)
		{
			//이부분은 key의 위치를 찾아가기 위해 오른쪽에서 왼쪽으로 key값을 이동시키는 부분이다.
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;

	}
}

//void shell_sort(int arr[], int N)
//{
//	int i, j, k, h;
//	int cur_el;
//	
//	//hk:: 배열을 나누는 간격
//	int hk[] = { 2047, 701, 31, 15, 4, 1, 0};
//
//	for (k = 0; hk[k] != 0; k++)
//	{
//		h = hk[k];
//
//		for (i = h; i < N; i++)
//		{
//			j = i - h; //정렬된 부분의 가장 오른쪽 값의 위치
//			cur_el = arr[i];
//
//			while ((j >= 0) && (arr[j] > cur_el))
//			{
//				arr[j + h] = arr[j];
//				j -= h;
//			}
//			arr[j + h] = cur_el;
//		}
//	}
//}


void shell_sort(int arr[], int N)
{
	int hk[] = { 2047, 701, 31, 15, 4, 1, 0 };
	int key;
	int i, j, k, h;

	for (k = 0; hk[k] != 0; k++)
	{
		h = hk[k];

		for (i = h; i < N; i++)
		{
			j = i - h;
			key = arr[i];

			while ((j >= 0) && (arr[j] > key))
			{
				arr[j + h] = arr[j];
				j -= h;
			}
			arr[j + h] = key;
		}
	}
}

void heap_sort(int data[], int heap_size)
{
	int k, i;

	/*Heap을 만든다*/
	for (i = (heap_size - 1) / 2; i >= 0; i--)
		downheap(data, i, heap_size);

	/*반복문 첨자 k를 통해 heap의 크기를 1 감소시킨다.*/
	for (k = heap_size - 1; k > 0; k--)
	{
		/*루트와 힙의 마지막 노드를 교환한다.*/
		SWAP(data[0], data[k]);

		//위배된 힙조건을 만족시킨다.
		downheap(data, 0, k);
	}
}

void quick_sort(int arr[], int left, int right)
{
	int piv;

	if (right - left > 1)
	{
		piv = partition(arr, left, right);

		quick_sort(arr, left, piv);
		quick_sort(arr, piv + 1, right);
	}
}

int partition(int arr[], int left, int right)
{
	int pivot, i , j;
	int p;
	
	p = (left + right) / 2;
	i = left;
	j = right;
	
	SWAP(arr[p], arr[left]);

	pivot = arr[left];

	while (1)
	{
		while (arr[++i] < pivot);
		while (arr[--j] > pivot);

		if (i >= j)
			break;

		SWAP(arr[i], arr[j])
	}
	SWAP(arr[left], arr[j]);
	return j;
}

void downheap(int data[], int cur, int end)
{
	int left, right, p;
	
	left = cur * 2 + 1;
	right = cur * 2 + 2;
	
	if (left >= end)
		return;

	p = left;

	if (right < end)
	{
		if (data[p] < data[right]) 
			p = right;
	}
	if (data[cur] < data[p])
	{
		SWAP(data[cur], data[p]);
		downheap(data, p, end);
	}
	else
		return;
}


int find_min(int arr[], int current, int N)
{
	int min, j;

	for (j = current + 1, min = current; j < N; j++)
	{
		if (arr[j] < arr[min])
		{
			min = j;
		}
	}
	return min;
}

void Sort(int sort_num)
{
	int arr[ARR_RANGE];
	int i;

	MKDAT();
	
	if (sort_num < 0 && sort_num > 10)
	{
		fprintf(stderr,"WRONG INPUT\n");
		exit(1);
	}


	printf("[BEFORE]\n");
	PRINT();

	switch (sort_num)
	{
	case 1:
		bubble_sort(arr, ARR_RANGE);
		break;
	case 2:
		selection_sort(arr, ARR_RANGE);
		break;
	case 3:
		insertion_sort(arr, ARR_RANGE);
		break;	
	case 5:
		quick_sort(arr, 0, ARR_RANGE);
		break;
	default:
		break;
	}

	printf("[AFTER]\n");
	PRINT();

	printf("\n[TIME: %.4lfs]\n", toc());
}