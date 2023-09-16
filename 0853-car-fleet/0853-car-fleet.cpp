class Solution {
public:
    struct Car {
        int position;
        int speed;
    };

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        for (int i = 0; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }

        sort (cars.begin(), cars.end(), [](const auto& i, const auto& j) -> bool {
            return i.position > j.position;
        });

        int fleets = 1;
        Car front = cars[0];
        for (int i = 1; i < position.size(); ++i) {
            if (!(front.speed < cars[i].speed && meet(front, cars[i], target))) {
                ++fleets;
                front = cars[i];
            }
        }
        
        return fleets;
    }
    
private:
    bool meet(Car front, Car back, int target) {
        float fronttime = (target - front.position) / (float) front.speed;
        float backtime = (target - back.position) / (float) back.speed;
        
        return backtime <= fronttime;
    }
};