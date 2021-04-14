#ifndef MAGE_H
#define MAGE_H

#include "Monstre.h"
#include <string>
#include <vector>

class Mage{

    private:

        std::string _nom;
        int _pdv;
        int _mana;
        std::vector<Monstre> _zoneDeJeu;
        std::vector<Monstre> _deck;
        std::vector<Monstre> _main;
        
    public:

        Mage(std::string nom, int pdv, int mana);

        int getHp();

        std::vector<Monstre> getZoneDeJeu();

        void setHp(int hp);

        void resetMana();

        //void invocation_exo2(std::string nom, int attaque, int pdv);

        // Avant d'invoquer un monstre, la main du joueur est affichée et le joueur rentre le numéro du monstre qu'il souhaite invoqué
        // La vérification d'avoir suffisamment de mana pour jouer cette carte se fera dans le main
        void invocation(int ind);

        //void attaque_monstre_exo2(Monstre * monstre1, Monstre * monstre2);

        //void attaque_mage_exo2(Monstre * monstre1, Mage * mage1);

        void attaque_monstre(int ind1, int ind2, Mage * mage1);

        void attaque_mage(int ind1, Mage * mage1);

        void affiche_stats();

        void affiche_zone();

        void affiche_main();

        void pioche();

        void ajout_au_deck(Monstre momo);

};

#endif