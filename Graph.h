#pragma once
//********************************************************************
// Julie Kye
// Project: Dijkstra's Shortest Path Algorithm
// File: Graph.h
// Description: This is the header file that defines a weighted directed graph
//********************************************************************

#include <string>
#include "MinPriorityQueue.h"

using namespace std;

class Graph
{
private:
    int numOfNode;                 //number of nodes in the graph
    MinPriorityQueue* cityHeap;    //adjacency list (min-heap) of departure City objects
    MinPriorityQueue* S; //updated cityHeap 

public:
    Graph(int numOfNode, MinPriorityQueue* cityHeap);
    void destructor();
    void initialize_single_source(string sourceCityName);
    void relax(City u, ArrCity v); 
    void dijkstra(string sourceCityName);
    void printDijkstraPath(string sourceCityName);
    void printPath(string sourceCityName, City aCity);
};

Graph::Graph(int numOfNode, MinPriorityQueue* cityHeap) //Constructor
{
    this->numOfNode = numOfNode;
    this->cityHeap = cityHeap;
}

void Graph::destructor() //Destructor Graph::~Graph()
{
    delete[] cityHeap;
    cityHeap = NULL;
    numOfNode = 0;
}

void Graph::initialize_single_source(string sourceCityName) {
    //update source city to distance of 0
    int srcIndex = cityHeap->isFound(sourceCityName);
    City source = cityHeap->getCityArr()[srcIndex];
    source.d = 0;
    source.cityName = sourceCityName;
    cityHeap->decreaseKey(srcIndex, source);
}

void Graph::relax(City u, ArrCity v) { //maintain shortest distance of vertex City
    int index = cityHeap->isFound(v.arrCityName);
    /*if (QIndex == -1) {
        return;
    }*/
    City cityV = cityHeap->getCityArr()[index];
    if (cityV.d < (u.d + v.distance)) { //previous distance already is shortest
        return;
    }
    cityV.d = u.d + v.distance; 
    if (cityHeap->decreaseKey(index, cityV) == true) { //update with shortest distance
        int newIndex = cityHeap->isFound(cityV.cityName);
        City* parent = new City();
        *parent = u; //edge City with shortest distance is the new predecessor
        parent->pi = u.pi; 
        cityHeap->getCityArr()[newIndex].pi = parent; //update predecessor
    }        
}

void Graph::dijkstra(string sourceCityName) {
    S = new MinPriorityQueue(cityHeap->getSize()); //updated heap of shortest paths

    initialize_single_source(sourceCityName); //update distance of source vertex
    cityHeap->printHeap(); // show intialized graph before Disktra

    while (cityHeap->getSize() > 0) { 
        City* u = new City(); //departure city
        *u = cityHeap->getHeapMin();
        cityHeap->extractHeapMin(); //delete city from original heap
        S->insert(*u); //insert into updated heap
        ArrCity* v = u->arrCityList->getHead(); //head of arrival city list of u 
        while (v != NULL) {  //go through each adjacent vertex v of u
            if (v->arrCityName == sourceCityName && v->next == NULL) {
                break;
            }
            if (v->arrCityName == "none" && v->next == NULL) {
                break;
            }
            if (v->arrCityName == "none" || v->arrCityName == sourceCityName) {
                v = v->next; 
            }
            relax(*u, *v); //determine if edge of vertices u and v
                           //is apart of v's shortest path 
            v = v->next; 
        }
    }
    if (cityHeap->getSize() == 0 && S->getSize() != 0) { //when original heap is empty print final result
        printDijkstraPath(sourceCityName);
    }
}
void Graph::printDijkstraPath(string sourceCityName) {
    cout << "Print the Dijkstra algorithm running result \n" << endl;
    cout << "Source City: " << sourceCityName << "\n" << endl;
    cout << left;
    cout << setw(15) << "Arrival City"
        << setw(15) << "Shortest Dist."
        << setw(15) << "Shortest Path" << endl;
    
    while (S->getSize() > 0) { //repeat until final heap is empty
        City printCity = S->getHeapMin();
        S->extractHeapMin();
        cout << setw(15) << printCity.cityName
            << setw(15) << fixed << setprecision(2) << printCity.d;
        printPath(sourceCityName, printCity); // print each shortest path 
    }
    cout << endl;
}

void Graph::printPath(string sourceCityName, City aCity) { 
    ArrivalCityList* printList = new ArrivalCityList(); 
    string printingCity = aCity.cityName; //arrival city
    if (aCity.cityName == sourceCityName) { 
        cout << sourceCityName << endl;
        return;
    }
    else {
        printList->addPrintCity(printingCity); //add arrival city to shortest 
                                               //path list to be printed in correct order
        while (aCity.pi != NULL && aCity.cityName != sourceCityName) {
            printList->addPrintCity(aCity.pi->cityName); //predecessor is added to head of printList
            aCity = *aCity.pi; //iterate through all predecessors until source city
        }
    }
    ArrCity* tempPrint = printList->getHead();
    // print shortest path starting with source city
    while (tempPrint != NULL && tempPrint->arrCityName != printingCity) {
        cout << tempPrint->arrCityName << "->";
        tempPrint = tempPrint->next;
    }
    // finally print arrival city
    cout << printingCity << endl; 
}

