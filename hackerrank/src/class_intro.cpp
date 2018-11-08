#include <iostream>
#include <sstream>
#include <string>
/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
    private:
    int age;
    std::string first_name;
    std::string last_name;
    int standard;
    public:
    Student(){}
    void set_age(int n){
        age = n;
    }
    void set_first_name(std::string f_name){
        first_name = f_name;
    }
    void set_last_name(std::string l_name){
        last_name = l_name;
    }
    void set_standard(int stdl){
        standard = stdl;
    }
    int get_age(){
        return age;
    }
    std::string get_first_name(){
        return first_name;
    }
    std::string get_last_name(){
        return last_name;
    }
    int get_standard(){
        return standard;
    }
    std::string to_string(){
        return std::to_string(age)+","+first_name+","+last_name+","+std::to_string(standard);
    }
};

int main() {
    int age, standard;
    std::string first_name, last_name;
    
    std::cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    std::cout << st.get_age() << "\n";
    std::cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    std::cout << st.get_standard() << "\n";
    std::cout << "\n";
    std::cout << st.to_string();
    
    return 0;
}