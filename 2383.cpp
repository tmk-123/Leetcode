#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int hours = 0;
        int curEnergy = initialEnergy;
        int curExp = initialExperience;
        
        for (int i = 0; i < energy.size(); i++) {
            curEnergy -= energy[i];

            if (curExp <= experience[i]) {
                hours += experience[i] + 1 - curExp;
                curExp = experience[i] + 1;
            }
            curExp += experience[i];
        }

        cout << hours << endl;
        if (curEnergy <= 0) hours -= curEnergy - 1; 
        return hours;
    }
};