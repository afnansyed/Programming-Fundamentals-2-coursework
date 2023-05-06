#pragma once
#include <exception>
#include <iostream>
using namespace std;

template<typename T>
class ABQ{
    int maxCapacity;
    int size;
    float scale_factor = 2.0f;
    T* qData = nullptr;
public:

    ABQ();   //default constructor
    ABQ(int capacity);   //constructor
    ABQ(const ABQ &d);   //copy constructor
    ABQ &operator=(const ABQ &d);   //assignment operator
    ~ABQ();  //destructor

    void enqueue(T data);    //add data to the top
    T dequeue();   //remove data at the top
    T peek();   //return value of data at the top

    //accessors
    unsigned int getSize();
    unsigned int getMaxCapacity();
    T* getData();

};

//default constructor
template<typename T>
ABQ<T>::ABQ(){
    maxCapacity = 1;
    size = 0;
    qData = new T[maxCapacity];
}

//constructor
template<typename T>
ABQ<T>::ABQ(int capacity){
    maxCapacity = capacity;
    size = 0;
    qData = new T[maxCapacity];
}

//copy constructor
template<typename T>
ABQ<T>::ABQ(const ABQ &d) {
    this->maxCapacity = d.maxCapacity;
    this->size = d.size;

    // deep copy for array in copy constructor.  Reference: Prof. Fox lecture, Zybooks Reference: 11.2
    qData = new T[maxCapacity];  // create new array, Zybooks reference: 10.3
    for (int i =0; i < maxCapacity; i++){  //copy old array to new array
        qData[i] = d.sData[i];
    }
}

//assignment operator
template<typename T>
ABQ<T>& ABQ<T>::operator=(const ABQ &d) {
    this->maxCapacity = d.maxCapacity;
    this->size = d.size;

    // deep copy for array in assignment operator.  Zybooks Reference: 11.2
    delete[] qData; //delete old array
    qData = new T[maxCapacity];  // create new array, Zybooks reference: 10.3
    for (int i =0; i < maxCapacity; i++){  //copy old array to new array
        qData[i] = d.sData[i];
    }
}

//destructor
template<typename T>
ABQ<T>::~ABQ(){
    delete[] qData;
}


template<typename T>
void ABQ<T>::enqueue(T data) {

    if(maxCapacity > size){
        qData[size] = data;  //add element to top of the queue, Zybooks reference: 7.12
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
            newData[i] = qData[i];
        }

        // 3.If you were adding something to the array, copy that as well
        newData[size] = data; //adding new element

        // 4.Delete the old array
        delete[] qData;  //Zybooks reference: 10.3

        // 5.Redirect the pointer to the old array to the new array
        // here both are pointers
        qData = newData;
    }

    size++;
}

//Remove the item at the top of the queue
template<typename T>
T ABQ<T>::dequeue() {
    //element on the top of the queue
    T numS = qData[0];

    //if queue is empty, throw error
    if(size < 1){
        throw runtime_error("An error has occurred.");
    }
    else{  //remove element in the front

        T* newData = new T[maxCapacity]; //create new array
        for(int i = 0, j = 1; i < maxCapacity; i++, j++){
            newData[i] = qData[j];  //copy elements of old array to new array besides the element at the front
        }

        delete[] qData; //delete old array

        qData = newData; //pointer of old array redirected to new array

        size = size - 1; //reduce int size

        //resizing
        float percentFull = ((float)size/maxCapacity);  //percentage the queue in full
        if (percentFull < (1 / scale_factor)) {  //if less than 1/scale_factor
            maxCapacity = maxCapacity / scale_factor;  //new capacity
        }
    }
    return numS;  //return element removed
}

//Return the value of the item at the front of the queue
template<typename T>
T ABQ<T>::peek() {
    T topNum;
    topNum = qData[0]; //element on front of the queue

    //if queue is empty
    if(size < 1){
        throw runtime_error("An error has occurred.");
    }

    return topNum;
}


//-----Accessors-----

//Returns the current number of items in the ABQ.
template<typename T>
unsigned int ABQ<T>::getSize() {
    return size;
}

//Returns the current max capacity of the ABQ.
template<typename T>
unsigned int ABQ<T>::getMaxCapacity() {
    return maxCapacity;
}

//Returns the array representing the stack.
template<typename T>
T* ABQ<T>::getData() {
    return qData;
}
