#include "Tournoi.hpp"





using namespace std;

int main(){

  cout<<"************     Hello and welcome to the best game ever made     ************"<<endl<<endl<<endl;
  
  
  Joueur j1{"cerise"}, j2{"pomme"}, j3{"fraise"};
  
  

  Tournoi tour;
 

  
  tour.inscription(j1);
  tour.inscription(j2);
  tour.inscription(j3);
 
  
  tour.lance_tournoi();





  //tour.vide_participants();

  //cout << endl << "Nouveau Tournoi" << endl;

  //Joueur j4{"mangue"};
  //Joueur j5{"acai"};
  //tour.inscription(j1);
  //tour.inscription(j3);
  //tour.inscription(j4);
  //tour.inscription(j5);
  //tour.lance_tournoi();
  
  return 0;
}
