/**
another disasterclass
straight away came up with the bfs idea, but didn't/couldn't think of the edge cases
first thought the only terminating condition is when the next points are empty
then realized it is possible to go round and round in same points => this should've been my clue
but then i went onto a entire journey of seeing if the target can be reached from the base points:
- i tried seeing if target x,y,z lie between min max of each, but then you might never get max value because floor
- then tried some cases with this
- then came up with trying pairs of all initial points and seeing if we can get target point in between
- eventually realized that if the bfs can go into cycles, then we can just filter out only the new points in each cycle and based on that we can do the next.empty check
**/

class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int tx = target[0], ty = target[1], tz = target[2];
        tuple<int, int, int> t = {tx, ty, tz};

        set<tuple<int, int, int>> q;
        for (auto& point : points) {
            int x = point[0], y = point[1], z = point[2];

            tuple<int, int, int> c = {x, y, z};
            if (c == t) return 0;
            q.insert(c);
        }

        // bool x = 0, y = 0, z = 0;

        // for (int i = 0; i < points.size(); ++i) {
        //     int x1 = points[i][0], y1 = points[i][1], z1 = points[i][2];
        //     for (int j = i + 1; j < points.size(); ++j) {
        //         int x2 = points[j][0], y2 = points[j][1], z2 = points[j][2];

        //         if ((tx >= min(x1, x2) && tx < max(x1, x2)) || (tx == max(x1, x2) && x1 == x2)) {
        //             x = 1;
        //         }

        //         if ((ty >= min(y1, y2) && ty < max(y1, y2)) || (ty == max(y1, y2) && y1 == y2)) {
        //             y = 1;
        //         }

        //         if ((tz >= min(z1, z2) && tz < max(z1, z2)) || (tz == max(z1, z2) && z1 == z2)) {
        //             z = 1;
        //         }
        //     }
        // }

        // if (!x || !y || !z) {
        //     return -1;
        // }

        int k = 0;

        auto getc = [] (tuple<int, int, int> a, tuple<int, int, int> b) {
            auto [x1, y1, z1] = a;
            auto [x2, y2, z2] = b;
            tuple<int, int, int> c = {floor((x1 + x2) / 2.0), floor((y1 + y2) / 2.0), floor((z1 + z2) / 2.0)};
            return c;
        };

        while (true) {
            vector<tuple<int, int, int>> temp(begin(q), end(q)), next;

            for (int i = 0; i < temp.size(); ++i) {
                for (int j = i + 1; j < temp.size(); ++j) {
                    auto c = getc(temp[i], temp[j]);
                    if (c == t) return k + 1;
                    if (!q.count(c)) next.push_back(c);
                }
            }

            if (next.empty()) return -1;

            for (auto& c : next) {
                q.insert(c);
            }

            ++k;
        }

        return -1;
    }
};

/**
// 7 (tle, [[0,6,3],[4,0,1]], [2,5,1])
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int tx = target[0], ty = target[1], tz = target[2];
        tuple<int, int, int> t = {tx, ty, tz};

        set<tuple<int, int, int>> q;
        for (auto& point : points) {
            int x = point[0], y = point[1], z = point[2];

            tuple<int, int, int> c = {x, y, z};
            if (c == t) return 0;
            q.insert(c);
        }

        bool x = 0, y = 0, z = 0;

        for (int i = 0; i < points.size(); ++i) {
            int x1 = points[i][0], y1 = points[i][1], z1 = points[i][2];
            for (int j = i + 1; j < points.size(); ++j) {
                int x2 = points[j][0], y2 = points[j][1], z2 = points[j][2];

                if ((tx >= min(x1, x2) && tx < max(x1, x2)) || (tx == max(x1, x2) && x1 == x2)) {
                    x = 1;
                }

                if ((ty >= min(y1, y2) && ty < max(y1, y2)) || (ty == max(y1, y2) && y1 == y2)) {
                    y = 1;
                }

                if ((tz >= min(z1, z2) && tz < max(z1, z2)) || (tz == max(z1, z2) && z1 == z2)) {
                    z = 1;
                }
            }
        }

        if (!x || !y || !z) {
            return -1;
        }

        int k = 0;

        auto getc = [] (tuple<int, int, int> a, tuple<int, int, int> b) {
            auto [x1, y1, z1] = a;
            auto [x2, y2, z2] = b;
            tuple<int, int, int> c = {floor((x1 + x2) / 2.0), floor((y1 + y2) / 2.0), floor((z1 + z2) / 2.0)};
            return c;
        };

        while (true) {
            vector<tuple<int, int, int>> temp(begin(q), end(q)), next;

            for (int i = 0; i < temp.size(); ++i) {
                for (int j = i + 1; j < temp.size(); ++j) {
                    auto c = getc(temp[i], temp[j]);
                    if (c == t) return k + 1;
                    next.push_back(c);
                }
            }

            if (next.empty()) return -1;

            for (auto& c : next) {
                q.insert(c);
            }

            ++k;
        }

        return -1;
    }
};

// 6 (wa, [[1,6,2],[1,6,5]], [1,6,4])
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int tx = target[0], ty = target[1], tz = target[2];
        tuple<int, int, int> t = {tx, ty, tz};

        int minx = 6, maxx = 0, miny = 6, maxy = 0, minz = 6, maxz = 0;

        set<tuple<int, int, int>> q;
        for (auto& point : points) {
            int x = point[0], y = point[1], z = point[2];

            minx = min(minx, x);
            maxx = max(maxx, x);
            miny = min(miny, y);
            maxy = max(maxy, y);
            minz = min(minz, z);
            maxz = max(maxz, z);

            tuple<int, int, int> c = {x, y, z};
            if (c == t) return 0;
            q.insert(c);
        }

        if (tx < minx || tx >= maxx || ty < miny || ty >= maxy || tz < minz || tz >= maxz) {
            return -1;
        }

        int k = 0;

        auto getc = [] (tuple<int, int, int> a, tuple<int, int, int> b) {
            auto [x1, y1, z1] = a;
            auto [x2, y2, z2] = b;
            tuple<int, int, int> c = {floor((x1 + x2) / 2.0), floor((y1 + y2) / 2.0), floor((z1 + z2) / 2.0)};
            return c;
        };

        while (true) {
            vector<tuple<int, int, int>> temp(begin(q), end(q)), next;

            for (int i = 0; i < temp.size(); ++i) {
                for (int j = i + 1; j < temp.size(); ++j) {
                    auto c = getc(temp[i], temp[j]);
                    if (c == t) return k + 1;
                    next.push_back(c);
                }
            }

            if (next.empty()) return -1;

            for (auto& c : next) {
                q.insert(c);
            }

            ++k;
        }

        return -1;
    }
};

// 5 (wa, [[1,6,2],[1,6,5]], [1,6,4])
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int tx = target[0], ty = target[1], tz = target[2];
        tuple<int, int, int> t = {tx, ty, tz};

        int minx = 6, maxx = 0, miny = 6, maxy = 0, minz = 6, maxz = 0;

        set<tuple<int, int, int>> q;
        for (auto& point : points) {
            int x = point[0], y = point[1], z = point[2];

            minx = min(minx, x);
            maxx = max(maxx, x);
            miny = min(miny, y);
            maxy = max(maxy, y);
            minz = min(minz, z);
            maxz = max(maxz, z);

            tuple<int, int, int> c = {x, y, z};
            if (c == t) return 0;
            q.insert(c);
        }

        if (tx < minx || tx >= maxx || ty < miny || ty >= maxy || tz < minz || tz >= maxz) {
            return -1;
        }

        int k = 0;

        auto getc = [] (tuple<int, int, int> a, tuple<int, int, int> b) {
            auto [x1, y1, z1] = a;
            auto [x2, y2, z2] = b;
            tuple<int, int, int> c = {floor((x1 + x2) / 2.0), floor((y1 + y2) / 2.0), floor((z1 + z2) / 2.0)};
            return c;
        };

        while (true) {
            vector<tuple<int, int, int>> temp(begin(q), end(q)), next;

            for (int i = 0; i < temp.size(); ++i) {
                for (int j = i + 1; j < temp.size(); ++j) {
                    auto c = getc(temp[i], temp[j]);
                    if (c == t) return k + 1;
                    next.push_back(c);
                }
            }

            if (next.empty()) return -1;

            for (auto& c : next) {
                q.insert(c);
            }

            ++k;
        }

        return -1;
    }
};

// 4 (wa, [[1,6,2],[1,6,5]], [1,6,4])
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int tx = target[0], ty = target[1], tz = target[2];
        tuple<int, int, int> t = {tx, ty, tz};

        int minx = 6, maxx = 0, miny = 6, maxy = 0, minz = 6, maxz = 0;

        set<tuple<int, int, int>> q;
        for (auto& point : points) {
            int x = point[0], y = point[1], z = point[2];

            minx = min(minx, x);
            maxx = max(maxx, x);
            miny = min(miny, y);
            maxy = max(maxy, y);
            minz = min(minz, z);
            maxz = max(maxz, z);

            tuple<int, int, int> c = {x, y, z};
            if (c == t) return 0;
            q.insert(c);
        }

        if (tx < minx || tx >= maxx || ty < miny || ty >= maxy || tz < minz || tz >= maxz) {
            return -1;
        }

        int k = 0;

        auto getc = [] (tuple<int, int, int> a, tuple<int, int, int> b) {
            auto [x1, y1, z1] = a;
            auto [x2, y2, z2] = b;
            tuple<int, int, int> c = {floor((x1 + x2) / 2.0), floor((y1 + y2) / 2.0), floor((z1 + z2) / 2.0)};
            return c;
        };

        while (true) {
            vector<tuple<int, int, int>> temp(begin(q), end(q)), next;

            for (int i = 0; i < temp.size(); ++i) {
                for (int j = i + 1; j < temp.size(); ++j) {
                    auto c = getc(temp[i], temp[j]);
                    if (c == t) return k + 1;
                    next.push_back(c);
                }
            }

            if (next.empty()) return -1;

            for (auto& c : next) {
                q.insert(c);
            }

            ++k;
        }

        return -1;
    }
};

// 3 (tle, [[1,4,5],[3,0,0]], [3,2,4])
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int tx = target[0], ty = target[1], tz = target[2];
        tuple<int, int, int> t = {tx, ty, tz};

        int minx = 6, maxx = 0, miny = 6, maxy = 0, minz = 6, maxz = 0;

        set<tuple<int, int, int>> q;
        for (auto& point : points) {
            int x = point[0], y = point[1], z = point[2];

            minx = min(minx, x);
            maxx = max(maxx, x);
            miny = min(miny, y);
            maxy = max(maxy, y);
            minz = min(minz, z);
            maxz = max(maxz, z);

            tuple<int, int, int> c = {x, y, z};
            if (c == t) return 0;
            q.insert(c);
        }

        if (tx < minx || tx > maxx || ty < miny || ty > maxy || tz < minz || tz > maxz) {
            return -1;
        }

        int k = 0;

        auto getc = [] (tuple<int, int, int> a, tuple<int, int, int> b) {
            auto [x1, y1, z1] = a;
            auto [x2, y2, z2] = b;
            tuple<int, int, int> c = {floor((x1 + x2) / 2.0), floor((y1 + y2) / 2.0), floor((z1 + z2) / 2.0)};
            return c;
        };

        while (true) {
            vector<tuple<int, int, int>> temp(begin(q), end(q)), next;

            for (int i = 0; i < temp.size(); ++i) {
                for (int j = i + 1; j < temp.size(); ++j) {
                    auto c = getc(temp[i], temp[j]);
                    if (c == t) return k + 1;
                    next.push_back(c);
                }
            }

            if (next.empty()) return -1;

            for (auto& c : next) {
                q.insert(c);
            }

            ++k;
        }

        return -1;
    }
};

// 2 (wa, [[0,0,0],[6,6,6]], [3,3,3])
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int tx = target[0], ty = target[1], tz = target[2];
        tuple<int, int, int> t = {tx, ty, tz};

        int minx = 7, maxx = -1, miny = 7, maxy = -1, minz = 7, maxz = -1;

        set<tuple<int, int, int>> q;
        for (auto& point : points) {
            int x = point[0], y = point[1], z = point[2];

            minx = min(minx, x);
            maxx = max(maxx, x);
            miny = min(miny, y);
            maxy = max(maxy, y);
            minz = min(minz, z);
            maxz = max(maxz, z);

            tuple<int, int, int> c = {};
            if (c == t) return 0;
            q.insert(c);
        }

        if (tx < minx || tx > maxx || ty < miny || ty > maxy || tz < minz || tz > maxz) {
            return -1;
        }

        int k = 0;

        auto getc = [] (tuple<int, int, int> a, tuple<int, int, int> b) {
            auto [x1, y1, z1] = a;
            auto [x2, y2, z2] = b;
            tuple<int, int, int> c = {floor((x1 + x2) / 2.0), floor((y1 + y2) / 2.0), floor((z1 + z2) / 2.0)};
            return c;
        };

        while (true) {
            vector<tuple<int, int, int>> temp(begin(q), end(q)), next;

            for (int i = 0; i < temp.size(); ++i) {
                for (int j = i + 1; j < temp.size(); ++j) {
                    auto c = getc(temp[i], temp[j]);
                    if (c == t) return k + 1;
                    next.push_back(c);
                    cout << "(" << get<0>(c) << ", " << get<1>(c) << ", " << get<2>(c) << ") ";
                }
            }

            cout << endl;

            if (next.empty()) return -1;

            for (auto& c : next) {
                q.insert(c);
            }

            ++k;
        }

        return -1;
    }
};

// 1 (tle, [[2,0,5],[0,5,5]], [0,2,4])
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        tuple<int, int, int> t = {target[0], target[1], target[2]};

        set<tuple<int, int, int>> q;
        for (auto& point : points) {
            tuple<int, int, int> c = {point[0], point[1], point[2]};
            if (c == t) return 0;
            q.insert(c);
        }

        int k = 0;

        auto getc = [] (tuple<int, int, int> a, tuple<int, int, int> b) {
            auto [x1, y1, z1] = a;
            auto [x2, y2, z2] = b;
            tuple<int, int, int> c = {(x1 + x2) / 2, (y1 + y2) / 2, (z1 + z2) / 2};
            return c;
        };

        while (true) {
            vector<tuple<int, int, int>> temp(begin(q), end(q)), next;

            for (int i = 0; i < temp.size(); ++i) {
                for (int j = i + 1; j < temp.size(); ++j) {
                    auto c = getc(temp[i], temp[j]);
                    if (c == t) return k + 1;
                    next.push_back(c);
                }
            }

            if (next.empty()) return -1;

            for (auto& c : next) {
                q.insert(c);
            }

            ++k;
        }

        return -1;
    }
};
**/