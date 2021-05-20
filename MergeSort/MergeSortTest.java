public class MergeSortTest {

	public static void main(String[] args) {
		MergeSort mst = new MergeSort();
		
		int n = (int)(Math.random()*10)+11;
		int[] arr = new int[n];
		System.out.println("n:"+n);
		System.out.println("================before================");
		for(int i=0;i<n;i++) {
			arr[i] = (int)(Math.random()*1000)+1;
			System.out.print(arr[i] + " ");
		}
		
		System.out.println("\n");
		System.out.println("================after=================");
		mst.sort(arr,0,n);
		
		for(int i=0;i<n;i++) {
			System.out.print(arr[i] + " ");
		}
	}

}
