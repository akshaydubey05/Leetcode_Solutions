class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
          vector<int> c;
          sort(a.begin(),a.end());
          sort(b.begin(),b.end());
          auto ip=unique(a.begin(),a.end());
          a.resize(distance(a.begin(),ip));
          int i=0;
          int j=0;
          while(i<a.size()){
              if(j>=b.size()){
                  i++;
                  j=0;
                  continue;
              }
              if(a[i]==b[j]){
                  c.push_back(a[i]);
                  i++;
              }
              else{
                  j++;
              }
          }
          return c;
    }
};