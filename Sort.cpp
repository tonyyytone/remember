#include <iostream>
#include "sortHelper.h"
using namespace std;

template<typename T>
void insertSort(T arr[], int n) {
	for (int i = 1; i < n; i++)
	{
		T temp = arr[i];
		int j;
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

template<typename T>
void shellsort(T arr[], int n) {
	int k = 1;
	while (k < n / 3) {
		k = k * 3 + 1;
	}
	while (k >= 1) {
		for (int i = k; i < n; i++)
		{
			T temp = arr[i];
			int j;
			for (j = i; j >= k&&arr[j - k] > temp; j -= k) {
				arr[j] = arr[j - k];
			}
			arr[j] = temp;
		}
		k /= 3;
	}
}

template<typename T>
void bubblesort(T arr[], int n) {
	bool swapped = true;
	do {
		swapped = false;
		for (int i = 1; i < n; i++)
		{
			
			if (arr[i - 1] > arr[i]) {
				swap(arr[i - 1], arr[i]);
				swapped = true;
			}
		}
		n--;
	} while (swapped);
}

template<typename T>
void selectionsort(T arr[], int n)
{
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = i; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}
template<typename T>
//归并排序Merge
void __merge(T arr[], int l, int mid,int r) {
	T *aux = new T[r - l + 1];
	for (int i = l; i <= r; i++) {
		aux[i-l] = arr[i];
	}
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {
			arr[k] = aux[j - l];
			j++;
		}
		else if(j>r){
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] < aux[j - l]) {
			arr[k] = aux[i - l];
			i++;
		}
		else {
			arr[k] = aux[j - l];
			j++;
		}
	}
}
//归并排序里函数
template<typename T>
void __mergeSort(T arr[], int l, int r) {
	if (l >= r)
		return;
	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	__merge(arr, l, mid, r);
}

//归并排序函数
template<typename T>
void mergeSort(T arr[], int n) {
	__mergeSort(arr, 0, n - 1);
}
int __partition(int arr[], int l, int r) {
	int v = arr[l];
	int j = l;
	for (int i = l + 1; i < r; i++) {
		if (arr[i] < v) {
			swap(arr[j+1], arr[i]);
			j++;
		}
	}
	swap(arr[l], arr[j]);
	return j;
}
void __quickSort(int arr[],int l, int r) {
	if (l >= r) {
		return;
	}
	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}
void quickSort(int arr[], int n) {
	__quickSort(arr, 0, n - 1);
}
int main() {
	int *arr=SortHelper::generateRandom(50000, 1, 50000);
	int *arr2 = SortHelper::copyArray(arr, 50000);
	SortHelper::testsort("mergeSort",mergeSort, arr, 50000);
	SortHelper::testsort("insertionSort", insertSort, arr2, 50000);
	delete[]arr;
	arr = NULL;
	system("pause");
	return 0;
}