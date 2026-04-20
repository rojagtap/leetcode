double PI = 3.14159265358979323846;

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        // https://leetcode.com/problems/angles-of-a-triangle/solutions/7877131/binary-search-without-using-formulas-by-46k3z

        sort(begin(sides), end(sides));
        int AB = sides[0], BC = sides[1], AC = sides[2];

        // AC is longest

        if (AB + BC <= AC) {
            return {};
        }

        auto sind = [] (double degrees) {
            return sin(degrees * (PI / 180.0));
        };

        auto search = [&] (int left, int right, int base) {
            // base must be the longest side
            // this ensures the top vertex is the largest angle
            // which means the perpendicular will always be on the base (not outside)
            // i.e., base = half1 + half2
            double low = 0, high = 90;

            while (high - low > 1e-8) {
                double mid = (low + high) / 2.0;
                double height = sind(mid) * left;
                double half1 = sqrt(left * left - height * height);
                double half2 = base - half1;

                if (half2 * half2 + height * height >= right * right) {
                    high = mid;
                } else {
                    low = mid;
                }
            }

            return low;
        };

        double A = search(AB, BC, AC);
        double C = search(BC, AB, AC);
        double B = 180 - A - C;

        vector<double> angles = {A, B, C};

        sort(begin(angles), end(angles));

        return angles;
    }
};