#include "math.hpp"
// 1-the library must provide function that gives sum of two numbers 
int sum(int a,int b){
    return a+b;
}
// --------------------------------
// 2-
// there is concept named "the only constant is change" --> this means that the requirement of the current app can be changed in the future 
// the second requirement is --> the library must provide a function that provides two doubles
// -->so simple way to cover all use cases is  overloading 
// but overloading violates important rule which is "dont repeat yourself"

double sum(double a,double b){
    return a+b;
}

unsigned int sum(unsigned int  a,unsigned int  b){
    return a+b;
}

double sum(double a,double b,double c){//this arguments can be endless with endless variable type
    return a+b;
}// so requirements is endless ,and by increasing the parameters --> the readability is bad,increases the library size as it will contains many functions to cover all the test cases and violates the dont repeat yourself concept
// so this library is not generic , and the requirements can include test cases that is not covered using overloading
// -----------------------------------------
// metaprogramming  is a paradigm for writing code like oop and evaluated at compile time
// there are two entities that work on the code -->compiler and cpu
// code.cpp is processed using the compiler then executed using the cpu

// metaprogramming make use of the compile time to generate code at compile time using two keywords :templates,constexpr
// these keywords must be on the code for the compiler to process them and generate code at the compile time
// to apply meta programming in our code we must add templates and constexpr in our code.
// --------------------------------
// templates helps in making the code generic
// generic code:code that work with any data type ,in the previous code when new requirement comes with new datatype needed we used overloading and the increased number of parameter  which is not true

// ----------------------------------------
// refactoring sum functions using templates
// 3-using template programming in main.cpp file,the function became independent on the input datatype
// -------------------------------------------
// 4- this case causes  undefined reference to int sum<int>(int, int, int) ,this problem explained in details in canva
// template<typename T>
// T sum(const T a,const T b,const T c){
//     return a+b;
// }
// ------------------
// 5-solving the previous problem the definition must be put in math.hpp and included in main.cpp
// -------------------------------------------


