/*
Problem: 

Given two arrays at and dt, arrival and departure time of all trains that reach a railway station.
Find the min number of platforms required for that railway station so that no train needs to wait.

*/

//code:

int calculateMinPatforms(int at[], int dt[], int n) {
    
    sort(at, at+n);
    sort(dt, dt+n);

    int i=0, j=1;
    int reserved=1, platform=1;

    while(i<n && j<n){
        if(dt[i]>=at[j]){
            platform++;
            j++;
        }else{
            platform--;
            i++;
        }
        reserved= max(reserved,platform);
    }
    return reserved;
}
