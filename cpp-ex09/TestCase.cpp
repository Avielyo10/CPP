#include "TestCase.hpp"

TestCase::TestCase(string name, ostream &out){
        testName = name;
        op = &out;
}

TestCase TestCase::print(){
       string d,s = testName+": "+to_string(failed)+" failed, "+to_string(passed)+" passed, "+to_string(failed+passed)+" total.#";
       int counter = s.size()+1;
       while(counter!=0){
               d+="#";
               counter--;
       }
       *op <<"\n"+d;
       *op <<"\n#"+s<<endl; 
       *op <<d+"\n=================================================================================================\n\n";
       return *this;
}