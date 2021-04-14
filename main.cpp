#include "Monstre.cpp"
#include "Mage.cpp"
#include <iostream>
#include <string>


int main(){

    Monstre monstre1 = Monstre("Médor", 4, 6);
    Monstre monstre2 = Monstre("Poupi", 1, 10);

    monstre1.affiche();

    monstre1.attaque(&monstre2);

    monstre1.affiche();
    monstre2.affiche();

    Mage mage1 = Mage("Duduche",20);    
    Mage mage2 = Mage("Paul",20);

    mage1.affiche();

    mage1.invocation("Médor", 4, 6);
    mage1.affiche();
    mage1.invocation("Poupi", 1, 10);
    mage1.affiche();

    mage1.attaque_monstre(&monstre1,&monstre2);
    
    monstre1.affiche();
    monstre2.affiche();

    mage1.attaque_mage(&monstre1, &mage2);
    
    mage2.affiche();
    
    return 0;
}