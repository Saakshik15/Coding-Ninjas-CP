void getZarr(int *z , string &test){

    int n=test.size();
    int left=0 , right=0;
    z[0]=0;

    for(int i=1;i<n;++i){
        if(i>right){
            left=right=i;

            while(right<n && test[right]==test[right-left])
                right++;
            z[i]=right-left;
            right--;
        }
        else{
            int k=i-left;
            if(z[k]<right-i+1)
                z[i]=z[k];
            else{
                left=i;
                while(right<n && test[right]==test[right-left])
                    right++;
                z[i]=right-left;
                right--;
            }
        }
    }
}
 

int zAlgorithm(string s, string p, int n, int m){
    string test=p+"$"+s;

    int len=test.size();
    int z[len];
	
    getZarr(z,test);
    int ans=0;

    for(int i=0;i<len;++i){
        if(z[i]==p.size())
            ans++;
    }

    return ans;
}
