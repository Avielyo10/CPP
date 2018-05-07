#include <iostream>
using namespace std;

class IllegalCoordinateException{
    private:
    int first,second;
    public:
        IllegalCoordinateException(pair<int,int> coordinates){
            first = coordinates.first;
            second = coordinates.second;
        }
        string theCoordinate() const{
            return to_string(first)+","+to_string(second);
        }
    friend ostream& operator<< (ostream& out,IllegalCoordinateException ex){
        return cout << ex.first <<","<<ex.second<<endl;
    }
};
class IllegalCharException{
    private:
    char c;
    public:
    IllegalCharException(char someChar){
        c = someChar;
    }
    char theChar() const{
        return c;
    }
    friend ostream& operator<< (ostream& out,IllegalCharException ex){
        return cout << ex.c <<endl;
    }
};