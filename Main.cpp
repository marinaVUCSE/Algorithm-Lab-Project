#include<bits/stdc++.h>
using namespace std;

const char nl = '\n';
using ll = long long int;

class Medicine
{
    public:
        string name;
        int quantity;
        double price;

        Medicine(string n,int q,double p)
        {
            name=n;
            quantity=q;
            price=p;
        }
};

class Pharmacy
{
    public:
        string name,address,phone;
        vector<Medicine>medicines;

        Pharmacy(string n, string a, string p, vector<Medicine>m)
        {
            name=n;
            address=a;
            phone=p;
            medicines=m;
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<Pharmacy>pharmacies;


    return 0;
}