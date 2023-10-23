#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    int n, x; cin >> n >> x;
 
    int peopleWeights[n];
    for (auto &x : peopleWeights) cin >> x;
 
    //We need to use bitmasking to compute the dp table
 
    vector <pair <int, int>> dp (1 << n);
    // Pair : {NumberOfElevatorRides , WeightOfLastRide} for the 
    // chosen subset of people
 
    dp[0] = {1, 0};
    //First ride with no people for empty subset of chosen people
 
    for (int subset = 1; subset < (1 << n); subset++) {
 
        dp[subset] = {21, 0};
        //We consider that the chosen subset of people need 21 rides
        //(since we know , n <= 20) with an empty last ride.
 
        for (int person = 0; person < n; person++) {
 
            //We check if the person is a part of the chosen subset of people
            
            if ((subset >> person) & 1) {
                int rides = dp[subset ^ (1 << person)].first, weight = dp[subset ^ (1 << person)].second;
                //gets the state of the elevator rides upto the last chosen person
 
                if (weight + peopleWeights[person] > x) {
                    rides++;
                    weight = min (peopleWeights[person], weight);
                }
 
                else weight += peopleWeights[person];
                dp[subset] = min (dp[subset], {rides, weight});
 
            }
 
        }
    }
 
    cout << dp[(1 << n) - 1].first;
    //Minimum Number of rides with all the people chosen 
}
