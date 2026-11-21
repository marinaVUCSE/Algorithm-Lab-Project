#include<bits/stdc++.h>
using namespace std;

class Pharmacy
{
    public:
        string name, address, phone;
        vector<string> medicines;

        Pharmacy(string n, string a, string p)
        {
            name = n;
            address = a;
            phone = p;
        }
};

string lowerCase(string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
    }

    return s;
}

int main()
{
    vector<Pharmacy> pharmacies;

    pharmacies.push_back(Pharmacy("M.R Son Pharma", "Dairapak Crossroads", "01711972202"));
    pharmacies.push_back(Pharmacy("Makka Pharmacy", "Koroitola, Meherchondi", "01926894354"));
    pharmacies.push_back(Pharmacy("Swapna Medical Hall", "Rajshahi Bus Terminal", "01716990122"));
    pharmacies.push_back(Pharmacy("Dighi Pharmacy", "Emaduddin Road", "01885739838"));
    pharmacies.push_back(Pharmacy("Lifeline Pharmacy", "Amchottor, Naodapara", "01732623240"));
    pharmacies.push_back(Pharmacy("Apollo Drugs", "Khorkhori Bazar", "01715059999"));

    // M.R Son Pharma
    pharmacies[0].medicines.push_back("Napa");
    pharmacies[0].medicines.push_back("ORS");
    pharmacies[0].medicines.push_back("Sergel");
    pharmacies[0].medicines.push_back("Senora");
    pharmacies[0].medicines.push_back("Antacid");
    pharmacies[0].medicines.push_back("Cetirizine");

    // Makka Pharmacy
    pharmacies[1].medicines.push_back("Sergel");
    pharmacies[1].medicines.push_back("Cetirizine");
    pharmacies[1].medicines.push_back("Napa");
    pharmacies[1].medicines.push_back("Joya");
    pharmacies[1].medicines.push_back("Tufnil");
    pharmacies[1].medicines.push_back("Feluric");

    // Swapna Medical Hall
    pharmacies[2].medicines.push_back("Viset");
    pharmacies[2].medicines.push_back("Napa");
    pharmacies[2].medicines.push_back("Esipram");
    pharmacies[2].medicines.push_back("Joya");
    pharmacies[2].medicines.push_back("ORS");
    pharmacies[2].medicines.push_back("Cetirizine");

    // Dighi Pharmacy
    pharmacies[3].medicines.push_back("Napa");
    pharmacies[3].medicines.push_back("Antacid");
    pharmacies[3].medicines.push_back("Cetirizine");
    pharmacies[3].medicines.push_back("Motigut");
    pharmacies[3].medicines.push_back("deflux");
    pharmacies[3].medicines.push_back("Sergel");

    // Lifeline Pharmacy
    pharmacies[4].medicines.push_back("Napa");
    pharmacies[4].medicines.push_back("Ceclo");
    pharmacies[4].medicines.push_back("virux");

    // Apollo Drugs
    pharmacies[5].medicines.push_back("Dormicum");
    pharmacies[5].medicines.push_back("Napa");
    pharmacies[5].medicines.push_back("Cotrim");
    pharmacies[5].medicines.push_back("Histacin");
    pharmacies[5].medicines.push_back("Senora");

    // Medicine Search
    string searchMedicine;
    cout << "Enter medicine name: ";
    cin >> searchMedicine;
    searchMedicine=lowerCase(searchMedicine);

    bool found = false;

    for(int i = 0; i < pharmacies.size(); i++)
    {
        for(int j = 0; j < pharmacies[i].medicines.size(); j++)
        {
            string medicineName = pharmacies[i].medicines[j];
            medicineName=lowerCase(medicineName);
            if(medicineName == searchMedicine)
            {
                found = true;

                cout << "\nMedicine Found!" << endl;
                cout << "Pharmacy Name: " << pharmacies[i].name << endl;
                cout << "Address: " << pharmacies[i].address << endl;
                cout << "Phone: " << pharmacies[i].phone << endl;
                cout << "------------------------" << endl;
                
                break;
            }
        }
    }

    if(found == false)
    {
        cout << "Medicine not available!" << endl;
    }

    vector<pair<int,int>> adj[7];

    // Varendra University
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 8});
    adj[0].push_back({5, 6});

    // Khorkhori
    adj[1].push_back({0, 1});
    adj[1].push_back({2, 5});
    adj[1].push_back({6, 5});

    // Koroitola
    adj[2].push_back({0, 8});
    adj[2].push_back({1, 5});
    adj[2].push_back({3, 3});

    // Emamuddin Road
    adj[3].push_back({2, 3});
    adj[3].push_back({4, 1});

    // Amchottor
    adj[4].push_back({3, 1});
    adj[4].push_back({5, 4});
    adj[4].push_back({6, 2});

    // Bus Terminal
    adj[5].push_back({0, 6});
    adj[5].push_back({4, 4});
    adj[5].push_back({6, 1});

    // Dairapak
    adj[6].push_back({1, 5});
    adj[6].push_back({5, 1});
    adj[6].push_back({4, 2});

    return 0;
}