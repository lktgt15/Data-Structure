#include <vector>

using namespace std;

template <typename T>
void myQuickSort(int l,int r,vector<T> &arr){
	if(l>=r) return;
	T pivot = arr[r];
	int lidx = l, ridx = r-1;
	while(lidx<ridx){
		while(arr[lidx] < pivot && lidx<ridx) lidx++;
		while(arr[ridx] > pivot && lidx<ridx) ridx--;
		if(lidx<ridx){
			T tmp = arr[lidx];
			arr[lidx] = arr[ridx];
			arr[ridx] = tmp;
		}
	}
	if(arr[lidx] > pivot){
		T tmp = arr[lidx];
		arr[lidx] = pivot;
		arr[r] = tmp;
	}
	myQuickSort(l,lidx,arr);
	myQuickSort(ridx+1,r,arr);
}
