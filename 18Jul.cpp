// Question - Generate prime numbers upto 10^9 
// Solution - Can not use simple sieve of eratosthenes, because too much memoery needed. For larger ranges (upto 10^9), need to use SEGMENTED SIEVE.

#include <bits/stdc++.h>
#define MAX 1000000000
using namespace std;

vector<int> getPrimesInit(){
    vector<int> primes;
    int lim = sqrt(MAX);
    int* ar = new int [lim]{0};
    ar[0] = ar[1] = 1;
    for (int i=2; i<lim; i++){
        if (ar[i] == 0){
            for (int j=i*i; j<lim; j+=i){
                ar[j] = 1;
            }
            primes.push_back(i);
        }
    }
    return primes;
}

void getPrimesNext(vector<int>& primes, int checkTill, int start){
    int lim = sqrt(MAX);
    int *ar = new int [lim]{0};

    for (int i=0; i<checkTill; i++){
        int lowerLim = start/primes[i];
        while (primes[i]*lowerLim < start)
            lowerLim++;
        for (int j=primes[i]*lowerLim; j<start+lim; j+=primes[i]){
            ar[j-start] = 1;
        }
    }

    for (int i=0; i<lim; i++){
        if (ar[i] == 0)
            primes.push_back(i+start);
    }
}
