#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int** a = new int*[n]; //pointer to a pointer
    
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        a[i] = new int[m]; //create a new array
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            a[i][j] = x; //fill array
        }
    }
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        cout << a[x][y] << endl;
    }
    return 0;
}