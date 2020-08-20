#include <vector>
#include <cstdio>

using namespace std;

template <typename T>
class MergeSort{

private:
	vector<T> tmpv;

public:
	MergeSort(){

	}

	void sizing(vector<T> &arr){
		tmpv.resize(arr.size());
	}

	void merge(T l, T r, vector<T> &arr){
		if(l >= r) return;
		T mid = (l+r)/2;
		merge(l,mid,arr);
		merge(mid+1,r,arr);
		mergesort(l,r,arr);
	}

	void mergesort(T L, T R, vector<T> &arr){
		T l,r,idx,mid;
		l = idx = L;
		mid = (L+R)/2;
		r = mid+1;

		while(l <= mid && r <= R){
			if(arr[l] < arr[r]) tmpv[idx++] = arr[l++];
			else tmpv[idx++] = arr[r++];
		}

		while(l <= mid) tmpv[idx++] = arr[l++];
		while(r <= R) tmpv[idx++] = arr[r++];

		for(T i=L;i<=R;i++) arr[i] = tmpv[i];
	}

	void tmpToArrCopy(vector<T> &arr){
		for(int i=0;i<arr.size();i++) arr[i] = tmpv[i];
	}
};
