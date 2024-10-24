#include <iostream>
#include "class.h"
using namespace std;

Creature::Creature(){
    cout<<"A creature is born\n"<<endl;
    life=L;
}

Creature::~Creature(){
    cout<<"A creature die\n"<<endl;
}   

void Creature::set_name(const char* cname){
    name=new char[strlen(cname)+1];
    strcpy(name,cname);
}

bool Creature::is_a_zombie(){
    if(life==0)
        return true;
    else 
        return false;
}

void Creature::clone(){
    cout<<"A creture cloning himself\n"<<endl;
    Creature* clone_creature=new Creature;   
}

void Creature::bless(){
    if(is_a_zombie()==false){
        cout<<"A creature is blessing\n"<<endl;
        life++;  
    }
    else 
        cout<<"The creature is zombie\n"<<endl;
}

void Creature::beat(){
    if(is_a_zombie()==false){
        cout<<"A creature gets beaten\n"<<endl;
        life--;
    }
    else 
        cout<<"The creature is zombie\n"<<endl;
}

///////////////////////////
bool Good_creature::g_is_a_good(){
    is_a_good=true;
    return true;
}

void Good_creature::good_bless(){
    bless();
    if(life>good_thrsh)
        clone();
}

////////////////////////////
bool Bad_creature::b_is_a_good(){
    is_a_good=false;
    return false;
}

void Bad_creature::bad_bless(){
    bless();
    if(life>bad_thrsh){
        clone();
    }
}

//////////////////////////
Creature_society::Creature_society(){
    cout<<"A society is constructed\n"<<endl;
    //cout<<"\n\n\n"<<N<<"\n\n\n\n"<<endl;
    for(int i=0; i<=N; i++){
        society_s_creatures[i].set_name("name");
        //society_s_creatures[i].life=L;
        //cout<<"ok\n\n"<<endl;
        society_s_creatures[i].is_a_good=rand()%2;
    }
}

Creature_society::~Creature_society(){
    cout<<"A society is deconstructed\n"<<endl;
}

void Creature_society::beat_creature(int i){
    society_s_creatures[i].beat();
}

void Creature_society::bless_creature(int i){
    society_s_creatures[i].bless();
}

void Creature_society::clone_next(int i){
    society_s_creatures[i].clone();
}

void Creature_society::clone_zombies(){

}

int Creature_society::no_of_good(){
    int k=0;
    for(int i=0; i<=N; i++){
        if(society_s_creatures[i].is_a_good==true)
            k++;
    }
    return k;
}

int Creature_society::no_of_zombies(){
    int k=0;
    for(int i=0; i<=N; i++){
        if(society_s_creatures[i].is_a_zombie()==true)
            k++;
    }
    return k;
}