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
    for(size_t i = 0; i < s.size(); i++)
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
    // Graph Representation:
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

    pharmacies.push_back(Pharmacy("Apollo Drugs", "Khorkhori Bazar", "01715059999"));
    pharmacies.push_back(Pharmacy("Makka Pharmacy", "Koroitola, Meherchondi", "01926894354"));
    pharmacies.push_back(Pharmacy("Dighi Pharmacy", "Emaduddin Road", "01885739838"));
    pharmacies.push_back(Pharmacy("Lifeline Pharmacy", "Amchottor, Naodapara", "01732623240"));
    pharmacies.push_back(Pharmacy("Swapna Medical Hall", "Rajshahi Bus Terminal", "01716990122"));
    pharmacies.push_back(Pharmacy("M.R Son Pharma", "Dairapak Crossroads", "01711972202"));


    // Apollo Drugs
    pharmacies[0].medicines.push_back("ORS");
    pharmacies[0].medicines.push_back("Sergel");
    pharmacies[0].medicines.push_back("Senora");
    pharmacies[0].medicines.push_back("Antacid");
    pharmacies[0].medicines.push_back("Paracetamol");

    // Makka Pharmacy
    pharmacies[1].medicines.push_back("Sergel");
    pharmacies[1].medicines.push_back("Cetirizine");
    pharmacies[1].medicines.push_back("Napa");
    pharmacies[1].medicines.push_back("Joya");
    pharmacies[1].medicines.push_back("Tufnil");
    pharmacies[1].medicines.push_back("Feluric");

    // Dighi Pharmacy
    pharmacies[2].medicines.push_back("Viset");
    pharmacies[2].medicines.push_back("Napa");
    pharmacies[2].medicines.push_back("Esipram");
    pharmacies[2].medicines.push_back("Joya");
    pharmacies[2].medicines.push_back("ORS");
    pharmacies[2].medicines.push_back("Cetirizine");

    // Lifeline Pharmacy
    pharmacies[3].medicines.push_back("Napa");
    pharmacies[3].medicines.push_back("Antacid");
    pharmacies[3].medicines.push_back("Cetirizine");
    pharmacies[3].medicines.push_back("Motigut");
    pharmacies[3].medicines.push_back("deflux");
    pharmacies[3].medicines.push_back("Sergel");

    // Swapna Medical Hall
    pharmacies[4].medicines.push_back("Napa");
    pharmacies[4].medicines.push_back("Ceclo");
    pharmacies[4].medicines.push_back("virux");
    pharmacies[4].medicines.push_back("tufnil");

    // M.R Son Pharma
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


    cout << "==================================================================================\n";
    cout << "                                    MEDIROUTE\n";
    cout << "                      Medicine-Based Nearest Pharmacy Finder\n";
    cout << "==================================================================================\n";
    cout << "\nStarting Location: Varendra University, Rajshahi\n";
    
    // Medicine Search
    string searchMedicine;
    cout << "\nEnter Medicine Name: ";
    cin >> searchMedicine;
    cout << "\nSearching for " << searchMedicine << "........\n";
    searchMedicine=lowerCase(searchMedicine);

    bool found = false;
    int index = -1, shortestDistance = INT_MAX;

    for(size_t i = 0; i < pharmacies.size(); i++)
    {
        for(size_t j = 0; j < pharmacies[i].medicines.size(); j++)
        {
            string medicineName = lowerCase(pharmacies[i].medicines[j]);
            
            if(medicineName == searchMedicine)
            {
                found = true;

                if(index == -1 || dis[i+1] < shortestDistance)
                {
                    index = i;
                    shortestDistance = dis[i+1];
                }
                
                break;
            }
        }
    }

    if(found == true)
    {
        cout << "\nMedicine found!\n";
        cout << "Finding Nearest Pharmacy......\n";
        cout << "\nNearest Pharmacy:\n";
        cout << pharmacies[index].name;
        cout << "\nAddress: " << pharmacies[index].address;
        cout << "\nPhone: " << pharmacies[index].phone;
        cout << "\nDistance: " << dis[index+1] << " km\n";

        string location[7] = {"Varendra University", "Khorkhori", "Koroitola", "Emamuddin Road", "Amchottor", "Bus Terminal", "Dairapak"};
        int destination = index + 1;
        vector<int> path;

        while(destination != -1)
        {
            path.push_back(destination);
            destination = parent[destination];
        }

        reverse(path.begin(), path.end());

        cout << "Shortest Route: ";

        for(size_t i = 0; i < path.size(); i++)
        {
            cout << location[path[i]];

            if(i != path.size() - 1)
            {
                cout << " -> ";
            }
        }
        cout << "\n";
    }    

    else
    {
        cout << "\nMedicine not found in any pharmacy!\n";
    }

    cout << "\nThank you for using MediRoute!\n";
    
    return 0;
}