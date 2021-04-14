#include "Monstre.cpp"
#include "Mage.cpp"
#include <iostream>
#include <string>


int main(){

    Monstre monstre1 = Monstre("Médor", 4, 6, 4);
    Monstre monstre2 = Monstre("Poupi", 2, 10, 5);
    Monstre monstre3 = Monstre("Loulou", 5, 5, 4);
    Monstre monstre4 = Monstre("Grogro", 6, 3, 3);
    Monstre monstre5 = Monstre("Titi", 1, 2, 1);

    /*monstre1.affiche();

    monstre1.attaque(&monstre2);

    monstre1.affiche();
    monstre2.affiche();*/

    Mage mage1 = Mage("Duduche",20,5);    
    Mage mage2 = Mage("Paul",20,5);

    /*mage1.affiche_stats();

    mage1.invocation_exo2("Médor", 4, 6);
    mage1.affiche_stats();
    mage1.invocation_exo2("Poupi", 1, 10);
    mage1.affiche_stats();

    mage1.attaque_monstre(&monstre1,&monstre2);
    
    monstre1.affiche();
    monstre2.affiche();

    mage1.attaque_mage(&monstre1, &mage2);
    
    mage2.affiche_stats();*/

    mage1.ajout_au_deck(monstre1);
    mage1.ajout_au_deck(monstre2);
    mage2.ajout_au_deck(monstre3);
    mage2.ajout_au_deck(monstre4);
    mage2.ajout_au_deck(monstre5);

    /*
    mage1.pioche();
    mage2.pioche();
    mage2.pioche();
    
    mage1.affiche_stats();
    mage1.affiche_main();
    mage1.affiche_zone();
    mage2.affiche_stats();
    mage2.affiche_main();
    mage2.affiche_zone();

    mage2.invocation(1);

    mage2.affiche_main();
    mage2.affiche_zone();
    */

    bool partie_finie = false;
    int tour = 0;
    int choix1;
    int choix2;

    while (!partie_finie)
    {
        if (tour%2 == 0)
        {
            mage1.resetMana();
            mage1.affiche_stats();
            mage1.pioche();
            mage1.affiche_main();
            mage1.affiche_zone();
            mage2.affiche_zone();
            choix1 = -2;
            while (choix1 != -1)
            {
                mage1.affiche_main();
                std::cout << "Voulez-vous jouer une carte ? Tapez l'indice de la carte pour la jouer ou -1 pour passer votre tour." << std::endl;
                std::cin >> choix1;
                if (choix1 != -1)
                {
                    mage1.invocation(choix1);
                }
            }
            choix1 = -2;
            while (choix1 != -1)
            {
                mage1.affiche_zone();
                std::cout << "Voulez-vous attaquer un monstre du mage adverse ? Tapez l'indice du monstre que vous voulez envoyer" << std::endl;
                std::cout << " ou tapez -1 pour passer votre tour." << std::endl;
                std::cin >> choix1;
                if (choix1 != -1)
                {
                    choix2 = -2;
                    std::cout << "Tapez l'indice du monstre que vous voulez attaquer, -2 pour attaquer directement le mage ou tapez -1 pour changer d'attaquant." << std::endl;
                    std::cin >> choix2;
                    if (choix2 != -1)
                    {
                        if (choix2 != -2)
                        {
                            mage1.attaque_monstre(choix1,choix2,&mage2);
                        }
                        else
                        {
                            mage1.attaque_mage(choix1,&mage2);
                        }
                    }                    
                }
            }
        }
        else
        {
            mage2.resetMana();
            mage2.affiche_stats();
            mage2.pioche();
            mage2.affiche_main();
            mage2.affiche_zone();
            mage1.affiche_zone();
            choix1 = -2;
            while (choix1 != -1)
            {
                mage2.affiche_main();
                std::cout << "Voulez-vous jouer une carte ? Tapez l'indice de la carte pour la jouer ou -1 pour passer votre tour." << std::endl;
                std::cin >> choix1;
                if (choix1 != -1)
                {
                    mage2.invocation(choix1);
                }
            }
            choix1 = -2;
            while (choix1 != -1)
            {
                mage2.affiche_zone();
                std::cout << "Voulez-vous attaquer un monstre du mage adverse ? Tapez l'indice du monstre que vous voulez envoyer" << std::endl;
                std::cout << " ou tapez -1 pour passer votre tour." << std::endl;
                std::cin >> choix1;
                if (choix1 != -1)
                {
                    choix2 = -2;
                    std::cout << "Tapez l'indice du monstre que vous voulez attaquer, -2 pour attaquer directement le mage ou tapez -1 pour changer d'attaquant." << std::endl;
                    std::cin >> choix2;
                    if (choix2 != -1)
                    {
                        if (choix2 != -2)
                        {
                            mage2.attaque_monstre(choix1,choix2,&mage1);
                        }
                        else
                        {
                            mage2.attaque_mage(choix1,&mage2);
                        }
                    }                    
                }
            }
        }
        tour += 1;
    }
    
    return 0;
}
