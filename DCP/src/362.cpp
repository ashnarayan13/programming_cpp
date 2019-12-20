#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> processString(const vector<string>& vec, int n, int total) {
    vector<string> ret;
    for (string s : vec) {
        if (n != total) {
            ret.push_back("0" + s + "0");
        }
        ret.push_back("1" + s + "1");
        ret.push_back("8" + s + "8");
        ret.push_back("6" + s + "9");
        ret.push_back("9" + s + "6");
    }
    return ret;
}

vector<string> findImp(int n, int total) {
    if (n == 0) { return vector<string> { "" }; }
    if (n == 1) { return vector<string> { "1", "8", "0" }; }
    return processString(findImp(n - 2, total), n, total);
}

vector<string> findStrobogrammatic(int n) {
    return findImp(n, n);
}

int main(){
    vector<string> output = findStrobogrammatic(3);
    for(int i=0; i<output.size(); ++i){
        std::cout<<output[i]<<std::endl;
    }
}

