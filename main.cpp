#include <iostream>
#include <ctime>
#include "class.h"
using namespace std;

int main(int argc,char* argv[]){
    srand((unsigned) time(0));

    Creature_society c_s;

    c_s.N=std::atoi(argv[1]);
    c_s.M=std::atoi(argv[2]);
    c_s.L=std::atoi(argv[3]);
    c_s.good_thrsh=std::atoi(argv[4]);
    c_s.bad_thrsh=std::atoi(argv[5]);

    for(int i=0; i<=c_s.N; i++){
        c_s.society_s_creatures[i].set_name("name");
        c_s.society_s_creatures[i].life=c_s.L;
        c_s.society_s_creatures[i].is_a_good=rand()%2;
    }

    for(int i=0; i<=c_s.M; i++){
        //choose bless or beat
        //k=rand απο τα N πλασματα
        int k=rand()%c_s.N+1;
        int j=rand()%2;
        if(j==0)
            c_s.beat_creature(k);
        else
            c_s.bless_creature(k);
    }

    for(int i=0; i<=c_s.N; i++){
        if(c_s.no_of_zombies()==0){
            cout<<"Good Dominates in the World!\n"<<endl;
            break;
        }
        else if(c_s.no_of_zombies()==c_s.N){
            cout<<"This is a dead society\n"<<endl;
            break;
        }
        else{
            cout<<"Try again to improve the world\n"<<endl;
            break;
        }
    }
    return 0;
}