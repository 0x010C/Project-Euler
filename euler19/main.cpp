/*
Projet Euler 19
Le but est de déterminer le nombre de fois que le premier du mois est un dimanche
entre le 1er janvier 1901 et le 31 décembre 2000
Réponse : 171
Temps d'execution : 0.002S
*/
#include <iostream>

using namespace std;

int main()
{
    int codeSemaine, jour = 1, mois, an, nbDimanche = 0;
    for(an=1901;an<=2000;an++)
    {
        for(mois=1;mois<=12;mois++)
        {
            if(mois<3)
                codeSemaine = (((23*mois)/9) + jour + 4 + an + ((an-1)/4) - ((an-1)/100) + ((an-1)/400)) % 7;
            else
                codeSemaine = (((23*mois)/9) + jour + 4 + an + (an/4) - (an/100) + (an/400) - 2) % 7;

            if(codeSemaine == 0)
                nbDimanche++;
        }
    }
    cout << "Nombre de dimanches : " <<  nbDimanche << endl << endl;
    return 0;
}
