/*

*/

#include <iostream>
#include <vector>
#include <math.h>
/*pour accélérer, pas prendre en compte les pairs et s'arréter a racine de i*/
using namespace std;

int main()
{
    bool stop = false, isPremier = false, isSpecial = false;
    int unsigned i, j, k, l, m;
    vector<int> nbPremiers;
    vector<int> nbSpeciaux;
    nbPremiers.push_back(2);
    for(i=3;!stop;i++)
    {
        isPremier = true;
        for(j=0; j < nbPremiers.size(); j++)
        {
            if(i%nbPremiers[j] == 0)
            {
                isPremier = false;
                break;
            }
        }
        if(isPremier)
        {
            nbPremiers.push_back(i);
            /*Debut test*/
            isSpecial = true;
            k = i;
            for(l=1;k != 0;l++)
            {
                isPremier = false;
                for(j=0; j < nbPremiers.size(); j++)
                {
                    if(k == nbPremiers[j])
                    {
                        isPremier = true;
                        break;
                    }
                }
                if(!isPremier)
                {
                    isSpecial = false;
                    break;
                }
                k = k/10;
            }
            k=i;
            l--;
            if(isSpecial)
                cout << i << " : " << l << endl;
            while(l>1)
            {
                l--;
                k = k - ((k/pow(10,l))*pow(10,l));
                if(isSpecial)
                {
                    cout << i << " --> " << k << endl;
                }
                isPremier = false;
                for(j=0; j < nbPremiers.size(); j++)
                {
                    if(k == nbPremiers[j])
                    {
                        isPremier = true;
                        break;
                    }
                }
                if(!isPremier)
                {
                    isSpecial = false;
                    break;
                }
            }
            /*Fin test*/
            if(isSpecial)
            {
                if(i > 10)
                    nbSpeciaux.push_back(i);
                if(nbSpeciaux.size() >= 11)
                    stop = true;
            }
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
