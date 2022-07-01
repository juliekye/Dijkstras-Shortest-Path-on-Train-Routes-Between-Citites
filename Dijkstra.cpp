#pragma once
//********************************************************************
// Julie Kye
// Project: Dijkstra's Shortest Path Algorithm
// File: Dijkstra.cpp
// Description: source file for Dijkstra's shortest path program
//********************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "ArrivalCityList.h"
#include "Graph.h"
#include "MinPriorityQueue.h"

using namespace std;

void getCityInfo(string oneLine, string& depCityName, ArrivalCityList* arrCityList);
void getArrCityInfo(string oneArrCityInfo, string& arrCityName, double& dist);
void printMenu();
ArrivalCityList* arrCityList;
string depCityName, arrCityName;
double dist = 0.0;
bool performDijkstra = true;

int main()
{
    printMenu();
    while (performDijkstra == true) {
        int count;       //count for number of cities
        string oneLine, sourceCityName;
        cout << "Enter number of cities: "; //total of all cities to be provided 
        cin >> count;
        cin.ignore(20, '\n');

        //For each line of input, we will create a ArrivalCityList (linked list) 
        //to store all reachable arrival cities with distances for a specific departure city
        //Here we use an array of City to store them 
        City* cityArr = new City[count]; //City struct from minheap

        //Initialize each arrival city list 
        //Set each node's distance value to be very large 30000
        for (int i = 0; i < count; i++)
        {
            cityArr[i].d = 30000; // represent infinity
            cityArr[i].pi = NULL; //initialize predecessor to nil
        }

        //get input line by line
        for (int i = 0; i < count; i++)
        {
            arrCityList = new ArrivalCityList();
            cout << "\nEnter departure city and its arrival cities with distances: " << endl; //prompt user for city info
            getline(cin, oneLine);
            cin.clear();
            getCityInfo(oneLine, depCityName, arrCityList); // extract info from user input 
            cityArr[i].cityName = depCityName; //departure city name
            cityArr[i].arrCityList = arrCityList; 
        }

        //after all routes are provided, enter source city name to find all shortest paths from
        cout << "Enter source city name: " << endl;
        getline(cin, sourceCityName);

        //create a MinPriorityQueue with capacity of double the count
        MinPriorityQueue* cityHeap = new MinPriorityQueue(count * 2);

        //insert each City objects one by one inside cityHeap
        for (int i = 0; i < count; i++)
        {
            cityHeap->insert(cityArr[i]);
        }

        //create a Graph object by using its constructor
        Graph* graph1 = new Graph(cityHeap->getSize(), cityHeap);

        //Run Dijkstra algorithm on the graph
        graph1->dijkstra(sourceCityName);

        printMenu();
    }

}

//****************************************************************************
//This function from one line, get all city info.
void getCityInfo(string oneLine, string& depCityName, ArrivalCityList* arrCityList)
{
    // departure city is first city listed
    string delimiter = ",";
    int pos = oneLine.find(delimiter);
    string token = oneLine.substr(0, pos);
    depCityName = token;
    oneLine.erase(0, pos + delimiter.length());

    getArrCityInfo(oneLine, arrCityName, dist); // next get arrival city/cities         
}

//****************************************************************************
//Given one arrival city info. format of, such as New York(611.20), this function
//extract arrival city name 'New York' and distance 611.20 out.
void getArrCityInfo(string oneArrCityInfo, string& arrCityName, double& dist)
{
    if (oneArrCityInfo.empty()) { //if line is finished or no arrival city/cities 
        return;
    }
    if (oneArrCityInfo.length() == 1) { //arrival city DNE if last character is "," 
        arrCityName = "none"; 
        dist = 0; //initialize nonexistent arrival city destination to 0
        oneArrCityInfo.erase(1);
        arrCityList->addArrCity(arrCityName, dist);
        return;
    }
    string firstDelim = "("; // arrival city is found between delimiters , and (
    int pos = oneArrCityInfo.find(firstDelim);
    string token = oneArrCityInfo.substr(0, pos);
    arrCityName = token;
    oneArrCityInfo.erase(0, pos + firstDelim.length());

    string secDelim = ")"; // distance is found between delimiters ( and )
    pos = oneArrCityInfo.find(secDelim);
    token = oneArrCityInfo.substr(0, pos);
    dist = stod(token);
    oneArrCityInfo.erase(0, pos + 2); //delete delimiters ) and ,

    if (arrCityList->addArrCity(arrCityName, dist) == true) {
        getArrCityInfo(oneArrCityInfo, arrCityName, dist); //recursive call for multiple arrival cities
    }
}

//****************************************************************************
void printMenu() {
    string choice;
    cout// << "Options:" << endl
        << "Enter any key to find shortest train routes from a source city to reachable arrivial cities\n" 
        << "Or select one of the options below: \n"
        << "Q\tQuit\n" << "?\tHelp" << endl;
    cin >> choice;
   
    if (choice == "Q" || choice == "q") {
        performDijkstra == false;
        exit(0);
    }
    if (choice == "?") {
        cout << "---- HELP PAGE ----\n"
            << "This program finds the shortest path from one source city to all reachable cities "
            << "using Dijkstra's Shortest Path Algorithm. \n " << endl
            << "The distances are referrencing the number of miles a train from a departure city travels to an arrival city "
            << "Please input departure and arrival city information in this format:"
            << "One Departure City,Arrival City Name(Distance from Departure to Arrival City),Another Arrival City Name(Distance),\n"
            << endl;
        printMenu();
    }
}
