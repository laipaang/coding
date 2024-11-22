std::vector<int> getFriends(id);

// 时间复杂度O(N^3)
std::vector<int> getSecondLevelFriends(self) {
    auto friends = getFriends(self);
    std::unordered_set<int> friends_set(friends.begin(), friends.end());
    std::vector<int> result;

    // 遍历1阶朋友
    for (auto f1: friends_set) {
        // 遍历2阶朋友
        for (auto f2: getFriends(i)) {
            // 2阶朋友不能是id的直接朋友，或者id自身
            if (friends_set.count(f2) || f2 == self) {
                continue;
            }

            // f2是否和id有3个共同好友
            int cnt = 0;
            for (auto f3: getFriends(f2)) {
                if (friends_set.count(f3)) {
                    ++cnt;
                }
            }
            if (cnt == 3) {
                result.pushback(f2);
            }
        }
    }

    return result;
}

// 时间复杂度O(N^2)
std::vector<int> getSecondLevelFriends(self) {
    auto friends = getFriends(self);
    std::unordered_set<int> friends_set(friends.begin(), friends.end());

    std::unordered_map<int, int> f2_cnt;
    // 遍历1阶朋友
    for (auto f1: friends_set) {
        // 遍历2阶朋友
        for (auto f2: getFriends(i)) {
            // 2阶朋友不能是id的直接朋友，或者id自身
            if (friends_set.count(f2) || f2 == self) {
                continue;
            }

            f2_cnt[f2]++;
        }
    }

    std::vector<int> result;
    for (auto kv: f2_cnt) {
        if (kv.second == 3) {
            result.pushback(kv.first);
        }
    }

    return result;
}