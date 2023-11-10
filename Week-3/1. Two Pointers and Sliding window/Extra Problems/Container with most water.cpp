/*


*/

/*
Solution:

Approach 1: Brute force

1. Use two loops, fix the the outer loop and move the inner loop to check every possible combination of two heights in the given array.
2. Outer loop runs from 0 to n-1 and inner loop runs from outerLoopIndex + 1 to n.
3. For each iteration of the inner loop you will get a pair of heights. 
Check if the area formed using this pair of heights is greater than the max area so far.
4. If yes update the result, else continue to check the next pair.
5. Repeat step 1-4 for all possible pair of heights.
6. Finally return the maximum area obtained as the result.

Time complexity: O(N^2)
Space complexity: O(1)

*/


/*
Solution 2: 

Appraoch: Two pointer

Observation: 

if [1,8,6,2,5,4,8,3,7] is the given array, if you start with the combination of first and last heights and move inwards 
i.e. (1,7), (1,3), (1,8), (1,4) and so on, you can see that you get no benefit by using combinations (1,3), (1,8), (1,4) 
so on after (1,7) to calculate area, as the minimum height obtained by using any of these combinations remains same. 
This is so because in all cases 2nd height is greater than the 1st height (height1= 1, which is same for all the pairs), 
and since we take the minimum of 1st and 2nd heights while calculating the area, we always end up with 1 as the 
result(for minimum height) for all the above combinations. This is true for all such cases where for a set of combinations 
one of the heights is same and it is smaller than the other height in all pairs. Also the width keeps decreasing as we move inwards, 
for (1,7) width is 8, for (1,3) width is 7, for (1,8) width is 6 and so on. Therefore the area also will decrease.


We can use this to our advantage to solve this problem in linear time. 
This approach involves the following steps:

1. We need to start our algorithm with left pointer pointing to the 0th index and right pointer 
pointing to the last index of the heights array.

2. We calculate the area using the left and right heights using the previous formula.

3. After this we need to retain maximum of left and right pointers (heights) and move the other pointer. 
For example if our (left, right) = (1,7), after calculating the area, we check which of (left height, right height) is larger. 
In this case, right height i.e. 7 is the larger of the two. So, we keep the right pointer at the same position and increment 
the left pointer by 1.

4. Similarly if the left element was larger as in (8,3) then we keep the left pointer at the same index and decrement the 
right pointer after calculating the area for (8, 3). We can do this because we know, we do not get any benefit 
(in terms of area obtained) by retaining the smaller height, and thus this would have no impact on the output.

5. We have to repeat the above steps as long as our left pointer is less than right pointer, after which we return 
the maximum area obtained thus far as the result. 
*/

//code:

class Solution {
public:
    int maxArea(vector<int>& height) {

        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        int n= height.size();
        int l=0, r= n-1;
        int res=0;

        while(l<r){
            int currArea = min(height[l], height[r])*(r-l);
            res= max(res, currArea);

            height[l]<height[r] ? l++ : r--;
        }
        return res;
    }
};
