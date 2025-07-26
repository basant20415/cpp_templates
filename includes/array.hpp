#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_
#include<iostream>
#include<type_traits>
using namespace std;

// template<typename T,size_t N>//template parameter,non-template parameter
// class array{
// public:

// explicit array(const T init_val=0){//constructor
//     for(auto &i:this->buffer){
//         i=init_val;
//     }
// }

// // subscript operator
// // The subscript operator is the operator that allows access to elements of an object using square brackets []. 
// // here we are making overloading to the subscript operator
// T& operator[](const size_t i) {
//     return buffer[i];
// }


// size_t max_size() const{//const --> enforces read only behaviour inside the function
//     return this->max_elements;
// }
// private:
// //member variables
// size_t max_elements[N];

// T buffer[N];

// };


//new requirement array class should implement a function called print_string incase datatype is char[]

// class template specialization

template<size_t N>//non-template parameter
class array<char[],N>{//template to be matched "partial template specialization"

public :

char& operator[](const size_t i) {
    return buffer[i];
}

void print_string(){

    cout<<this->buffer;
}

private:
char buffer[N];
};
// template<>
// class array<char[],10>{ full template specialization

// private:
// char buffer[10];
// }

// if the data types used are not from the basic data type tell the compiler not to generate code and generate error
//tell the compiler to pass this function only if it works only with basic datatypes
// go to cpp reference then find typetraits
#endif