#include <bits/stdc++.h>
using namespace std;

vector<int> FindbestCoordinate(vector<vector<int>>& towers, int radius) {
        int n = towers.size();
        int sum;
        int ans = 0;
        
        pair<int,int> final;
		// Calculate for every 'x's and 'y's 
        for(int x = 0; x <= n; x++){
            for(int y = 0; y <= 50; y++){
                sum = 0;
                for(const auto it : towers){
                    int xa = it[0];
                    int ya = it[1];
                    int qa = it[2];
					// get the distance between the two points
                    int distance = pow(x - xa, 2) + pow(y - ya, 2);
                    if(distance > radius * radius) {
                        continue;
                    }
					// increment the quality value
                    sum += (int)(qa / (1 + sqrt(distance)));
                }
				// store the maximum ans
                if(sum > ans){
                    ans = sum;
                    final = {x,y};
                }
            }
        }
        return vector<int>{{final.first, final.second}};
    }

int main() 
{
      vector<vector<int>> towers = {{1, 2, 5}, {2, 1, 7}, {3, 1, 9}};
      int radius = 2;

    vector<int> result = FindbestCoordinate(towers, radius);

    cout << "Best coordinate: [" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}