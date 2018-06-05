#include "square.hpp"
#include "exeptions.hpp"
#include <iostream>
using namespace std;

square::square(){}
square::square(char someChar){
     c = someChar;
}
ostream& operator<< (ostream& out,square& s){
   return cout <<s.c;
}
char& square::operator=(char someChar){
    if(someChar=='X'||someChar=='O'||someChar=='.'){
        return c = someChar;  
    }
    else{
        throw(IllegalCharException(someChar));
    }
}
square::operator char(){
   return c;
}
bool square::operator==(char someChar)const{
    if(c==someChar){
       return true;
   }
   return false;
<<<<<<< HEAD
}
=======
}
>>>>>>> ffafbd965be7ae0f3581e221872a09fc2ee5bd40
