class Solution {
public:
    int xc(int maxSum,vector<int> &a ) {
    int n = a.size();
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + a[i] <= maxSum) {
            subarraySum += a[i];
        }
        else {
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}
    int splitArray(vector<int>& n, int k) {
        int a = *max_element(n.begin(), n.end());
        int b = accumulate(n.begin(), n.end(),0);
        while(a<=b){
            int mid = a+(b-a)/2;
            int as=xc(mid, n);
            if(as> k){
                a=mid+1;
            }
            else{
                b=mid-1;
            }
        }
        return a;
    }
};