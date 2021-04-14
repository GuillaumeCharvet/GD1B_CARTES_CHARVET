#ifndef MONSTRE_CPP
#define MONSTRE_CPP

#include "Monstre.h"
#include <iostream>
#include <algorithm>

    Monstre::Monstre(std::string nom, int attaque, int pdv) : _nom(nom), _attaque(attaque), _pdv(pdv), _dispo(true), _vivant(true){}

    void Monstre::affiche(){
        std::cout << "***********************" << std::endl;
        std::cout << "Le monstre " << _nom << " possède " << _pdv << " points de vie, a une attaque de " << _attaque;
        if (_dispo){std::cout << " et est prêt à attaquer !" << std::endl;}
        else {std::cout << " et doit se reposer à ce tour." << std::endl;}        
    }

    int Monstre::getAttaque(){
        return _attaque;
    }

    int Monstre::getHp(){
        return _pdv;
    }

    void Monstre::setHp(int hp){
        _pdv = hp;
    }

    void Monstre::setDispo(bool dispo){
        _dispo = dispo;
    }

    void Monstre::setVivant(bool vivant){
        _vivant = vivant;
    }

    void Monstre::attaque(Monstre * momo){
        _pdv = std::max(0,_pdv - momo->getAttaque());
        momo->setHp(std::max(0,momo->getHp() - _attaque));
        _dispo = false;
        momo->setDispo(false);
        if (_pdv == 0){_vivant = false;}
        if (momo->getHp() == 0){momo->setVivant(false);}
    }

#endif