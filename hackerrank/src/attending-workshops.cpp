#include<bits/stdc++.h>

using namespace std;
//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
//can be solved with pairs
typedef vector<pair<int,int> > Available_Workshops;
Available_Workshops* initialize(int *start, int *dur, int size){
    Available_Workshops *temp = new Available_Workshops(size);
    for(int i=0; i<size; i++){
        temp->at(i).first=start[i],temp->at(i).second=start[i]+dur[i];
    }
    return temp;
}

int CalculateMaxWorkshops(Available_Workshops *ws){
    /*for(int i=0; i<ws->size(); i++){
        cout<<ws->at(i).first<<" "<<ws->at(i).second<<endl;
    }*/
    sort(ws->begin(), ws->end(), [](const pair<int,int> &a, const pair<int,int> &b){return a.second<b.second;});
    /*cout<<"after sort \n";
    for(int i=0; i<ws->size(); i++){
        cout<<ws->at(i).first<<" "<<ws->at(i).second<<endl;
    }*/
    int p=0,q=0;
    for(int i=0; i<ws->size();i++){
        if(ws->at(i).first>=q){
            p++;
            q = ws->at(i).second;
        }
    }
    return p;
}
int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
