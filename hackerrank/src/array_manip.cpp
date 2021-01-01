#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long arrayManFast(int n, vector<vector<int>> queries)
{
    vector<long> resVec(n+1, 0);
    long max = 0; 
    long count = 0;
    
    for (auto const& value:queries)
    {
        resVec[value[0]-1] += value[2];
        resVec[value[1]] -= value[2];
    }
    
    for(int i=0; i<n; ++i)
    {
        count += resVec[i];
        if(count>max)
        {
            max = count;
        }
    }
    return max;
}

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<int> right;
    for(auto const& value: queries) {
        right.push_back(value[1]);
    }
    vector<int>::iterator minRight = min_element(right.begin(), right.end());    
    vector<int>::iterator maxRight = max_element(right.begin(), right.end());
    //cout<<*minRight<<" "<<*maxRight;
    //long arr[n] = {0};
    vector<long> resVec(n+1, 0);
    for(auto const& value: queries)
    {
        if(value[0] >= *minRight && value[1] <= *maxRight)
        {
            //cout<< value[0]<<" "<<value[1]<<endl;
            for(int i=value[0]; i<=value[1]; ++i)
            {
                resVec[i-*minRight] += value[2];
            }
        }
    }
    
    vector<long>::iterator best = std::max_element( resVec.begin(), resVec.end() );
    //cout<<"result: "<<*highest;
    return *best;

}

int main()
{
    std::ifstream infile("/home/nomad/projects/programming_cpp/hackerrank/src/array_manipulation.txt");

    std::string line;
    int n, m;
    while (std::getline(infile, line))
    {
        vector<string> op = split_string(line);

        n = stoi(op[0]);
        m = stoi(op[1]);
        break;
    }

    vector<vector<int>> queries(m);

    int i = 0;
    while (std::getline(infile, line))
    {
        queries[i].resize(3);
        vector<string> op = split_string(line);

        for (int j = 0; j < 3; j++) {
            queries[i][j] = stoi(op[j]);
        }
        i++;
    }

    //long result = arrayManipulation(n, queries);

    long result = arrayManFast(n, queries);

    cout << result << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
