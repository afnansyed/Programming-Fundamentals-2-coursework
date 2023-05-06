#pragma once
#include <iostream>
#include <exception>

using namespace std;

template<typename T>
class ABS{
    int maxCapacity;
    int size;
    float scale_factor = 2.0f;
    T* sData;
public:

    ABS();   //default constructor
    ABS(int capacity);   //constructor
    ABS(const ABS &d);   //copy constructor
    ABS &operator=(const ABS &d);   //assignment operator
    ~ABS();  //destructor

    void push(T data);    //add data to the top
    T pop();   //remove data at the top
    T peek();   //return value of data at the top

    //accessors
    unsigned int getSize();
    unsigned int getMaxCapacity();
    T* getData();
};


//default constructor
template<typename T>
ABS<T>::ABS(){
    maxCapacity = 1;
    size = 0;
    sData = new T[maxCapacity];
}

//constructor
template<typename T>
ABS<T>::ABS(int capacity){
    maxCapacity = capacity;
    size = 0;
    sData = new T[maxCapacity];
}

//copy constructor
template<typename T>
ABS<T>::ABS(const ABS &d) {
    this->maxCapacity = d.maxCapacity;
    this->size = d.size;

    // deep copy for array in copy constructor.  Reference: Prof. Fox lecture, Zybooks Reference: 11.2
    sData = new T[maxCapacity];  // create new array, Zybooks reference: 10.3
    for (int i =0; i < maxCapacity; i++){  //copy old array to new array
        sData[i] = d.sData[i];
    }
}

//assignment operator
template<typename T>
ABS<T>& ABS<T>::operator=(const ABS &d) {
    this->maxCapacity = d.maxCapacity;
    this->size = d.size;

    // deep copy for array in assignment operator.  Zybooks Reference: 11.2
    delete[] sData; //delete old array
    sData = new T[maxCapacity];  // create new array, Zybooks reference: 10.3
    for (int i =0; i < maxCapacity; i++){  //copy old array to new array
        sData[i] = d.sData[i];
    }
}

//destructor
template<typename T>
ABS<T>::~ABS(){
    delete[] sData;
}

template<typename T>
void ABS<T>::push(T data) {

    if(maxCapacity > size){
        sData[size] = data;  //add element to top of the stack, Zybooks reference: 7.12
    }
    //resizing
    else{
        //Reference to steps: Prof. Fox lecture 'writing dynamic array'
        // these steps given in lab 3 document

        //1.Create a new array based on the desired size
        maxCapacity = maxCapacity*scale_factor;  //new capacity (desired size)
        T* newData = new T[maxCapacity];  //new array

        // 2.Copy elements from the old array to the new array
        // here, int size is smaller than capacity, Zybooks Reference: 11.2
        for(int i = 0; i < size; i++){
            newData[i] = sData[i];
        }

        // 3.If you were adding something to the array, copy that as well
        newData[size] = data; //adding new element

        // 4.Delete the old array
        delete[] sData;  //Zybooks reference: 10.3

        // 5.Redirect the pointer to the old array to the new array
        // here both are pointers
        sData = newData;
    }

    size++;
}

//Remove the item at the top of the stack
template<typename T>
T ABS<T>::pop() {
    //element on the top of the stack
    T numS = sData[size - 1];

    //if stack is empty, throw error
    if(size < 1){
        throw runtime_error("An error has occurred.");
    }
    else{  //remove element on top
        size = size - 1;  //reducing the size; Reference: T.A James Horn on Slack

        //resizing
        float percentFull = ((float)size/maxCapacity);  //percentage the stack in full
        if (percentFull < (1 / scale_factor)) {  //if less than 1/scale_factor
            maxCapacity = maxCapacity / scale_factor;  //new capacity
        }
    }

    return numS;  //return element removed
}

//Return the value of the item at the top of the stack
template<typename T>
T ABS<T>::peek() {
    T topNum;
    topNum = sData[size-1]; //element on top of the stack

    //if stack is empty
    if(size < 1){
        throw runtime_error("An error has occurred.");
    }

    return topNum;
}

//-----Accessors-----

//Returns the current number of items in the ABS.
template<typename T>
unsigned int ABS<T>::getSize() {
    return size;
}

//Returns the current max capacity of the ABS.
template<typename T>
unsigned int ABS<T>::getMaxCapacity() {
    return maxCapacity;
}

//Returns the array representing the stack.
template<typename T>
T* ABS<T>::getData() {
    return sData;
}







