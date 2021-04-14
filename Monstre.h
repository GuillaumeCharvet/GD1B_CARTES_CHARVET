#ifndef MONSTRE_H
#define MONSTRE_H

#include <string>

class Monstre{

    private:

        std::string _nom;
        int _attaque;
        int _pdv;
        bool _dispo;
        bool _vivant;
        
    public:

        Monstre(std::string nom, int attaque, int pdv);

        void affiche();

        int getAttaque();

        int getHp();

        void setHp(int hp);

        void setDispo(bool dispo);

        void setVivant(bool vivant);

        void attaque(Monstre * momo);

};

#endif