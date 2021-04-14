#include "Monstre.cpp"
#include <iostream>
#include <string>


int main(){

    Monstre monstre1 = Monstre("monstre1", 4, 6);
    Monstre monstre2 = Monstre("monstre2", 1, 10);

    monstre1.affiche();

    monstre1.attaque(&monstre2);

    monstre1.affiche();
    monstre2.affiche();
    
    return 0;
}