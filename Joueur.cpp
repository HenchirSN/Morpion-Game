#include "Joueur.hpp"
#include <iostream>
using namespace std;


ostream& operator<<(ostream& out, Joueur &x) 
{
out << "Je suis le joueur  : " << x.getId()<<" j'ai le score : "<<x.getScore() << endl; return out;
}



Joueur::Joueur (string id_joueur): id_joueur(id_joueur)
{

}

void Joueur::majScore(){
       
        score =  (score + (9.0 / (coup + (coup % 2))));
        
}

string Joueur::getId(){
    return id_joueur;
}

float Joueur::getScore(){
    return score;
}

void Joueur::setScore(float sc)
{
    score=sc;

}


int Joueur::getCoup()
{
    return coup;
}

void Joueur::setCoup(int cp)
{
    coup=cp;
}

void Joueur::incCoup()
{
    coup++;
}


