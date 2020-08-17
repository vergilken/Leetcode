//
// Created by Vergilken on 8/13/20.
//

#ifndef LEETCODE_PROBLEM0609_H
#define LEETCODE_PROBLEM0609_H

class FindDuplicateFileInSystem {
public:
    vector<vector<string>> find_duplicate_file(vector<string>& paths) {
        unordered_map<string, vector<string>> files;
        vector<vector<string>> result;

        for (auto path: paths) {
            stringstream in(path);
            string root, tmp;
            getline(in, root, ' ');
            while(getline(in, tmp, ' ')) {
                string fileName = root + '/' + tmp.substr(0, tmp.find('('));
                string fileContent = tmp.substr(tmp.find('(') + 1, tmp.find(')') - tmp.find('(') - 1);
                files[fileContent].push_back(fileName);
            }
        }

        for (auto file: files) {
            if (file.second.size() > 1)
                result.push_back(file.second);
        }
        return result;
    }
};
#endif //LEETCODE_PROBLEM0609_H
