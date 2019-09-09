//
// Created by vergilken on 8/25/19.
//

#ifndef ALGORITHMS_PROBLEM1146_H
#define ALGORITHMS_PROBLEM1146_H

class SnapshotArray {
public:
    explicit SnapshotArray(int length): snapId(0), map(length) {}

    void set(int index, int val) {
        auto* v = map[index];
        if (v == nullptr) {
            map[index] = new vector<pair<int, int>>(1, make_pair(snapId, val));
        } else if (v -> back().first < snapId) {
            v -> emplace_back(make_pair(snapId, val));
        } else {
            v -> back().second = val;
        }
    }

    int snap() {
        ++snapId;
        return snapId - 1;
    }

    int get(int index, int snap_id) {
        auto* v = map[index];
        if (v == nullptr) {
            return 0;
        } else {
            auto it = lower_bound(v -> begin(), v -> end(), make_pair(snap_id, 0),
                    [](const auto& l, const auto& r) {return l.first < r.first;});
            if (it == v -> end()) {
                return v -> back().second;
            } else if (it -> first == snap_id) {
                return it -> second;
            } else if (it == v -> begin()) {
                return 0;
            } else {
                return (--it) -> second;
            }
        }
    }

private:
    vector<vector<pair<int, int>>*> map;
    int snapId;
};

#endif //ALGORITHMS_PROBLEM1146_H
