#include "Coordinate.hpp"
#include "exeptions.hpp"
#include <iostream>
using namespace std;

Coordinate::Coordinate(){}
Coordinate::Coordinate(char someChar){
     c = someChar;
}
Coordinate::Coordinate(uint i ,uint j){
    index_i = i;
    index_j = j;
}
ostream& operator<< (ostream& out,Coordinate& s){
   return cout <<s.index_i<<","<<s.index_j<<endl;
}
char& Coordinate::operator=(char someChar){
    if(someChar=='X'||someChar=='O'||someChar=='.'){
        return c = someChar;  
    }
    else{
        throw(IllegalCharException(someChar));
    }
}
Coordinate::operator char(){
   return c;
}
bool Coordinate::operator==(char someChar)const{
    if(c==someChar){
       return true;
   }
   return false;
}