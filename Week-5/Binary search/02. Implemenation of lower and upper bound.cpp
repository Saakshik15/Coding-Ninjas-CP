// pseudo-code for lower_bound()

lower_bound(nums, target){
  left= 0, right= nums.length-1;

  while(left<=right){
    mid= left+(right-left)/2;

    if(arr[mid]>=n) {
      ans=mid;
      high=mid-1;
    }
    else
      low=mid+1;
  }
}

