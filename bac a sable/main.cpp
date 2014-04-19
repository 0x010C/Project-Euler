#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int l = 4, k, i = 3797, j, d = 1;
    bool isPremier, isSpecial = true;
    vector<int> nbPremiers;
    nbPremiers.push_back(2);
    nbPremiers.push_back(3);
    nbPremiers.push_back(5);
    nbPremiers.push_back(7);
    nbPremiers.push_back(11);
    nbPremiers.push_back(13);
    nbPremiers.push_back(17);
    nbPremiers.push_back(19);
    k=i;
    while(l>1)
    {
        l--;
        k = k/pow(10,l);
        cout << k << endl;
        if(isSpecial)
        {
            cout << i << " : " << l << "--> " << k << endl;
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
    cout << "Hello world!" << endl;
    return 0;
}
