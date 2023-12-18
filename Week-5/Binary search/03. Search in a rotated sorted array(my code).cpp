int search(int* arr, int n, int key) {
    int low=0, high= n-1;

    while (low <= high) {

        int mid= low+(high-low)/2;
        if (arr[mid]==key) return mid;

        //check if left half is sorted
        if(arr[low]<=arr[mid]){
            //check if tgt lies between low and mid, if yes then eliminate high
            if(arr[low]<= key && key<=arr[mid]) high= mid-1;
            //if no, eliminate low and keep high
            else low= mid+1;
        }
        //check if right half is sorted
        else{
            //check if tgt lies between mid & high, if so, we dont need low
            if(arr[mid]<=key && key<= arr[high]) low= mid+1;
            //if tgt does not lie between mid & high, we will eliminate high
            else high=mid-1;
        }
    }
    return -1;
}
