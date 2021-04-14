#ifndef MAGE_H
#define MAGE_H

#include "Monstre.h"
#include <string>
#include <vector>

class Mage{

    private:

        std::string _nom;
        int _pdv;
        std::vector<Monstre> _zoneDeJeu;
        
    public:

        Mage(std::string nom, int pdv);

        int getHp();

        void setHp(int hp);

        void invocation(std::string nom, int attaque, int pdv);

        void attaque_monstre(Monstre * monstre1, Monstre * monstre2);

        void attaque_mage(Monstre * monstre1, Mage * mage1);

        void affiche();

};

#endif