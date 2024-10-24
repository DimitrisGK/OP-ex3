#include <iostream>
#include <cstring>
using namespace std;

class Creature{
private:
    char* name;
public:
    Creature();
    ~Creature();

    int life;
    void set_name(const char*);

    bool is_a_zombie();
    bool is_a_good;

    void clone();
    void bless();
    void beat();

    int M, L, good_thrsh, bad_thrsh;
    int N;
};

class Good_creature: public Creature{
private:

public:
    void good_bless();
    bool g_is_a_good();
};

class Bad_creature: public Creature{
private:
    
public:
    void bad_bless();
    bool b_is_a_good();
};

class Creature_society: public Creature{
private:
    int num_space;
    int* p;
public:
    Creature_society();
    ~Creature_society();

    void beat_creature(int);
    void bless_creature(int);

    void clone_next(int);
    void clone_zombies();

    int no_of_good();
    int no_of_zombies();

    //int N;

    //Creature* society_s_creatures=new Creature;
    Creature society_s_creatures[50];
    //society_s_creatures=new int[N];
    //non-static array
};