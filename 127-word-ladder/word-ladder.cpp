class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            if(word==endWord){
                return steps;
            }
            q.pop();
            for(int i=0;i<word.size();i++){
                char ori=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=ori;
            }
        }
        return 0;
    }
};