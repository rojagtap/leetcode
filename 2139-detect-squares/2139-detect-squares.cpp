/*
look for diagonals and take all points such that (x, diagy), (x, y), (diagx, y), (diagx, diagy) form a square
for this diagx - x == diagy - y
*/
class DetectSquares {
public:
    DetectSquares() {
        
    }

    void add(vector<int> point) {
        ++points[{point[0], point[1]}];
    }

    int count(vector<int> point) {
        int squares = 0;
        int px = point[0], py = point[1];
        for (auto entry = points.begin(); entry != points.end(); ++entry) {
            int x = entry->first.first, y = entry->first.second;
            if ((abs(py - y) == abs(px - x)) && x != px && y != py) {
                // * because there can be duplicate entries of points
                squares += points[{x, py}] * points[{px, y}] * points[{x, y}];
            }
        }

        return squares;
    }

private:
    map<pair<int, int>, int> points;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */