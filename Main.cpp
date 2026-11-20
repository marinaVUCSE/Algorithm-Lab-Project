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

        Pharmacy(string n, string a, string p)
        {
            name=n;
            address=a;
            phone=p;
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<Pharmacy>pharmacies;

    pharmacies.push_back(Pharmacy("M.R Son Pharma", "Dairapak Crossroads", "01711972202"));
    pharmacies.push_back(Pharmacy("Makka Pharmacy", "Koroitola, Meherchondi", "01926894354"));
    pharmacies.push_back(Pharmacy("Swapna Medical Hall", "Rajshahi Bus Terminal ", "01716990122"));
    pharmacies.push_back(Pharmacy("Dighi Pharmacy", "Emaduddin Road", "01885739838"));
    pharmacies.push_back(Pharmacy("Lifeline Pharmacy", "Amchottor, Naodapara", "01732623240"));
    pharmacies.push_back(Pharmacy("Apollo Drugs", "Khorkhori Bazar", "01715059999"));

    pharmacies[0].medicines.push_back(Medicine("Napa", 20, 2.00));
    pharmacies[0].medicines.push_back(Medicine("ORS", 15, 6.00));
    pharmacies[0].medicines.push_back(Medicine("Sergel", 10, 7.00));
    pharmacies[0].medicines.push_back(Medicine("Senora", 110, 2.00));
    pharmacies[0].medicines.push_back(Medicine("Antacid", 15, 6.00));
    pharmacies[0].medicines.push_back(Medicine("Cetirizine", 10, 3.00));

    pharmacies[1].medicines.push_back(Medicine("Sergel", 14, 8.00));
    pharmacies[1].medicines.push_back(Medicine("Cetirizine", 15, 3.00));
    pharmacies[1].medicines.push_back(Medicine("Napa", 10, 1.00));
    pharmacies[1].medicines.push_back(Medicine("Joya", 15, 110.00));
    pharmacies[1].medicines.push_back(Medicine("Tufnil", 10, 3.00));
    pharmacies[1].medicines.push_back(Medicine("Feluric", 20, 2.00));
    pharmacies[1].medicines.push_back(Medicine("ORS", 0, 4.00));

    pharmacies[2].medicines.push_back(Medicine("Viset", 11, 4.00));
    pharmacies[2].medicines.push_back(Medicine("Napa", 21, 2.00));
    pharmacies[2].medicines.push_back(Medicine("Esipram", 5, 6.00));
    pharmacies[2].medicines.push_back(Medicine("Joya", 11, 35.00));
    pharmacies[2].medicines.push_back(Medicine("Tufnil", 0, 2.00));
    pharmacies[2].medicines.push_back(Medicine("ORS", 15, 6.00));
    pharmacies[2].medicines.push_back(Medicine("Cetirizine", 10, 3.00));

    pharmacies[3].medicines.push_back(Medicine("Napa", 20, 2.00));
    pharmacies[3].medicines.push_back(Medicine("Antacid", 75, 6.00));
    pharmacies[3].medicines.push_back(Medicine("Cetirizine", 10, 3.00));
    pharmacies[3].medicines.push_back(Medicine("Motigut", 34, 2.00));
    pharmacies[3].medicines.push_back(Medicine("deflux", 35, 6.00));
    pharmacies[3].medicines.push_back(Medicine("Sergel", 20, 3.00));

    pharmacies[4].medicines.push_back(Medicine("Napa", 20, 2.00));
    pharmacies[4].medicines.push_back(Medicine("Senora", 0, 110.00));
    pharmacies[4].medicines.push_back(Medicine("Ceclo", 10, 3.00));
    pharmacies[4].medicines.push_back(Medicine("virux", 13, 2.00));

    pharmacies[5].medicines.push_back(Medicine("Dormicum", 15, 6.00));
    pharmacies[5].medicines.push_back(Medicine("Napa", 20, 2.00));
    pharmacies[5].medicines.push_back(Medicine("Cotrim", 15, 6.00));
    pharmacies[5].medicines.push_back(Medicine("Histacin", 10, 3.00));
    pharmacies[5].medicines.push_back(Medicine("Amocid", 0, 3.00));
    pharmacies[5].medicines.push_back(Medicine("Senora", 15, 110.00));

    
    string searchMedicine;

    cout << "Enter medicine name: ";
    cin >> searchMedicine;






    
    return 0;
}