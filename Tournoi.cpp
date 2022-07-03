#include<iostream>
#include "Tournoi.hpp"







Tournoi::Tournoi(){
    
}


ostream& operator<<(ostream& out, Tournoi &x) 
{
    out << "ceci est un tournoi : " << endl; return out;
}


void Tournoi::inscription(Joueur j)
{
    if (session==true)
    {
    cout<<"nombre des joueurs avant l'ajout de "<<j.getId() << " est : "<<liste_inscription.size()<<endl;
    liste_inscription.push_back(j);
    cout<<"inscription pour le joueur : "<<j.getId() <<" ### son score actuellement est : "<<j.getScore()<<endl;
    cout<<"nombre des joueurs actuellement inscrit est : "<<liste_inscription.size()<<endl<<endl<<endl;
    }
    else cout<<"La session d'inscription pour ce tournoi est terminée !! "<<endl;
    
}


void Tournoi::lance_tournoi()
{
    session=false; //pour fermer la session une fois le tournoi commence ( ne plus accepter les inscriptions)
    cout<<" Le tournoi est lancé  ! Que le meilleur gagne !! "<<endl;
    int nbj=liste_inscription.size(); 
    
    int i=0;
    int k=0;
    cout<<"les nombre de participant dans ce tournoi est est :" <<nbj <<endl;

    for (i=0;i<nbj-1;i++)
    {   
        k=i+1;
        while(k<nbj)    
            {
            Partie p1{1}; //Création de la parie 
            p1.game(liste_inscription[i],liste_inscription[k]); // lancer une partie entre deux participants
            
            k++;
            }
        
    }
    cout<<"fin de tournoi !!!"<<endl;
  
    
    cout<<"scores totaux de participants :  "<<endl;

    for (int i=0;i<liste_inscription.size();i++)

    {
        cout<<"scores du joueur "<<liste_inscription[i].getId()<<" : tournoi "<<liste_inscription[i].getScore()<<", total "<<liste_inscription[i].getScore()<<endl;
        

    }
    
    
    
    


     
}

void Tournoi::vide_participants()
{
    liste_inscription.clear();
    cout<<"le tournoi est terminé tous les participants sont vidés "<<endl;
    session=true;
    cout<<liste_inscription.size(); //pour vérifier que lous les joueurs sont vidés
}