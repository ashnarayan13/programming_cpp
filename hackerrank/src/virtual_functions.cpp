#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int p_id = 0;
int s_id = 0;
class Person{
    protected:
    int age, id, score;
    string name;
    public:
    virtual void putdata() = 0;
    virtual void getdata() = 0;
};
class Professor : public Person{
    private:
    void getdata(){
        cin>>name>>age>>score;
        id = ++p_id;
    }
    void putdata(){
        cout<<name<<" "<<age<<" "<<score<<" "<<id<<endl;
    }
};
class Student : public Person{
    private:
    void getdata(){
        cin>>name>>age;
        for(int i=0; i<6;i++){
            int temp;
            cin>>temp;
            score += temp;
        }
        id = ++s_id; 
    }
    void putdata(){
        cout<<name<<" "<<age<<" "<<score<<" "<<id<<endl;
    }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}