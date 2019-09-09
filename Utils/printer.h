//
// Created by vergilken on 8/22/19.
//

#ifndef ALGORITHMS_PRINTER_H
#define ALGORITHMS_PRINTER_H

#include "stl_tools.h"

class Printer {
public:
    // print segment line
    static void print_segment_line(int rows) {
        while (rows--) {
            cout << string(80, '*') << endl;
        }
    }

    // print matrix
    template<typename T>
    static void print_matrix(const vector<vector<T>>& matrix) {
         if (matrix.empty() || matrix[0].empty()) {
             return;
         } else {
             for (size_t i = 0; i < matrix.size(); ++i) {
                 for (size_t j = 0; j < matrix[0].size(); ++j) {
                     cout << matrix[i][j] << " ";
                 }
                 cout << endl;
             }
         }
    }

    // print vector
    template<typename T>
    static void print_vector(const vector<T>& vec) {
        if (vec.empty()) {
            return;
        } else {
            for (auto c: vec) {
                cout << c << " ";
            } cout << endl;
        }
    }
};
#endif //ALGORITHMS_PRINTER_H
