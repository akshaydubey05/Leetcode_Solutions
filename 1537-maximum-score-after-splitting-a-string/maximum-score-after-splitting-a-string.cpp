class Solution {
public:
    int maxScore(string s) {
        int max=INT_MIN;
        for(int i=0;i<s.length()-1;i++){
            string ch1=s.substr(0,i+1);
            string ch2=s.substr(i+1,s.length()-i);
            cout<<ch1<<" "<<ch2<<endl;
            int a=count(ch1.begin(),ch1.end(),'0');
            int b=count(ch2.begin(),ch2.end(),'1');
            int c=a+b;
            if(max<c){
                max=c;
            }
        }
        return max;
    }
};