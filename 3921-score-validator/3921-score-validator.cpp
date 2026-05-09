class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;

        for (auto& event : events) {
            if (isdigit(event[0])) {
                score += event[0] - '0';
            } else if (event == "W") {
                ++counter;
            } else {
                ++score;
            }

            if (counter == 10) {
                break;
            }
        }

        return {score, counter};
    }
};