#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_list[7];
int dis[7];
int parent[7];

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

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dis[s] = 0;

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int p_dis = p.first;
        int p_node = p.second;

        for (auto c : adj_list[p_node])
        {
            int c_node = c.first;
            int c_dis = c.second;

            if (p_dis + c_dis < dis[c_node])
            {
                dis[c_node] = p_dis + c_dis;
                pq.push({dis[c_node], c_node});
                parent[c_node] = p_node;
            }
        }
    }
}

int main()
{
    // Varendra University
    adj_list[0].push_back({1, 1});
    adj_list[0].push_back({2, 8});
    adj_list[0].push_back({5, 6});

    // Khorkhori
    adj_list[1].push_back({0, 1});
    adj_list[1].push_back({2, 5});
    adj_list[1].push_back({6, 5});

    // Koroitola
    adj_list[2].push_back({0, 8});
    adj_list[2].push_back({1, 5});
    adj_list[2].push_back({3, 3});

    // Emamuddin Road
    adj_list[3].push_back({2, 3});
    adj_list[3].push_back({4, 1});

    // Amchottor
    adj_list[4].push_back({3, 1});
    adj_list[4].push_back({5, 4});
    adj_list[4].push_back({6, 2});

    // Bus Terminal
    adj_list[5].push_back({0, 6});
    adj_list[5].push_back({4, 4});
    adj_list[5].push_back({6, 1});

    // Dairapak
    adj_list[6].push_back({1, 5});
    adj_list[6].push_back({5, 1});
    adj_list[6].push_back({4, 2});

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
    pharmacies[4].medicines.push_back("tufnil");

    // Apollo Drugs
    pharmacies[5].medicines.push_back("Dormicum");
    pharmacies[5].medicines.push_back("Napa");
    pharmacies[5].medicines.push_back("Cotrim");
    pharmacies[5].medicines.push_back("Histacin");
    pharmacies[5].medicines.push_back("Senora");


    for(int i = 0; i < 7; i++)
    {
        dis[i] = INT_MAX;
        parent[i] = -1;
    }
    dijkstra(0);

    vector<pair<int,string>>shortestDistance;
    shortestDistance.push_back({INT_MAX,pharmacies[0].name});
    shortestDistance.push_back({INT_MAX,pharmacies[1].name});
    shortestDistance.push_back({INT_MAX,pharmacies[2].name});
    shortestDistance.push_back({INT_MAX,pharmacies[3].name});
    shortestDistance.push_back({INT_MAX,pharmacies[4].name});
    shortestDistance.push_back({INT_MAX,pharmacies[5].name});

    

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

                shortestDistance[i].first=dis[i+1];

                cout << "\nMedicine Found!" << endl;
                cout << "Pharmacy Name: " << pharmacies[i].name << endl;
                cout << "Address: " << pharmacies[i].address << endl;
                cout << "Phone: " << pharmacies[i].phone << endl;
                cout << "Distance: " << dis[i+1] << " km" << endl;
                cout << "------------------------" << endl;
                
                break;
            }
        }
    }

    if(found == true)
    {
        cout << "Medicine found!" << endl;

        // for(auto p: shortestDistance)
        // {
        //     if(p.first!=INT_MAX)
        //     {
        //         cout << "Pharmacy: " << p.second << ", Distance: " << p.first << " km" << endl;
        //     }
        // }
        cout << endl;

        sort(shortestDistance.begin(), shortestDistance.end());
        cout << shortestDistance[0].second << " " << shortestDistance[0].first << " km" << endl;
    }

    else
    {
        cout << "Medicine not found in any pharmacy!" << endl;
    }


    return 0;
}