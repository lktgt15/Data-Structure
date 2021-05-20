public class MergeSort {
	private int[] tmparr;
	
	public void init(int length) {
		if(tmparr == null || tmparr.length < length) tmparr = new int[length];
	}

	public void sort(int[] arr,int l,int r){
		init(arr.length);
		split(arr,l,r);
	}

	private void split(int[] arr,int l,int r){
		if(l+1 >= r) return;

		int mid = (l+r)/2;
		split(arr,l,mid);
		split(arr,mid,r);
		mergeSort(arr,l,r);
	}

	private void mergeSort(int[] arr,int l,int r){
		int tmpl = l;
		int mid = (l+r)/2;
		int tmpr = mid;
		int idx = l;
		while(tmpl<mid && tmpr<r){
			if(arr[tmpl] < arr[tmpr]) tmparr[idx++] = arr[tmpl++];
			else tmparr[idx++] = arr[tmpr++];
		}

		while(tmpl<mid) tmparr[idx++] = arr[tmpl++];
		while(tmpr<r) tmparr[idx++] = arr[tmpr++];

		for(int i=l;i<r;i++){
			arr[i] = tmparr[i];
		}
	}
}
