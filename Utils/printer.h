//
// Created by vergilken on 8/22/19.
//

#ifndef ALGORITHMS_PRINTER_H
#define ALGORITHMS_PRINTER_H

struct Trunk {
    Trunk* prev;
    string str;
    explicit Trunk(Trunk* _prev, string _str) {
        prev = _prev;
        str = move(_str);
    }
};

template<typename T>
class Printer {
public:
    // print segment line
    static void print_segment_line(int rows) {
        while (rows--) {
            cout << string(80, '*') << endl;
        }
    }

    // print matrix
    static void print_matrix(const vector<vector<T>>& matrix) {
         if (matrix.empty() || matrix[0].empty()) {
             return;
         } else {
             for (size_t i = 0; i < matrix.size(); ++i) {
                 for (size_t j = 0; j < matrix[i].size(); ++j) {
                     cout << matrix[i][j] << " ";
                 }
                 cout << endl;
             }
         }
    }

    // print vector
    static void print_vector(const vector<T>& vec) {
        if (vec.empty()) {
            return;
        } else {
            for (auto c: vec) {
                cout << c << " ";
            }
            cout << endl;
        }
    }

    // print binary tree
    static void print_binary_tree(TreeNode<T>* root) {
        print_tree_helper(root, nullptr, false);
    }

    // print forward linked list
    static void print_forward_linked_list(ForwardLinkedListNode<T>* head) {
        while (head != nullptr) {
            cout << head->value << " ";
            head = head->next;
        }
        cout << endl;
    }

    static void print_stack(stack<T>& st) {
        vector<T> tmp;
        while(!st.empty()) {
           tmp.push_back(st.top());
           st.pop();
        }
        reverse(tmp.begin(), tmp.end());
        cout << "|| ";
        print_vector(tmp);
    }

private:
    // print binary tree branches of binary tree
    static void show_trunks(Trunk *p) {
        if (p != nullptr) {
            show_trunks(p -> prev);
            cout << p -> str;
        }
    }

    // use in-order traversal to print binary tree
    static void print_tree_helper(TreeNode<T>* root, Trunk *prev, bool isLeft) {
        if (root == nullptr) return;
        string prev_str = "    ";
        auto *trunk = new Trunk(prev, prev_str);
        print_tree_helper(root -> left, trunk, true);

        if (!prev) {
            trunk -> str = "---";
        } else if (isLeft) {
            trunk -> str = ".---";
            prev_str = "  |";
        } else {
            trunk -> str = "`---";
            prev -> str = prev_str;
        }

        show_trunks(trunk);
        cout << root -> value << endl;

        if (prev) {
            prev -> str = prev_str;
        }
        trunk -> str = "  |";
        print_tree_helper(root -> right, trunk, false);
    }
};

#endif //ALGORITHMS_PRINTER_H
