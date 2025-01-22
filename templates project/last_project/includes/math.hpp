#ifndef _MATH_HPP_
#define _MATH_HPP_
#include<iostream>
#include<type_traits>
using namespace std;

// namespace subtraction{

// template<typename T>
// auto sub(const T &a){
// static_assert(is_arithmetic<T>::value,"T  must be arithmatic values");

//     return a;
// }

// auto sub(){
//     return 0;
// }

// template<typename T,typename U,typename ...TS>
// auto sub(const T&a,const U &b,const TS&...values){
// static_assert(is_arithmetic<T>::value&&is_arithmetic<U>::value,"T ,U ,TS must be arithmatic values");
// auto r=a-b;
// return (sub(r,values...));
// }

// }





namespace maximum{

template <typename T>
auto max(const T &a){
static_assert(is_arithmetic<T>::value,"T must be arithmatic values");

return a;
}

auto max(){
return 0;
}


template <typename T,typename U ,typename ...TS >
auto max(const T &a,const U &b,const TS&... values){
static_assert(is_arithmetic<T>::value&&is_arithmetic<U>::value,"T ,U ,TS must be arithmatic values");
int max_value=0;
if (a>b) max_value=a;
else max_value=b;
return max (max_value,values...);
}

}

namespace minimum{

template <typename T>
auto min(const T &a){
static_assert(is_arithmetic<T>::value,"T must be arithmatic values");

return a;
}

auto min(){
return 0;
}


template <typename T,typename U ,typename ...TS >
auto min(const T &a,const U &b,const TS& ...values){
static_assert(is_arithmetic<T>::value&&is_arithmetic<U>::value,"T ,U ,TS must be arithmatic values");
int min_value=0;
if (a<b) min_value=a;
else min_value=b;
return min (min_value,values...);
}

}

template <typename T>
class custom {

public:


auto sub(const T &a,const T &b){
  auto r=a-b;
  return r;
}

private:


};
template <>
class custom <string>{

public:


int sub(const string &a,const string &b){
  int r=a.length()-b.length();
  return r;
}

private:
string m_b;

};
#endif

