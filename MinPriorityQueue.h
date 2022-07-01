#pragma once
//****************************************************************************
// Julie Kye
// Project: Dijkstra's Shortest Path Algorithm
// File: MinPriorityQueue.h
// Description: minimum priority queue for maintaining shortest path distances
//****************************************************************************

#include <string>
#include "ArrivalCityList.h"
#include "Graph.h"

using namespace std;

//City represent a vertex of the graph which is a departure City
struct City
{
    string cityName;
    double d; //distance
    struct City* pi;
    ArrivalCityList* arrCityList;
};

//class MinPriorityQueue represents a Min-heap that contains City objects.
//The key of each City is its d value
//(the underlying data structure is a one dimensional array of City objects)
class MinPriorityQueue
{
private:
    struct City* cityArr;	//a City array
    int capacity, size;

public:
    MinPriorityQueue(int capacity);
    ~MinPriorityQueue();

    City* getCityArr();
    int getSize();
    int getCapacity();
    int isFound(string cityName);
    bool decreaseKey(int index, City oneCitywithNewD);
    bool insert(City oneCity);
    void heapify(int index);
    City getHeapMin();
    void extractHeapMin();
    int leftChild(int parentIndex);
    int rightChild(int parentIndex);
    int parent(int childIndex);
    void printHeap();
};

MinPriorityQueue::MinPriorityQueue(int capacity) { //constructor
    this->capacity = capacity;
    size = 0;
    cityArr = new City[capacity];
    for (int i = 0; i < capacity; i++) { //initialize city array with City objects
        cityArr[i] = City();
    }
}

MinPriorityQueue:: ~MinPriorityQueue() { //destructor
    int numDeleted = 0;
    int totalCities = size -1;
    for (int i = 0; i < size; i++) {
        delete[i] cityArr;
    }
}

City* MinPriorityQueue::getCityArr() {
     return cityArr;
}

int MinPriorityQueue::getSize() {
    return size;
}

int MinPriorityQueue::getCapacity() {
    return capacity;
}

int MinPriorityQueue::isFound(string cityName) {
    for (int i = 0; i < size; i++) {
        if (cityArr[i].cityName.compare(cityName) == 0) {
            return i; //return index 
         }
    }
    return -1; //default
}

bool MinPriorityQueue::decreaseKey(int index, City oneCitywithNewD) {
    int i = index;
    if (isFound(oneCitywithNewD.cityName) == -1 || oneCitywithNewD.d > cityArr[index].d) {
        return false; //not found or new d is greater than current 
    }
    cityArr[i].d = oneCitywithNewD.d;
    while ((i > 0) && (cityArr[parent(i)].d > cityArr[i].d)) { // maintain min-heap property
        swap(cityArr[i], cityArr[parent(i)]);
        i = parent(i);
    }
    return true;
}

bool MinPriorityQueue::insert(City oneCity) {
    int i = getSize();
    if (i == capacity) { // overflow
        return false;
    }
    size++;
    City* newCity = new City;
    newCity->cityName = oneCity.cityName;
    newCity->d = oneCity.d;
    newCity->pi = oneCity.pi;
    newCity->arrCityList = oneCity.arrCityList;
    cityArr[i] = *newCity;

    while ((i > 0) && (cityArr[parent(i)].d > cityArr[i].d)) {
        swap(cityArr[i], cityArr[parent(i)]);
        i = parent(i);
    }
    return true;
}

void MinPriorityQueue::heapify(int index) { // maintain min-heap property
    int min = index;
    int i = index;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < size && cityArr[l].d < cityArr[min].d) {
        min = l;
    }
    if (r < size && cityArr[r].d < cityArr[min].d) {
        min = r;
    }
    if (min != i) {
        swap(cityArr[i], cityArr[min]);
        heapify(min);
    }
}

City MinPriorityQueue::getHeapMin() { //return min element
    return cityArr[0];
}

void MinPriorityQueue::extractHeapMin() { // deletes min element
    if (size == 0){
        return;
    }
    City heapmin = cityArr[0];
    cityArr[0] = cityArr[size - 1]; //1
    size = size - 1;
    heapify(0);
}

int MinPriorityQueue::leftChild(int parentIndex) {
    int leftChild = 2 * parentIndex + 1;
    return leftChild;
}

int MinPriorityQueue::rightChild(int parentIndex) {
    int rightChild = 2 * parentIndex + 2;
    return rightChild;
}

int MinPriorityQueue::parent(int childIndex) {
    int parent = (childIndex-1) / 2;
    return parent;
}

void MinPriorityQueue::printHeap() { // for printing inital graph before dijsktra
    cout << "\nInitialized graph before Dijsktra's: \n" << endl;
    //cout << "Heap size = " << size << "\n" << endl;
    cout << left;
    cout << setw(15) << "City Name"
        << setw(12) << "d Value"
        << setw(15) << "PI"
        << "Arrival City List" << endl;
    for (int i = 0; i < size; i++) {
        if (cityArr != NULL) {
            cout << left;
            cout << setw(15) << cityArr[i].cityName
                << setw(12) << fixed << setprecision(2) << cityArr[i].d
                << setw(15) << "No parent";
                cityArr[i].arrCityList->printArrCityList();
        }
    }
    cout << "\n" << endl;
}

