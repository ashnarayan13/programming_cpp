#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n) {
    /*
     * Write your code here.
     */
    return (n+2)/2;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int total = pageCount(n);
    int front = pageCount(p)-1;
    int back = total - front -1;

    fout << min(front, back) << "\n";

    fout.close();

    return 0;
}