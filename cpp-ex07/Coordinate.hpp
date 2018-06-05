#include <iostream>
using namespace std;

class Coordinate{
    private:
    char c;
    int index_i;
    int index_j;
    public:
    Coordinate();
    Coordinate(char someChar);
    Coordinate(uint i,uint j);
    int const getIndexI()const {return index_i;}
    int const getIndexJ()const{return index_j;}
    friend ostream& operator<< (ostream& out,Coordinate& s);
    char& operator=(char someChar);
    operator char();
    bool operator==(char someChar)const;
};
