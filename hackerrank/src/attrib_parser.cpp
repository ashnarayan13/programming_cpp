#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stack>
using namespace std;

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

vector<string> removeChars(string input)
{
    char chars[] = {'<','>','/','\"'};

    for (unsigned int i = 0; i < 4; ++i)
    {
        // you need include <algorithm> to use general algorithms like std::remove()
        input.erase(std::remove(input.begin(), input.end(), chars[i]), input.end());
    }
    vector<string> res = split_string(input);
    return res;
}

vector<pair<string, string>> keyVal(vector<string> inputs)
{
    vector<pair<string, string>> res;
    for(int i=1; i<inputs.size(); ++i)
    {
        if(inputs[i] == "=")
        {
            // We need to create a pair
            pair<string,string> newPair;
            // No need to handle exception since query is expected to be well formed
            newPair.first = inputs[i-1];
            newPair.second = inputs[i+1];
            res.push_back(newPair);
        }
    }
    return res;
}

string getQueryString(stack<string> input)
{
    stack<string> res;
    string output = "";

    while (input.empty() == false)
    {
        string tempTop = input.top();
        input.pop();
        res.push(tempTop);
    }
    while(res.empty() == false)
    {
        if(!output.empty())
        {
            output += ".";
        }
        output += res.top();
        res.pop();
    }
    return output;
}

vector<pair<string, string>> getValues(string query, vector<pair<string, string>> keyValPairs)
{
    // For each key val pair. Create a query and push
    vector<pair<string, string>> mapItems;
    for(auto const& value:keyValPairs)
    {
        pair<string, string> newPair;
        string temp = query;
        temp += "~";
        temp += static_cast<string>(value.first);
        newPair.first = temp;
        newPair.second = value.second;
        mapItems.push_back(newPair);
    }
    return mapItems;
}

vector<string> solve(vector<string> inputs, vector<string> queries)
{
    vector<string> results;
    
    map<string, string> terms;
    stack<string> currentStack;
    
    for(string data:inputs)
    {
        if(data[1] == '/')
        {
            // We only need to pop from the queue
            currentStack.pop();
        }
        else
        {
            // Begin tag
            // Push to queue and create a valid term
            vector<string> res = removeChars(data);
            
            // First value of res should be the tag!
            currentStack.push(res[0]);

            // Now process from 1 to n
            vector<pair<string, string>> keyValPairs = keyVal(res);

            // Convert the stack into text
            string queryString = getQueryString(currentStack);
            
            // Create multiple pairs
            vector<pair<string, string>> values = getValues(queryString, keyValPairs);
            for(auto const& val:values)
            {
                terms.insert(val);
            }
        }
    }
    
    for(string data:queries)
    {
        if(terms.find(data) != terms.end())
        {
            // We have a hit
            cout<<terms.find(data)->second<<endl;
        }
        else
        {
            cout<<"Not Found!\n";
        }
        
    }
    
    return results;
}

int main() {

    std::ifstream infile("/home/nomad/projects/programming_cpp/hackerrank/src/attrib_parse.txt");

    std::string line;
    int n, m;
    while (std::getline(infile, line))
    {
        vector<string> op = split_string(line);

        n = stoi(op[0]); // Inputs
        m = stoi(op[1]); // Queries
        break;
    }

    int count = 0;
    vector<string> inputs;
    vector<string> queries;
    while(std::getline(infile, line))
    {
        if(count<n)
        {
            inputs.push_back(line);
            count++;
        }
        else
        {
            queries.push_back(line);
            count++;
        }
    }
    
    solve(inputs, queries);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

