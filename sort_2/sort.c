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

	/*N-1���� �н� ����*/
	for (i = 1; i < N; i++)
	{
		/*�迭 ������ ��ȯ �۾��� ����*/
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

	//i: �迭�� ���ĵ� �κ��� ���� �ٱ��� ���� ��ġ
	//j: �迭�� ���ĵ��� ���� �κ��� ���� ���� �κ��� ��ġ
	//key: ���ĵ� �迭�� ���� ���Ե� ��(�̹� ���ĵ� �迭 ������ ���ĵ� ������ ���� �ش� ��ġ�� ã�ư�)

	/*�ٱ��� for�� :: �̹� ���ĵ� �迭�� �κ�*/
	//for���� �ѹ� ������ ÷�ڰ� �ϳ� �������� �� �̹� �� ������ �ش��ϴ� �κ��� ������
	//�Ǿ� �ִ� �����̿��� ��.
	for (i = 1; i < N; i++)
	{
		j = i - 1;
		key = arr[i];

		//key���� ��ġ�� ã�ư��� ����
		//�Ʒ��� ���ǵ��� 1��°, �ش� �迭 ���� �� �κб��� �ٴٶ�������
		//2��°, ������ �ְ��� �ϴ� ���� ������ ���ĵ� �κ��� �� ���ڶ�, �� ���ĵ� �κп��� ���� ū ������ 
		//�� ū���� ����̴�.
		while (j >= 0 && arr[j] > key)
		{
			//�̺κ��� key�� ��ġ�� ã�ư��� ���� �����ʿ��� �������� key���� �̵���Ű�� �κ��̴�.
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
//	//hk:: �迭�� ������ ����
//	int hk[] = { 2047, 701, 31, 15, 4, 1, 0};
//
//	for (k = 0; hk[k] != 0; k++)
//	{
//		h = hk[k];
//
//		for (i = h; i < N; i++)
//		{
//			j = i - h; //���ĵ� �κ��� ���� ������ ���� ��ġ
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

	/*Heap�� �����*/
	for (i = (heap_size - 1) / 2; i >= 0; i--)
		downheap(data, i, heap_size);

	/*�ݺ��� ÷�� k�� ���� heap�� ũ�⸦ 1 ���ҽ�Ų��.*/
	for (k = heap_size - 1; k > 0; k--)
	{
		/*��Ʈ�� ���� ������ ��带 ��ȯ�Ѵ�.*/
		SWAP(data[0], data[k]);

		//����� �������� ������Ų��.
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