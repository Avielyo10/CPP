#include <iostream>
using namespace std;

class CircularInt{
    public:
    int minValue, maxValue, current ,size;
    CircularInt(int min,int max){
      if(min>max){
        minValue = max;
        maxValue = min;
        current = max;
      }
      else{
        minValue = min;
        maxValue = max;
        current = min;
      }
        size = maxValue-minValue+1;
    }
    friend ostream& operator<< (ostream& out, CircularInt c);
    CircularInt& operator+=(int n);
    CircularInt& operator-=(int n);
    CircularInt& operator++(int);
    CircularInt& operator--(int);
    int operator-();
    int operator+(CircularInt c);
    CircularInt& operator*=(int n);
    CircularInt& operator/=(int n);
    int operator/(int n);
};
ostream& operator<< (ostream& out, CircularInt c) {
    return out << c.current;
}
CircularInt& CircularInt::operator+=(int n){
  current = ((current+n)%size);
  if(current == 0){
    current = maxValue;
  }
  return *this;
}
CircularInt& CircularInt::operator-=(int n){
  return *this+=-n;
}
CircularInt& CircularInt::operator++(int){
  return *this+=1;
}
CircularInt& CircularInt::operator--(int){
  return *this-=1;
}
int CircularInt::operator-(){
  int result = maxValue - current;
  if (result==0){
    result = maxValue;
  }
  return result;
}
CircularInt operator-(int a, CircularInt c){
  int result = a - c.current;
  result = ((result+c.maxValue)%c.size);
  if(result == 0){
    result = c.maxValue;
  }
  c.current = result;
  return c;
}
CircularInt operator+(int a, CircularInt c){
  int result = a + c.current;
  result = ((result+c.maxValue)%c.size);
  if(result == 0){
    result = c.maxValue;
  }
  c.current = result;
  return c;
}
int CircularInt::operator+(CircularInt c){
  int result = ((current + c.current)%size);
  if(result == 0){
    result = maxValue;
  }
  return result;
}
CircularInt& CircularInt::operator*=(int n){
  current = ((current*n)%size);
  if(current == 0){
    current = maxValue;
  }
  return *this;
}
CircularInt& CircularInt::operator/=(int n){
  current = ((current/n)%size);
  if(current == 0){
    current = maxValue;
  }
  return *this;
}
int CircularInt::operator/(int n){
  float a = float(current)/n; // option one
  float b = float(maxValue+current)/n; // option two
  int c = a*10;
  int d = b*10;
  try{
    if(c%10 == 0){
      return a;
    }
    else if(d%10 == 0){
      return b;
    } 
    else{
      string message = "There is no number x in {"+to_string(minValue)+","+to_string(maxValue)+"} such that x*"+to_string(n)+"="+to_string(current);
      throw message;
    }
  }catch(const string& message){
    throw;
  }
}



