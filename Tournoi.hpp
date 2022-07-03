#include<string>
#include<iostream>
#include<vector>
#include "Partie.hpp"




using namespace std;



class Tournoi
{
private:
    bool session=true;
    vector <Joueur> liste_inscription; 
    

public:
    Tournoi();
    void inscription(Joueur j);
    void vide_participants();
    void lance_tournoi();
    
};



ostream& operator<<(ostream& out, Tournoi &x);



