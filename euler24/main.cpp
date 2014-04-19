/*
Projet euler 24 :
Le but est de déterminer le 1 000 000ème élément de la suite ordonnée des nombres composés de 0,1,2,3,4,5,6,7,8,9 (présent une seul fois)
Réponse : 2783915460
Temps d'execution : 0.140s
*/
#include <iostream>

using namespace std;

int main()
{
    int nb0, nb1, nb2, nb3, nb4, nb5, nb6, nb7, nb8, nb9, i = 0;
    bool stop = false;
    for(nb0 = 0 ; nb0 <= 9; nb0++)
    {
        for(nb1 = 0 ; nb1 <= 9; nb1++)
        {
            if(nb1 == nb0)
                continue;
            for(nb2 = 0 ; nb2 <= 9; nb2++)
            {
                if(nb2 == nb0 or nb2 == nb1)
                    continue;
                for(nb3 = 0 ; nb3 <= 9; nb3++)
                {
                    if(nb3 == nb0 or nb3 == nb1 or nb3 == nb2)
                        continue;
                    for(nb4 = 0 ; nb4 <= 9; nb4++)
                    {
                        if(nb4 == nb0 or nb4 == nb1 or nb4 == nb2 or nb4 == nb3)
                            continue;
                        for(nb5 = 0 ; nb5 <= 9; nb5++)
                        {
                            if(nb5 == nb0 or nb5 == nb1 or nb5 == nb2 or nb5 == nb3 or nb5 == nb4)
                                continue;
                            for(nb6 = 0 ; nb6<= 9; nb6++)
                            {
                                if(nb6 == nb0 or nb6 == nb1 or nb6 == nb2 or nb6 == nb3 or nb6 == nb4 or nb6 == nb5)
                                    continue;
                                for(nb7 = 0 ; nb7<= 9; nb7++)
                                {
                                    if(nb7 == nb0 or nb7 == nb1 or nb7 == nb2 or nb7 == nb3 or nb7 == nb4 or nb7 == nb5 or nb7 == nb6)
                                        continue;
                                    for(nb8 = 0 ; nb8<= 9; nb8++)
                                    {
                                        if(nb8 == nb0 or nb8 == nb1 or nb8 == nb2 or nb8 == nb3 or nb8 == nb4 or nb8 == nb5 or nb8 == nb6 or nb8 == nb7)
                                            continue;
                                        for(nb9 = 0 ; nb9<= 9; nb9++)
                                        {
                                            if(nb9 == nb0 or nb9 == nb1 or nb9 == nb2 or nb9 == nb3 or nb9 == nb4 or nb9 == nb5 or nb9 == nb6 or nb9 == nb7 or nb9 == nb8)
                                                continue;
                                            i++;
                                            if(i == 1000000)
                                            {
                                                stop = true;
                                                break;
                                            }
                                        }
                                        if(stop)
                                            break;
                                    }
                                    if(stop)
                                        break;
                                }
                                        if(stop)
                                            break;
                            }
                                        if(stop)
                                            break;
                        }
                                        if(stop)
                                            break;
                    }
                                        if(stop)
                                            break;
                }
                                        if(stop)
                                            break;
            }
                                        if(stop)
                                            break;
        }
                                        if(stop)
                                            break;
    }
    cout << "Le resultat est : " << nb0 << nb1 << nb2 << nb3 << nb4 << nb5 << nb6 << nb7 << nb8 << nb9 << endl;
    return 0;
}
