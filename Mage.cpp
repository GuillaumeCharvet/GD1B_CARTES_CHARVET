#ifndef MAGE_CPP
#define MAGE_CPP

#include "Mage.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h>

    Mage::Mage(std::string nom, int pdv, int mana) : _nom(nom), _pdv(pdv), _mana(mana){}

    int Mage::getHp(){
        return _pdv;
    }

    std::vector<Monstre> Mage::getZoneDeJeu(){
        return _zoneDeJeu;
    }

    void Mage::setHp(int hp){
        _pdv = hp;
    }

    void Mage::resetMana(){
        _mana = 5;
    }

    /*void Mage::invocation_exo2(std::string nom, int attaque, int pdv){
        Monstre momo = Monstre(nom,attaque,pdv);
        _zoneDeJeu.push_back(momo);
    }*/

    void Mage::invocation(int ind){
        _mana = std::max(0,_mana - _main[ind].getMana());
        _zoneDeJeu.push_back(_main[ind]);
        _main.erase(_main.begin() + ind);
    }

    /*void Mage::attaque_monstre_exo2(Monstre * monstre1, Monstre * monstre2){
        monstre1->attaque(monstre2);
    }

    void Mage::attaque_mage_exo2(Monstre * monstre1, Mage * mage1){
        mage1->setHp(mage1->getHp() - monstre1->getAttaque());
    }*/

    void Mage::attaque_monstre(int ind1, int ind2, Mage * mage1){
        _zoneDeJeu[ind1].attaque(&(mage1->getZoneDeJeu()[ind2]));
    }

    void Mage::attaque_mage(int ind1, Mage * mage1){
        //mage1->setHp(mage1->getHp() - monstre1->getAttaque());
    }

    void Mage::affiche_stats(){
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Le mage " << _nom << " possède " << _pdv << " points de vie et " << _mana << " points de mana." << std::endl;
    }

    void Mage::affiche_zone(){
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Le mage " << _nom;
        if (_zoneDeJeu.size() == 0)
        {
            std::cout << " ne contrôle aucun monstre." << std::endl;
        }
        else
        {
            std::cout << " contrôle actuellement les monstre suivants :" << std::endl;
            for (int i = 0; i < _zoneDeJeu.size(); i++)
            {
                std::cout << "  *  ";
                _zoneDeJeu[i].affiche();
            }
        }
    }

    void Mage::affiche_main(){
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Le mage " << _nom;
        if (_main.size() == 0)
        {
            std::cout << " n'a aucune carte en main." << std::endl;
        }
        else
        {
            std::cout << " a les cartes suivantes en main :" << std::endl;
            for (int i = 0; i < _main.size(); i++)
            {
                std::cout << "  *  ";
                _main[i].affiche();
            }
        }
    }

    void Mage::pioche(){
        if (_deck.size() == 0)
        {
            std::cout << "Le deck est vide, vous ne pouvez pas piocher !" << std::endl;
        }
        else
        {
            std::cout << "Vous piochez une carte." << std::endl;
            _main.push_back(_deck[_deck.size()-1]);
            _deck.pop_back();
        }
    }

    void Mage::ajout_au_deck(Monstre momo){
        _deck.push_back(momo);
    }

#endif