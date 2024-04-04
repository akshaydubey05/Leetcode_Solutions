class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int max=INT_MIN;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count++;
            }
            if(max<count){
                max=count;
                cout<<max<<" ";
            }
            if(s[i]==')'){
                count--;
            }
            
        }
        return max;
    }
};