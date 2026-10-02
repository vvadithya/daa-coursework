#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct activity{
    int start;
    int finish;
};

int main() {
    vector<int> start_time = {1, 3, 0, 5, 8, 5};
    vector<int> finish_time = {2, 4, 6, 7, 9, 9};
    int n = start_time.size();
    vector<activity>activities(n);
    for(int i=0;i<n;i++){
        activities[i].start=start_time[i];
        activities[i].finish = finish_time[i];
    }

    sort(activities.begin() , activities.end() , [](const activity&a,const activity&b){
        return a.finish<b.finish;
    });
    int cnt=1;
    activity prev=activities[0];
    vector<activity>optimal_list_of_activities;
    optimal_list_of_activities.push_back(prev);
    for(int i=1;i<n;i++){
        // prev obj , curr obj
        activity curr=activities[i];
        if(curr.start>prev.finish){
            cnt++;
            prev=curr;
            optimal_list_of_activities.push_back(curr);
        }
    }
    cout << "NO OF POSSIBLE ACTIVITIES: " << cnt;
    cout << "\nThe activities are:\n";
    for(auto &obj : optimal_list_of_activities){
        cout << "START: " << obj.start << " FINISH: " << obj.finish << " \n";
    }
    
}