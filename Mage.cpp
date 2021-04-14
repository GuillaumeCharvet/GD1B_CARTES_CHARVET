#ifndef MAGE_CPP
#define MAGE_CPP

#include "Mage.h"
#include <iostream>
#include <algorithm>

    Mage::Mage(std::string nom, int pdv) : _nom(nom), _pdv(pdv){}

    int Mage::getHp(){
        return _pdv;
    }

    void Mage::setHp(int hp){
        _pdv = hp;
    }

    void Mage::invocation(std::string nom, int attaque, int pdv){
        Monstre momo = Monstre(nom,attaque,pdv);
        _zoneDeJeu.push_back(momo);
    }

    void Mage::attaque_monstre(Monstre * monstre1, Monstre * monstre2){
        monstre1->attaque(monstre2);
    }

    void Mage::attaque_mage(Monstre * monstre1, Mage * mage1){
        mage1->setHp(mage1->getHp() - monstre1->getAttaque());
    }

    void Mage::affiche(){
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Le mage " << _nom << " possède " << _pdv << " points de vie ";
        if (_zoneDeJeu.size() == 0)
        {
            std::cout << "et ne contrôle aucun monstre." << std::endl;
        }
        else
        {
            std::cout << "et contrôle actuellement les monstre suivants :" << std::endl;
            for (int i = 0; i < _zoneDeJeu.size(); i++)
            {
            _zoneDeJeu[i].affiche();
            }
        }
    }

#endif