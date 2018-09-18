#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int cumulative = 0;
    int current = 0;
    int shared = 0;
    int i = 1;
    while(i<=n){
        if(i==1){
            shared = 5;
            current = shared/2;
            cumulative = current;
        }
        else{
            shared = current * 3;
            current = shared / 2;
            cumulative += current;
        }
        i++;
        //cout<<shared<<" "<<current<<" "<<cumulative<<endl;
    }
    return cumulative;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}