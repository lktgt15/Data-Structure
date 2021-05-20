package QuickSort;

public class QuickSort {
    public void sort(int[] arr,int l,int r){
        if(l+1 >= r) return;
        int pivot = arr[r-1];
        int idx = l-1;
        for(int i=l;i<r-1;i++){
            if(arr[i] < pivot){
                swap(arr,++idx,i);
            }
        }
        swap(arr,++idx,r-1);
        sort(arr,l,idx);
        sort(arr,idx+1,r);
    }

    private void swap(int[] arr,int a,int b){
        int tmp = arr[b];
        arr[b] = arr[a];
        arr[a] = tmp;
    }
}
