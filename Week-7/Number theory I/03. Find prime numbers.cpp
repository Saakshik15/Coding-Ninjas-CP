/*
Problem statement: 
given N find all the prime numbers from 1 to N
*/

//code:

vector<int> primeNumbersTillN(int n) {
	
	vector<int> prime(n+1);
	
    for (int i = 0; i <= n; i++)  prime[i] = true;
    prime[1] = false;
                                                       
    for (int i = 2; i * i <= n; i++) {
        if (prime[i] == true) {
    	    for (int j = i * i; j <= n; j += i) 
				prime[j] = false;
        }
    }

	vector<int> ans;

	for(int i=1; i<=n; i++) {
		if(prime[i]==true) ans.push_back(i);
	}
 	return ans;
}


.
