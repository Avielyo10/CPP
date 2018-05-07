#include <iostream>
#include <vector>
using namespace std;

typedef class Member{
    private:
        vector <Member*> allMyFriends;
        vector <Member*> followers;
    public:
        Member(){
            vector <Member*> allMyFriends;
            vector <Member*> followers;
            allUsers.push_back(this);
        }
        ~Member(){
          for(int j=0;j<allUsers.size();j++){
              if(allUsers.at(j)==this){
                  allUsers.erase(allUsers.begin()+j);
              }
          }
          for (int i=0;i<allMyFriends.size();i++){
                unfollow(*allMyFriends.at(i));
          }
          for(int h=0;h<followers.size();h++){
               followers.at(h)->unfollow(*this); 
          }
        }
    static int count();
    static vector <Member*> allUsers;
    int numFollowing();
    int numFollowers();
    void follow(Member& member);
    void unfollow(Member& member);
}Member;

vector<Member*> Member::allUsers;
int Member::count(){  //return all the Users that lives in the system
    return allUsers.size();
}
int Member::numFollowers(){ //return the number of the members who follows me
    return followers.size();
}
int Member::numFollowing(){ //return the number of my friends
    return allMyFriends.size();
}
void Member::follow(Member& member){
    if(this==&member){ //return if follow the same object
        return;
    }
    int count = 0;
    for(int i =0; i< allMyFriends.size();i++){
        if(&member==allMyFriends.at(i)){
            count++;
        }
    }
    if(count==0){
        allMyFriends.push_back(&member);//adding the new member to my friends list
        member.followers.push_back(this);//adding this to the ppl who follows member
    }
   }
void Member::unfollow(Member& member){
     if(this==&member){ //return if unfollow the same object
        return;
    }
    for(int i=0;i<allMyFriends.size();i++){
        if(&member==allMyFriends.at(i)){//delete the member from my friends list
            allMyFriends.erase(allMyFriends.begin()+i);
        }
    }
      for(int h=0;h<member.followers.size();h++){
        if(this==member.followers.at(h)){//delete this from the ppl who follows member
            member.followers.erase(member.followers.begin()+h);
        }
    }
}