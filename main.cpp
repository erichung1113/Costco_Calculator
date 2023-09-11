#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Please enter how many people there are in total : ";
    int NumberOfPeople;
    cin >> NumberOfPeople;
    vector<int> Total(NumberOfPeople+1);
    string line;
    while(getline(cin,line)){
        if(line == "") continue;
        if(line == "end") break;
        stringstream ss(line);
        int ItemPrice;
        ss >> ItemPrice;
        vector<int> WhoToShare;
        int person;
        while(ss >> person) {
            if(person == 0){
                for(int i=1;i<=NumberOfPeople;i++) WhoToShare.push_back(i);
            }else{ 
                WhoToShare.push_back(person);
            }
        }
        int NumberOfShares=WhoToShare.size();
        int AvgItmePrice=ceil((double)ItemPrice/NumberOfShares);
        for(auto who:WhoToShare){
            Total[who]+=AvgItmePrice;
        }
        cout << "----Current----\n";
        for(int i=1;i<=4;i++) cout << "person " << i << " : " << Total[i] << '\n';
        cout << "---------------\n";
    }

    cout << "---------Total----------\n";
    for(int i=1;i<=4;i++) cout << "|    person " << i << " : " << left << setw(8) << Total[i] << "|" << '\n';
    cout << "------------------------\n";
}
