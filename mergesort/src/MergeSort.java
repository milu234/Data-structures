public class MergeSort{
    int[] array;
    int[] tempArray;
    int length;
    public static void main(String[] args) {
        int[] arrayToSort = {43,98,56,42,71,23,120,-6};
        MergeSort arr = new MergeSort();
        arr.Sort(arrayToSort);
        for(int i:arrayToSort){
            System.out.print(i);
            System.out.print(" ");
            
        }
   
}
    public void Sort(int[] arrayToSort){
        this.array = arrayToSort;
        this.length = arrayToSort.length;
        this.tempArray = new int[length];
        Merge_Sort(0, length-1);
}
    
    
    public void Merge_Sort(int low, int high){
        if(low<high){
            int mid= low + (high-low)/2;
            Merge_Sort(low,mid);
            Merge_Sort(mid+1,high);
            Merge(low,mid,high);
        }
        
    }
    
    public void Merge(int low, int mid, int high){
        for(int i  = low;i<=high;i++){
            tempArray[i] = array[i];
        }
        int i = low;
        int j = mid+1;
        int k = low;
        while(i<=mid && j <= high){
            if(tempArray[i] <= tempArray[j])
            {
                array[k] = tempArray[i];
                i++;
            }
            else{
                array[k]  = tempArray[j];
                j++;
            }
            k++;
        }
        while(i <=mid){
            array[k] = tempArray[i];
            i++;
            k++;
        }
        
    }
    
}