#include <iostream>
#include <string>
#include <map>
#include <queue>

std::string frequencySort(std::string s) {
        std::map<char,int>m;
        for(int i=0;i<s.size();i++){
            ++m[s[i]];
        }
        
        std::priority_queue<std::pair<int,char>>pq;
        for(auto itr=m.begin();itr!=m.end();itr++){
            std::pair<char,int>p = *itr;
            pq.push({p.second,p.first});
        }
        
        std::string ans = "";
        while(!pq.empty()){
            int freq = pq.top().first;
            char x = pq.top().second;
            for(int i=0;i<freq;i++){
                ans += x;
            }
            pq.pop();
        }
        return ans;
    }

int main()
{
    std::string input = "tweet";

    std::cout<<frequencySort(input);
}