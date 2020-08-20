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

	void merge(int l, int r, vector<T> &arr){
		if(l >= r) return;
		int mid = (l+r)/2;
		merge(l,mid,arr);
		merge(mid+1,r,arr);
		mergesort(l,r,arr);
	}

	void mergesort(int L, int R, vector<T> &arr){
		int l,r,idx,mid;
		l = idx = L;
		mid = (L+R)/2;
		r = mid+1;

		while(l <= mid && r <= R){
			if(arr[l] < arr[r]) tmpv[idx++] = arr[l++];
			else tmpv[idx++] = arr[r++];
		}

		while(l <= mid) tmpv[idx++] = arr[l++];
		while(r <= R) tmpv[idx++] = arr[r++];

		for(int i=L;i<=R;i++) arr[i] = tmpv[i];
	}

	void tmpToArrCopy(vector<T> &arr){
		for(int i=0;i<arr.size();i++) arr[i] = tmpv[i];
	}
};

int main(){
	vector<int> arr = {9,6,7,5,3,2,8,4,1,0};
	MergeSort<int> mst;
	mst.sizing(arr);
	mst.merge(0,arr.size()-1,arr);
	for(int &n : arr) printf("%d ",n);
}
