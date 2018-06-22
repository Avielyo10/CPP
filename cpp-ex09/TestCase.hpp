#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class TestCase{
    public:
    string testName;
    ostream* op;
    int passed = 0, failed = 0;
    TestCase(string name, ostream &out);

    template <class T> 
    TestCase& check_equal(T a,T b){
        stringstream ssA, ssB;
        ssA<<a;ssB<<b;
        if(a==b){++passed;}
        else{
            ++failed;
            *op <<testName<<": "<<"Failure in test #"<<failed+passed<<": "<<ssA.str()<<" should equal "<<ssB.str()<<endl;
        }
        return *this;
    }

    template <class T> 
    TestCase& check_different(T a,T b){
        stringstream ssA, ssB;
        ssA<<a;ssB<<b;
        if(a!=b){++passed;}
        else{
            ++failed;
            *op <<testName<<": "<<"Failure in test #"<<failed+passed<<": "<<ssA.str()<<" is not different from "<<ssB.str()<<endl;
        }
        return *this;
    }

    template <typename T,typename F,typename C>  
    TestCase& check_function(const F& function, const T& toOperateOn,const C& result){
        if(function(toOperateOn)==result){++passed;}
        else{
            ++failed;
            *op <<testName<<": "<<"Failure in test #"<<failed+passed<<": Function should return "<<result<<" but returned "<<function(toOperateOn)<<"!"<<endl;
        }
        return *this;  
    }

    template <class T> 
    TestCase& check_output(T a,string s){
        stringstream ss;
        ss<<a;
        if(ss.str()==s){++passed;}
        else{
            ++failed;
            *op <<testName<<": "<<"Failure in test #"<<failed+passed<<": string value should be "<<s<<" but is "<<ss.str()<<endl;
        }
        return *this;
    }
    TestCase print();
};
