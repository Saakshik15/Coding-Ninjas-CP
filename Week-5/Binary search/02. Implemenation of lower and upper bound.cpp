// pseudo-code for lower_bound()

lower_bound(nums, target){
  left= 0, right= nums.length;

  while(left<right){
    mid= left+(right-left)/2;

    if(target<= arr[mid]) {
      ans=mid;
      right=mid-1;
    }
    else
      left=mid+1;
  }
  if (left<nums.length && nums[left]<target) left++;
  return left;
}


// pseudo-code for upper_bound()

upper_bound(nums, target){
  left=0, right= nums.length;

  while(left<right){
    mid= left+(right-left)/2;

    if(target >= nums[mid]) left= mid+1;
    else right= mid;
  }
  if( left < nums.length && nums[left]<=target) left++;
  return left;
}


