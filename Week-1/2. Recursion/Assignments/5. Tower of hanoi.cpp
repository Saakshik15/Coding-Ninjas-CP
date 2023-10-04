/* Problem: You are given three rods (numbered 1 to 3), and ‘N’ disks initially placed on the first rod, one on top of 
each other in increasing order of size ( the largest disk is at the bottom). You are supposed to move the ‘N’ disks to another 
rod(either rod 2 or rod 3) using the following rules and in less than 2 ^ (N) moves.
1. You can only move one disk in one move. 
2. You can not place a larger disk on top of a smaller disk.
3. You can only move the disk at the top of any rod. 
*/

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

//recursive function

void helper(int n,int s,int a,int d,vector<vector<int>>&ans){
    if(n==0) return;
    helper(n-1,s,d,a,ans);
    ans.push_back({s,d});
    helper(n-1,a,s,d,ans);
 }

 vector<vector<int>> towerOfHanoi(int n){
    vector<vector<int>>ans;
     helper(n,1,2,3,ans);
     return ans;
}



//main code

bool checker(vector<vector<int>> &v, int n)
{
    vector<int> a[3];
    //  push all the disks to the first rod.
    for (int i = n; i >= 1; i--)
    {
        a[0].push_back(i);
    }

    int sz = n;
    //    If there are more than 2^n -1 moves return false.
    if (v.size() >= (1 << n))
    {
        cout<<"No of moves exceeded"<<endl;
        return false;
    }

    for (int i = 0; i < v.size(); i++)
    {
        
        
        //    if one move has more than 3 integers return false
        if (v[i].size() != 2)
        {
            cout<<"Using more than 2 disks in one move"<<endl;
            return false;
        }

        int to = v[i][1];
        int from = v[i][0];

        //  If Rod number lies out of range return false.
        if (to <= 0 or from <= 0)
        {
            cout<<"Invalid rod number "<<endl;

            return false;
        }

        //  If Rod number lies out of range return false.
        if (to > 3 or from > 3)
        {
            cout<<"Invalid rod number "<<endl;

            return false;
        }

        //  0 based indexing
        to--;
        from--;

        //    If there is no disk on the rod return false.
        if (a[from].empty())
        {
            cout<<"Removing disk from empty rod"<<endl;
            return false;
        }

        int last = a[from].back();
        a[from].pop_back();

        //    If the disk can be placed on the required rod.
        if (a[to].empty() or a[to].back() > last)
        {
            a[to].push_back(last);
        }
        //    Return false if the disk is placed on a smaller disk
        else
        {
            cout<<"Placing a larger disk on a smaller disk"<<endl;
            return false;
        }
    }

    //    Return true if rod 2 or rod 3 has N disks.
    return (a[1].size() == n or a[2].size() == n);
}

class Runner
{
    int t;
    vector<int> arr;

public:
    void takeInput()
    {

        cin >> t;
        arr.resize(t);
        for (int tc = 0; tc < t; tc++)
        {
            
            cin >> arr[tc];
            
        }
    }

    vector<int> getCopy()
    {
        vector<int> arrCopy = arr;

        return arrCopy;
    }

    void execute()
    {
        vector<int> arrCopy = arr;
        for (int i = 0; i < t; i++)
        {
            vector<vector<int>> ans = towerOfHanoi(arrCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int temp=arr[i];
            vector<vector<int>> ans = towerOfHanoi(arr[i]);

            if (checker(ans, temp))
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
