/*
You have a car with a gas tank of infinite capacity.  There are ‘N’ gas stations along a circular route. 
Gas stations are numbered from 0 to N - 1. You begin the journey with an empty tank at one of the gas stations. 
You want to travel around the circular route once in the clockwise direction. I.e if you start to travel from station ‘i’, 
then you will go to i + 1, i + 2, …, n - 1, 0, 1, 2, i - 1  and then return back to ‘i’.

You are given two integer arrays ‘gas’ and ‘cost’. ‘gas[i]’ gives the amount of gas available at station ‘i’ and 
cost[i] gives the amount of gas required to travel from station ‘i’ to next station i.e station ‘i’+1 (or 0 if the station is N - 1).

Return the starting gas station's index if it is possible to complete cycle of given circular route once in the clockwise direction. 
If there are multiple possible starting gas station’s indexes, then return the minimum of those gas station indexes. 
If there is no such gas station then return -1.
*/

//code:

int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) 
{
    int deficit=0, rem=0, j=0;

    for(int i=0; i<n; i++){
        rem += gas[i]-cost[i];

        if(rem<0){
            deficit+= rem;
            j= i+1;
            rem=0;
        }
    } 
    return deficit+rem >=0? j:-1;
}
