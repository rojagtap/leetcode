/*
first sort by position so that the lane is aligned
if the car ahead is slower than the one behind and they meet then, same fleet
else new fleet

if two cars are in a fleet, they will both go in the same slower speed of both i.e, the front car
so in
target      A <- B <- C
if ABC are going to be a fleet, then AB will meet and AC will meet.
Note that even if B and C meet before meeting A, it doesn't matter as all three are eventually going to go with A's speed
so we only need the front of the fleet always

as soon as a new fleet is formed, i.e., a front car A does not meet the back car B,
then B becomes the new front of the fleet as even if all the cars behind B meet, they can go as fast as B so we don't really need A anymore and we can increment the number of fleets and leave it.
i.e., although we are using a stack, we only need the top always

it will hence take constant space
*/
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