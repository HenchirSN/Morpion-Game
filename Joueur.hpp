#include<string>
#include<iostream>
using namespace std;


class Joueur
{
private:
    float score=0.0;
    string id_joueur;
    int coup=0;
    
public:
    Joueur(string id_joueur); //ctor du joueur 
    string getId(); 
    float getScore();
    void setScore(float sc);
    void majScore();
    int getCoup();
    void setCoup(int cp);
    void incCoup();

    
    

};

ostream& operator<<(ostream& out, Joueur &x);