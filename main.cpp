//
//  main.cpp
//  PROJECT3
//
//  Created by Hasan on 30.12.2020.
//
#include <fstream>
#include <queue>
#include <set>
#include <chrono>
#include <iostream>
#include "Vertex.h"
#include <list>
#include <iterator>
    using namespace std;
void print(std::vector <long> const &a) {
   std::cout << "The vector elements are : ";

   for(int i=0; i < a.size(); i++)
   std::cout << a.at(i) << ' ';
}
void print(std::list<long> const &list)
{
    for (auto const& i: list) {
        std::cout << i << " ";
    }
}


int main(int argc, const char * argv[]) {
    
    
    
    
    ifstream myfile ;
    myfile.open(argv[1]);
    myfile.sync_with_stdio(false);
    myfile.tie(NULL);
    ofstream outfile;
    outfile.open(argv[2]);
    long numberOfCrossingPolongs;
    myfile >> numberOfCrossingPolongs ;
    //cout << numberOfCrossingPolongs;
    
    vector<Vertex*> Vertexes ;
    
    Vertexes.reserve(numberOfCrossingPolongs);
        for(long i=0 ; i < numberOfCrossingPolongs ; i++){
        
        Vertexes.push_back(new Vertex(i));
    }
    long numberOfEdges=0;
   
    for(long i=0; i< numberOfCrossingPolongs ; i++){
        ;
        //cout << numberOfCrossingPolongs << endl;
        long indx ;
        myfile >> indx;
        long iterationTime;
        myfile >> iterationTime;
        Vertexes.at(i)->outDegree= iterationTime;
        Vertexes.at(i)->vectorr.reserve(iterationTime);
        for(long j=0; j < iterationTime ; j++){
            
           long AddedIndex;
            
            myfile >> AddedIndex;
            Vertexes.at(AddedIndex)->inDegree++;
            numberOfEdges++;
        // Vertexes.at(i)->EdgeQueue.push(AddedIndex);
         Vertexes.at(i)->vectorr.push_back(AddedIndex);
        }
    }
    long startingIndex;
    myfile >> startingIndex;
    //cout << startingIndex;
   for(int i=0 ; i< Vertexes.size(); i++){
        if(Vertexes.at(i)->inDegree != Vertexes.at(i)->outDegree){
          outfile <<  "no path";
            return 0;
        }
    }
    
    list <long> eulerianCircuit ;
    long currentIndex= startingIndex;
    std::list<long>::iterator it;
   
    
    while(eulerianCircuit.size()< numberOfEdges){
       
        list <long> tour ;
        
        while (Vertexes.at(currentIndex)->hasNonUsedEdge) {
            
            currentIndex= Vertexes.at(currentIndex)->getFirstNonUsedEdge();
            
            tour.push_back(currentIndex);
            
        }
        //print(tour) ;
        //cout << endl;
        
        
        if(eulerianCircuit.empty()){
            eulerianCircuit=tour;
        }
        
        else{
            it++;
            
          eulerianCircuit.insert(it , tour.begin(),tour.end());
            
        }
        std::list<long>::iterator it2;
        for( it2 = eulerianCircuit.begin(); it2 != eulerianCircuit.end();it2++){
            
           if( Vertexes.at(*it2)->hasNonUsedEdge){
              
               currentIndex = *it2;
               
               it = it2;
               
              // cout << *it;
                break;
            }
        }
        
      }
    outfile << startingIndex << " " ;
    for (auto const& i: eulerianCircuit) {
        outfile << i << " ";
    }
    
    
    return 0;
}
