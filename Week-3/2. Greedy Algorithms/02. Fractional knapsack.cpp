/*
You are given weights and values of N items. You have to select and put these selected items in a knapsack of capacity W. 
Select the items in such a way that selected items give the maximum total value possible with given capacity of the knapsack.
*/

/*
    Time Complexity : O(N * log(N))
    Space Complexity : O(1)

    where N is the number of items.
*/


#include <bits/stdc++.h>

// Comparator to sort items.
bool compare(pair<int, int>& a, pair<int, int>& b)
{
    double r1 = (double) a.second / a.first;
    double r2 = (double) b.second / b.first;

    return r1 > r2;
}

double maximumValue(vector<pair<int,int>>& items, int n, int w)
{
    // Sort items according to value/weight.
    sort(items.begin(), items.end(), compare);

    double maxValue = 0;
    int currWeight = 0;

    for (int i = 0; i < n; i++){
        if (currWeight + items[i].first <= w){
            currWeight += items[i].first;
            maxValue += items[i].second;
        }
        else{
            int remainingWeight = w - currWeight;
            // Pick a fraction of current item.
            maxValue += items[i].second * ((double)remainingWeight / items[i].first);
            break;
        }
    }

    return maxValue;
}
