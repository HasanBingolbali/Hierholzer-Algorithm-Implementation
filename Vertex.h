//
//  Vertex.h
//  PROJECT3
//
//  Created by Hasan on 31.12.2020.
//
//#include <vector>
#include <queue>
using namespace std;
#ifndef Vertex_h
#define Vertex_h

class Vertex{
    public:
    long ID;
    Vertex(long ID);
    long inDegree=0;
    long outDegree=0;
    bool hasNonUsedEdge=true;
    queue<long> EdgeQueue;
    vector<long> vectorr;
    long numberOfExerted=0;
    long lastUsedElement=0;
    long getFirstNonUsedEdge();
    Vertex();
    Vertex(const Vertex& vertex){
        this->ID = vertex.ID ;
        this->inDegree=vertex.inDegree;
        this->outDegree=vertex.outDegree;
        this->EdgeQueue = vertex.EdgeQueue;
    }
 //   void getFirstNonUsedEdge();
};
Vertex::Vertex(){
    
}

Vertex::Vertex(long ID){
    this->ID = ID ;
}
 long Vertex::getFirstNonUsedEdge(){
     
     
            numberOfExerted++;
            if(numberOfExerted== vectorr.size()){
                this->hasNonUsedEdge = false ;
            }
     lastUsedElement++;
     return vectorr.at(lastUsedElement-1);
            
    
     
}


#endif /* Vertex_h */
