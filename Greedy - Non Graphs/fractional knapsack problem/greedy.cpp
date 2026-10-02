#include<bits/stdc++.h>
using namespace std;


struct object{
    double profit;
    double units;
    double ratio;//profit per unit
};

int main(){
    double capacity = 50.0;
    vector<double> profits = {60.0, 100.0, 120.0};
    vector<double> units   = {10.0,  20.0,  30.0};
    int n = profits.size();
    vector<object>arr(n);
    for(int i=0;i<n;i++){
        arr[i].profit=profits[i];
        arr[i].units=units[i];
        arr[i].ratio=profits[i]/units[i];
    }

    sort(arr.begin() , arr.end() , [](const object&a , const object&b){
        return a.ratio>b.ratio;
    });
    // now choose as many units as possible
    double profit=0.0;
    for(auto &obj:arr){
        double units_to_take = min(capacity,obj.units);
        profit += obj.ratio * units_to_take;
        capacity-=units_to_take;
        if(capacity==0.0){
            break;
        }   
    }
    cout << "PROFIT: " << profit << endl;

}