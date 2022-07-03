#include<iostream>
#include"Partie.hpp"



ostream& operator<<(ostream& out, Partie &x) 
{

out << "ceci est une partie   " << endl; return out;
}


Partie::Partie(int id_partie ): id_partie(id_partie){
   
}

void Partie::afficherGrille()

{
   
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout<< grille[i][j]<<" ";

        }
        cout<<endl;
    }

} 

void Partie::makeGrille()
{
    ligne1.push_back(0);      
    ligne1.push_back(0);
    ligne1.push_back(0);
    grille.push_back(ligne1);

    ligne2.push_back(0);
    ligne2.push_back(0);
    ligne2.push_back(0);
    grille.push_back(ligne2);

    ligne3.push_back(0);
    ligne3.push_back(0);
    ligne3.push_back(0);
    grille.push_back(ligne3);
    

}

void Partie::input(Joueur &j1, Joueur &j2)
{
        int a;
        if(player==1)  
        {
        cout<<j1.getId()<<", Entrez une case i(ligne)  j(colonne) exemple 00 ou 11 ( entrer que des numéros !! ): ";
        j1.incCoup();
        
        
        }

        else if (player ==2)
        {
        cout<<j2.getId()<<", Entrez une case i(ligne)  j(colonne) exemple 00 ou 11 ( entrer que des numéros !! ) : ";
        j2.incCoup();
      
        
        
        }


        cin>>a; 

    
        if(a==00)
            grille[0][0]=player;
        else if (a==01)
            grille[0][1]=player;
        else if (a==02)
            grille[0][2]=player;
        else if (a==10)
            grille[1][0]=player;
        else if (a==11)
            grille[1][1]=player;
        else if (a==12)
            grille[1][2]=player;
        else if (a==20)
            grille[2][0]=player;
        else if (a==21)
            grille[2][1]=player;
        else if (a==22)
            grille[2][2]=player;
        else 
            cout<<"Choix invalide !!"<<endl;
         
        

    

}


int Partie::win()
{   int testnull=0; //variable utile pour le cas de partie nulle
    

    //Joueur 1
    if (grille[0][0]== 1 && grille[0][1]== 1 && grille[0][2]== 1)
        return 1;
    if (grille[1][0]== 1 && grille[1][1]== 1 && grille[1][2]== 1)
        return 1;
    if (grille[2][0]== 1 && grille[2][1]== 1 && grille[2][2]== 1)
        return 1;


    if (grille[0][0]== 1 && grille[1][0]== 1 && grille[2][0]== 1)
        return 1;
    if (grille[0][1]== 1 && grille[1][1]== 1 && grille[2][1]== 1)
        return 1;
    if (grille[0][2]== 1 && grille[1][2]== 1 && grille[2][2]== 1)
        return 1;
    
    if (grille[0][0]== 1 && grille[1][1]== 1 && grille[2][2]== 1)
        return 1;
    if (grille[0][2]== 1 && grille[1][1]== 1 && grille[2][0]== 1)
        return 1;




    //Joueur 2
    if (grille[0][0]== 2 && grille[0][1]== 2 && grille[0][2]== 2)
        return 2;
    if (grille[1][0]== 2 && grille[1][1]== 2 && grille[1][2]== 2)
        return 2;
    if (grille[2][0]== 2 && grille[2][1]== 2 && grille[2][2]== 2)
        return 2;


    if (grille[0][0]== 2 && grille[1][0]== 2 && grille[2][0]== 2)
        return 2;
    if (grille[0][1]== 2 && grille[1][1]== 2 && grille[2][1]== 2)
        return 2;
    if (grille[0][2]== 2 && grille[1][2]== 2 && grille[2][2]== 2)
        return 2;
    
    if (grille[0][0]== 2 && grille[1][1]== 2 && grille[2][2]== 2)
        return 2;
    if (grille[0][2]== 2 && grille[1][1]== 2 && grille[2][0]== 2)
        return 2;
    
    
    for (int i=0;i<3;i++) //verification partie nulle 
    {
        for (int j=0;j<3;j++)
            {
                if(grille [i][j]!=0 )
                    testnull++; 
            }
    }

    if (testnull==9)    //verification partie nulle 
    return 3;

    return 4;      
      
}




void Partie::changePlayer()
    {
        if(player == 1)
            player=2;
        else
            player=1;
    }



int Partie::getId()
{
    return id_partie; 
}


void Partie::game(Joueur &j1, Joueur &j2 )
{

    cout<<"le partie entre  "<<j1.getId()<<"  et  "<<j2.getId()<< " commence maintenant "<<endl;
    makeGrille(); //initialiser la grille 
    afficherGrille(); //affichage de la grille avec son état initial 

    while(1)
    {    
        input(j1,j2); 
        afficherGrille();
        if (win()== 1)
            {
                cout<<"--> Bravo Joueur "<<j1.getId()<<"!!!"<<endl;
                cout<<"son nb cout est : "<< j1.getCoup() <<endl;
                
                j1.majScore(); //modification du score 
                
                cout<<"score du joueur "<<j1.getId()<<" : tournoi "<<j1.getScore()<<", total "<<j1.getScore()<<endl;
                cout<<"score du joueur "<<j2.getId()<<" : tournoi "<<j2.getScore()<<", total "<<j2.getScore()<<endl;
                j1.setCoup(0);  
                j2.setCoup(0);
                break;
            }
        if (win()== 2)

            {
                
                cout<<"--> Bravo Joueur "<<j2.getId()<<"!!!"<<endl;
                cout<<"son nb cout est : "<< j2.getCoup() <<endl;
                
                j2.majScore(); 
                
                cout<<"score du joueur "<<j2.getId()<<" : tournoi "<<j2.getScore()<<", total "<<j2.getScore()<<endl;
                cout<<"score du joueur "<<j1.getId()<<" : tournoi "<<j1.getScore()<<", total "<<j1.getScore()<<endl;
                j2.setCoup(0);
                j1.setCoup(0);
                break;

            }

        if(win()==3)
             {

                cout<<"--> Partie nulle "<<endl;
                cout<<"score du joueur "<<j1.getId()<<" : tournoi "<<j1.getScore()<<", total "<<j1.getScore()<<endl;
                cout<<"score du joueur "<<j2.getId()<<" : tournoi "<<j2.getScore()<<", total "<<j2.getScore()<<endl;
                j1.setCoup(0);
                j2.setCoup(0); 
                break;

            }



        
        

        changePlayer();

    }
    
}