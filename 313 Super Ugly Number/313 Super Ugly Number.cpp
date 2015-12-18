// Write a program to find the nth super ugly number.
// Super ugly numbers are positive numbers whose all prime factors 
// are in the given prime list primes of size k. For example,
// [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of 
// the first 12 super ugly numbers given primes = [2, 7, 13, 19] of 
// size 4.
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n,0);
        ugly[0]=1;
        int N=primes.size();
        // index of the each primes number in the ugly array, which is all possible factor from small to larger
        vector<int> index(N,0);
        // nextNum is the possible next number which always is multiplied with an super ugly number
        vector<int> nextNum(N,0);
        // initialize the nextNum 
        for(int i=0;i<N;i++){
            nextNum[i]=primes[i];
        }
        // using dynamic programming to get the first n super ugly number
        for(int i=1;i<n;i++){
            int minVal=getMin(nextNum);
            ugly[i]=minVal;
            for(int j=0;j<N;j++){
                if(minVal==nextNum[j]){
                    // index of nextNum, then generate next smallest number for this nextNum[index], not the globally smallest
                    nextNum[j]=ugly[++index[j]]*primes[j];
                }
            }
        }
        return ugly[n-1];
    }
    int getMin(vector<int> array){
        int min=array[0];
        for(int i=0;i<array.size();i++){
            if(min>array[i])min=array[i];
        }
        return min;
    }
};