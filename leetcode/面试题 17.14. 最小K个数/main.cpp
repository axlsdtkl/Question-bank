class Solution {
    public int[] smallestK(int[] arr, int k) {
        Arrays.sort(arr);
        int[] a=new int[k];
        for(int i=0;i<k;i++)a[i]=arr[i];
        return a;
    }
}