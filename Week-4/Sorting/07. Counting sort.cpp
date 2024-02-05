/*
Suppose, we are given an array to sort which contains elements:

arr= [2,3,1,1,5,4,2,2,1]

Now, for sorting this array, we will find out the min and max element prsent in the array and make a new array 
of size max for counting the number of elements.
Finding the min and max element from the array will take up O(n) + O(n) time in total, traversing the array.

In the new array, we will initialize each element by 0, which is the initial count of the elements.
Now, we will traverse the given array and for each element encountered, we will increase its count at hte index no.
in the array we have created.

for eg, here the new array becomes= [0, 3, 3, 1, 1, 1]
indexnimbers are:                    0  1  2  3  4  5

and at the end, we will traverse the new array and add the elements to the array according to the count.

This sorting method thus ends up taking :
O(n)+ O(n)+ O(n)+ O(n) = O(4n) time which is ~= o(n) time.

This also uses space of O(n).
*/

/*
However, counting sort has some limitations, which can be given as:

1. Not helpful for large numbers as there is a limitation on the size of array we can create.
2. As we are using indexes to retrive the values, this method might not be that useful for fractional values.
3. It is not useful for negative values, as indexes cannot be negative, however, we can still use it for 
    negative values using some calculations.
4. Counting sort is not useful for custom sorting, eg sorting of pairs or customized ways of sorting.

*/
