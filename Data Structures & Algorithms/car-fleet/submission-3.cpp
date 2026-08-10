#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {

public:
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        // 1. Pair each car's position with its speed

        vector<pair<int, int>> Pairs;

        for (int i = 0; i < position.size(); i++)
            Pairs.push_back({position[i], speed[i]});

        // 2. Sort the pairs in reverse order
        // We need to start from the closest car of the target to the farthest
        // Reverse sorting allows us process every car after the car/fleet in front of it has already been processed.
        
        sort(Pairs.rbegin(), Pairs.rend());

        // 3. Store each fleet's arrival time

        vector<double> Stack;

        for (auto& pair : Pairs) {

            double TimeToRechTarget = (double)(target - pair.first) / pair.second;

            Stack.push_back(TimeToRechTarget);

            if (Stack.size() >= 2 && Stack.back() <= Stack[Stack.size() - 2])
                Stack.pop_back();
        }

        return Stack.size();
    }
};