#define MOD 1000000009;

int countSetBits(int x)
{
    unsigned int count = 0;
    while (x)
    {
      x &= (x-1) ;
      count = (count + 1) % MOD;
    }
    return count;
}

int saf(int i, int j){
    
    int z = i^j;
    //cout << "Z i j " << z << " "<< i << " " << j << " |";
    int el = countSetBits(z);
    return el;
}




int Solution::cntBits(vector<int> &A) {
    
    int coun = 0;
    for(int i = 0; i<A.size(); i++){
        for(int j = 0; j < A.size(); j++){
            coun += saf(A[i],A[j]);
        }
    }
    return coun;
}


// BETTER

typedef long long LL;
#define MOD 1000000007ll
int Solution::cntBits(vector<int> &A) {
    int ans=0,n=A.size();

    //traverse over all bits
    for(int i=0; i<31; i++){

        //count number of elements with ith bit = 0
        LL cnt=0;
        for(int j=0; j<n; j++)
            if((A[j]&(1<<i)))cnt++;

        //add to answer cnt*(n-cnt)*2
        ans += (cnt*((LL)n-cnt)*2)%MOD;
        if(ans>=MOD)ans-=MOD;

    }

    return ans;
}