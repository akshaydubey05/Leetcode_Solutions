class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int tot_sum = 0;
        for(int i = 0;i <code.size();i++){
            tot_sum += code[i];
        }
        vector<int> a(code.size(),0);
        if(k > 0){
            for(int i=0;i<code.size();i++){
                int sum = 0;
                int j=i+1;
                int s=k;
                while(s--){
                    if(j > code.size()-1){
                        j = 0;
                    }
                    cout<<sum<<"a"<<i<<" ";
                    sum+=code[j];
                    j++;
                }
                a[i] = sum;
            }
        }
        else if(k<0){
            for(int i = 0;i<code.size();i++){
                int sum = 0;
                int j=i-1;
                int x=-1*k;
                while(x--){
                    if(j < 0){
                        j = code.size()-1;
                    }
                    cout<<sum<<"a"<<i<<" ";
                    sum+=code[j];
                    j--;
                }
                a[i] = sum;
            }
        }
        return a;
    }
};