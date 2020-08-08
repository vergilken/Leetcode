#ifndef LEETCODE_PROBLEM1538_H
#define LEETCODE_PROBLEM1538_H
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */
class ArrayReader {
public:
    explicit ArrayReader(vector<int> _arr) {
        arr = move(_arr);
    }

    virtual ~ArrayReader() {
        vector<int>().swap(arr);
    }
    int query(int a, int b, int c, int d) {
        int sum = arr[a] + arr[b] + arr[c] + arr[d];
        switch(sum) {
            case 4:
            case 0:
                return 4;
            case 3:
            case 1:
                return 2;
            case 2:
                return 0;
            default:
                return -1;
        }
    }

    int length() {
        return arr.size();
    }

private:
    vector<int> arr;
};

class GuessMajorityInHiddenArray {
public:
    static int guessMajority(ArrayReader &reader) {
        int len = reader.length();
        if (len < 5) {
            return -1;
        }

        pair<size_t, size_t> base = getBase(reader);
        int result = getMajorityIndex(base, len, reader);
        return result;
    }

private:
    static pair<size_t, size_t> getBase(ArrayReader &reader) {
        switch(reader.query(0, 1, 2, 3)) {
            case 4: return pair<size_t, size_t>{0, 1};
            case 2: {
                switch (reader.query(0, 1, 2, 4)) {
                    case 4: return pair<size_t, size_t>{0, 1};
                    case 2: return pair<size_t, size_t>{3, 4};
                    case 0: {
                        switch (reader.query(0, 1, 3, 4)) {
                            case 2: return pair<size_t, size_t>{0, 1};
                            case 0: return pair<size_t, size_t>{2, 3};
                        }
                    }
                }
            }
            case 0: {
                switch (reader.query(0, 1, 2, 4)) {
                    case 0: return pair<int, int>{3, 4};
                    case 2: {
                        switch (reader.query(0, 1, 3, 4)) {
                            case 2: return pair<size_t, size_t>{2, 3};
                            case 0: return pair<size_t, size_t>{2, 4};
                        }
                    }
                }
            };
            default: return pair<size_t, size_t>{-1, -1};
        }
    }

    static bool checkElements(size_t a, size_t b, size_t i, size_t j, size_t &left, size_t &right, ArrayReader &reader) {
        switch (sortedCheck(a, b, i, j, reader)) {
            case 4: left += 2; return false;
            case 2: left += 1; right += 1; return false;
            case 0: right += 2; return true;
            default: return false;
        }
    }

    static int sortedCheck(size_t a, size_t b, size_t i, size_t j, ArrayReader &reader) {
        size_t tmpArr[4] = {a, b, i, j};
        sort(tmpArr, tmpArr + sizeof(tmpArr)/sizeof(tmpArr[0]));
        cout << a<< " " << b << " " <<  i << " " << j <<endl;
        return reader.query(tmpArr[0], tmpArr[1], tmpArr[2], tmpArr[3]);
    }

    static int getMajorityIndex(pair<int, int> base, int len, ArrayReader &reader) {
        size_t a = base.first, b = base.second, left = 0, right = 0;
        left += 2;

        size_t leftIndex = a;
        size_t rightIndex = -1;

        size_t edge = (len & 1) == 1 ? len - 1 : len;
        for (size_t i = 0; i < edge; ++i) {
            while (i == a || i == b) {++i;}
            size_t j = i + 1;
            while (j == a || j == b) {++j;}
            if (i >= edge || j >= edge) break;
            auto flag = checkElements(a, b, i, j, left, right, reader);
            if (flag && -1 == rightIndex) {
                rightIndex = i;
            }
            i = j;
        }

        if (left == right) {
            if (5 == len && 3 == a && 4 == b) {
                return 2;
            } else if (edge < len) {
                return edge;
            }
            return -1;
        } else if (left < right) {
            return rightIndex;
        } else {
            return leftIndex;
        }
    }
};
#endif //LEETCODE_PROBLEM1538_H
