#include<string>
#include<iostream>
#include"Joueur.hpp"
#include<vector>


using namespace std;

class Partie
{
private:
    int id_partie;
    int player=1; 
    vector < vector<int> > grille; 
    vector <int> ligne1;
    vector <int> ligne2;
    vector <int> ligne3;
    
public:

    Partie(int id_partie );
    int getId();
    void game(Joueur &j1, Joueur &j2);
    void makeGrille();
    void afficherGrille();
    void changePlayer();
    int win();
    void input(Joueur &j1, Joueur &j2 );


    
};

ostream& operator<<(ostream& out, Partie &x);



