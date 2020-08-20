#include <vector>
#include <cstdio>

using namespace std;

template <typename baseT>
class MergeSort{

private:
	vector<baseT> tmpv;

public:
	MergeSort(){

	}

	void sizing(vector<baseT> &arr){
		tmpv.resize(arr.size());
	}

	template <typename T1,typename T2>
	void merge(T1 l, T2 r, vector<baseT> &arr){
		if(l >= r) return;
		T1 mid = (l+r)/2;
		merge(l,mid,arr);
		merge(mid+1,r,arr);
		mergesort(l,r,arr);
	}

	template <typename T1, typename T2>
	void mergesort(T1 L, T2 R, vector<baseT> &arr){
		T1 l,r,idx,mid;
		l = idx = L;
		mid = (L+R)/2;
		r = mid+1;

		while(l <= mid && r <= R){
			if(arr[l] < arr[r]) tmpv[idx++] = arr[l++];
			else tmpv[idx++] = arr[r++];
		}

		while(l <= mid) tmpv[idx++] = arr[l++];
		while(r <= R) tmpv[idx++] = arr[r++];

		for(T1 i=L;i<=R;i++) arr[i] = tmpv[i];
	}

	void tmpToArrCopy(vector<baseT> &arr){
		for(int i=0;i<arr.size();i++) arr[i] = tmpv[i];
	}
};
