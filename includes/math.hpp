#ifndef _MATH_HPP
#define _MATH_HPP
#include<string>
#include<type_traits>
using namespace std;
// 1-provide function that gives sum of two numbers 
// int sum(const int a ,const int b);
// --------------------------------------
// 2-
// there is concept named "the only constant is change" --> this means that the requirement of the current app can be changed in the future 
// the second requirement is --> the library must provide a function that provides two doubles
// -->so simple way overloading 
// double sum(double a,double b);

// unsigned int sum(unsigned int  a,unsigned int  b);


// double sum(double a,double b,double c); 
// -------------------------------------------
// 4-
// template<typename T>
// T sum(const T a,const T b,const T c);

// -----------------------------
// 5-
// template<typename T>
// T sum(const T a,const T b,const T c){
//     return a+b+c;
// }

// template<typename T>
// T sum(const T a,const T b){
//     return a+b;
// }

// -------------------------------------------
// 6- a new requirement is to calculate the sum of two numbers of different data types
// template<typename T,typename U>
// T sum(const T & a,const U & b){
//     return a+b;
// }
// auto sum(const T & a,const U & b){
//     return a+b;
// }
// ----------------------------------------
// 7-new requirement: incase two parameters are strings the function must return the sum of lengthes of two strings
// template<typename T,typename U>
// auto sum(const T & a,const U & b){
//     return a+b;
// }// this way will cause concatenation

// // function template specialization
// // specialized case with specific data types
// template<>
// auto sum<string,string>(const string & a,const string & b){
//     return a.length()+b.length();
// }
// the general form must be above the specialization,when instantiation the compiler will run the specialized one not the generic(<string,string>)
// -------------------------------------------------------
//8- variadic template
// template can take more than one argument and the caller is the one who determine this number
// new requiremenet :calculate sum of unknown number of argument of any datatypes
   

// no of arguments
// // 0 or more
int sum(){
    return 0;
}
// 1 or more
template<typename T>
auto sum(const T& a){
    static_assert(is_arithmetic_v<T>,"T must be arithmetic");

    return a;
}
// 2 or more
template<typename T,typename U,typename ... TS>//parameter packing
// TS... is a pack of zero or more additional types.
auto sum(const T & a,const U & b,const TS & ... values){
// solution 1:tail recursion
// check number of arguments --->values
// values=0--->return a+b;
static_assert(is_arithmetic_v<T>&&is_arithmetic_v<U>,"T & U must be arithmetic");

if constexpr (sizeof ... (TS)>0) { // gets the number of types in the parameter pack 
    // sizeof is evaluated at compile time but why we are using constexpr ? if constexpr makes the compiler skip 
    // compiling the unused branch(else) in case of true condition, avoiding errors or unnecessary template instantiations.
    // constexpr introduced in c++17

    auto r=a+b;
    return sum (r,values ...);//parameters unpack
    // values... spreads the rest of the arguments as individual arguments.
    

}else{

    return a+b;
}
}

// // solution 2:folding expression introduced in c++17
// template<typename T ,typename U, typename ... TS>
// auto sum(const T & a,const U & b,const TS &... values) {

//     //programming by contract :contract with the user o input the T & U as basic arithmetic  types
//     static_assert(is_arithmetic_v<T>&&is_arithmetic_v<U>,"T & U must be arithmetic")
// auto r=a+b;
// return (sum(r,values ...));// searches for function that handles one argument in sum function
// // return r+sum(values ...); // this is another way but takes less number of calls and gives us better performance but this way forces us to implement function with zero arguments
// }


 //tail recursion uses more function calls than folding expression
// --------------------------------
// 9- array
// when we go to cpp reference -->array we find that array is class template not function template 
// new requirement :create a generic class for array to give the caller capability to create an array of any data type-->array.hpp


// ------------------------------------
// typetraits
// enforces the functions to accept specific data types only-->static_assert
// go to cpp reference you can find many questions other than is_arithmetic_v to be used
// --------------------
// our math library should be wrapped inside namespace called lib to avoid conflict with anoher library
// if we had two functions named sum in the same code base but each one is doing different functionality ,here the linker might cause an error
// so when using namespace we are creating different scope
// for using this scope we use the scope resolution operator lib::sum(100,200) or using namespace lib;
// but the scope resolution operator is more correct as the other can still cause naming error ,
// if we are adding using namespace lib; using namespace lib2; in the header and the two scopes containing sum function the linker will cause an error
namespace lib{

int sum(){
    return 0;
}
// 1 or more
template<typename T>
auto sum(const T a){
    static_assert(is_arithmetic_v<T>,"T must be arithmetic");

    return a;
}
// 2 or more
template<typename T,typename U,typename ... TS>//parameter packing
// TS... is a pack of zero or more additional types.
auto sum(const T & a,const U & b,const TS & ... values){
// solution 1:tail recursion
// check number of arguments --->values
// values=0--->return a+b;
if constexpr (sizeof ... (TS)>0) { // gets the number of types in the parameter pack 
    // sizeof is evaluated at compile time but why we are using constexpr ? if constexpr makes the compiler skip 
    // compiling the unused branch(else) in case of true condition, avoiding errors or unnecessary template instantiations.
    // constexpr introduced in c++17
        static_assert(is_arithmetic_v<T>&&is_arithmetic_v<U>,"T & U must be arithmetic");

    auto r=a+b;
    return sum (r,values ...);//parameters unpack

}else{
    return a+b;
}

}
 };
#endif