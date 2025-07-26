#include<iostream>
#include "math.hpp"
#include<string>
// #include"array.hpp"
using namespace std;
// using namespace lib;
// 3-
// template<typename T>//template parameter

// T sum(const T a,const T b){
//     return a+b;
// }
class T{



};

int main(){


// 1-provide function that gives sum of two integers 
// cout<<sum(10,20);
// --------------------------------------------
// 2-provide function that gives sum of two doubles
// --------------------------------------------
// 3-
// cout<< sum<double>(200.5,500.5);//template instantiation
// cout<< sum<char>(200.5,500.5);


//we can use godbolt website for exploring the compiler view
// --------------------------------------------
// 4-
// cout<<sum<int>(100,200,300);
// --------------------------------------------
// template argument deduction:the compiler tries to guess the data types in case they are not mentioned
// but this is done successfully when the types of the aruments are the same  but if one of them is double for example and the others are int then this is the output error: no matching function for call to ‘sum(int, double, int)’ (compilation error)
// cout<<sum(100,200,300);
// ------------------------
// 6-
//  cout<<sum(100,200.5);//--> AS the function return datatype T which is the datatype of 100 ,but this is an issue as the return type should be the type of the greatest size for not losing data 
//  and if we made U as the return type we cant gurantee the order of user input the user can put the datatype of lower size in place of U
// so we need a way to tell the compiler to make the return type like the type of the input with higher size and this way is to use auto as a return type this helps the compiler to choose the data type of higher size from the types of the inputs
// }
// ----------------------
// 7-
// string a {"bassant"};
// string b {"ehab"};
// cout<<sum<string,string>(a,b);

// -------------------------
// 8-variadic  template
// T new_class{};
// cout<<sum(100,200,400,new_class,400.6,900);//makes the static assertion fails
cout<<lib::sum(100,200,400,400.6,900);//lib namespace scope
// cout<<sum(100,200);
//  cout<<sum(100);
// cout<<sum();
// -----------------------
// 9-array
// array<int,3>arr_{1,2,3};// the compiler will put the type -->int , size-->3 in array template you can find it in cpp reference
// ----------------------------
// array template in array.hpp file
// array<char[],4>arr_;
// arr_[0]='A';
// arr_[1]='B';
// arr_[2]='C';
// arr_[3]='\0';

// arr_.print_string();

// array<int,4>arr_;
// arr_[2];
// cout<<arr_[2];
}
