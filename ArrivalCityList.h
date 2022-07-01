#pragma once
//********************************************************************
// Julie Kye
// Project: Dijkstra's Shortest Path Algorithm
// File: ArrivalCityList.h
// Description: functions for ArrivalCityList
//********************************************************************

#include <string>
using namespace std;

//struct ArrCity represents an arrival city information with
//distance from a specific departure city
struct ArrCity
{
    string arrCityName;
    double distance;
    struct ArrCity* next;
};

//class ArrivalCityList is a linked list of ArrCity
class ArrivalCityList
{
private:
    struct ArrCity* head;

public:
    ArrivalCityList();
    ~ArrivalCityList();
    ArrCity* getHead();
    ArrCity* findArrCity(string oneCity);
    bool addArrCity(string oneCity, double distance);
    void printArrCityList();
    int listSize;
    void addPrintCity(string cityName);
};

ArrivalCityList::ArrivalCityList() {   //constructor
    head = NULL;
    listSize = 0;
}

ArrivalCityList::~ArrivalCityList() {   //destructor
    ArrCity* current = head;
    while (current != NULL) {
        ArrCity* temp = current->next;
        delete current;
        current = temp;
    }
    head = NULL;
}

ArrCity* ArrivalCityList::getHead() {
    return head;
}

ArrCity* ArrivalCityList::findArrCity(string oneCity) {
    ArrCity* tempCity = head;
    while (tempCity != NULL) {
        if (tempCity->arrCityName.compare(oneCity) == 0) {
            cout << tempCity->arrCityName << tempCity->distance << endl;
            return tempCity;
        }
        tempCity = tempCity->next;
    }
    return NULL;
}

// used to print shortest path from source to arrival city in correct order
void ArrivalCityList::addPrintCity(string cityName) { 
    ArrCity* printCity = new ArrCity();
    printCity->arrCityName = cityName; //add to head of list
    printCity->distance = 0;
    printCity->next = head;
    head = printCity;
}

bool ArrivalCityList::addArrCity(string oneCity, double distance) {
    // add arrival cities in alphabetic order
    ArrCity* newCity = new ArrCity();
    listSize++;
    //add attributes
    newCity->arrCityName = oneCity;
    newCity->distance = distance;
    ArrCity* prevCity = NULL;
        
    if (head == NULL) { // add first element
        head = newCity;
        newCity->next = NULL;
        return true;
    }
    else { // maintain alphabetical order
        ArrCity* tempCity = head;
        while (tempCity != NULL) {
            int i = 0; // ith letter of cityName
            while (newCity->arrCityName.at(i) == tempCity->arrCityName.at(i)) {
                i++;
            }
            if (newCity->arrCityName.at(i) < tempCity->arrCityName.at(i)) {
                if (prevCity == NULL) {
                    head = newCity;
                    head->next = tempCity;
                    return true;
                }
                else {
                    prevCity->next = newCity;
                    newCity->next = tempCity;
                    return true;
                }
            }
            if (newCity->arrCityName.at(i) > tempCity->arrCityName.at(i)) {
                prevCity = tempCity;
                tempCity = tempCity->next;
            }
        }
        prevCity->next = newCity;
        return true;
    }
    return false; //default
}

void ArrivalCityList::printArrCityList() { //print arrival cities with distances
    ArrCity* tempCity = getHead();
    if (tempCity == NULL) {
        cout << "Arrival city list is empty" ;
    }
    while (tempCity != NULL) {
        if (tempCity->arrCityName == "none") {
            cout << "Arrival city list is empty";
            break;
        }
        cout << tempCity->arrCityName << "(" << tempCity->distance << ")";
        tempCity = tempCity->next;
    }
    cout << endl;
}


