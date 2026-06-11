class Solution {
public:
    string decodeString(string s) {
        stack<int> count_stack;
        stack<string> string_stack;
        string cur_string;
        int cur_num = 0;
        for(char c : s) {
            if(isdigit(c)) {
                cur_num = (cur_num * 10) + c - '0';
            }
            else if(c == '[') {
                string_stack.push(cur_string);
                count_stack.push(cur_num);
                cur_string = "";
                cur_num = 0;
            }
            else if(c == ']') {
                string prev_string = string_stack.top();
                int repetitions = count_stack.top();
                string_stack.pop();
                count_stack.pop();
                string tmp = "";
                for(int i = 0; i < repetitions; i++) {
                    tmp += cur_string;
                }
                cur_string = prev_string + tmp;
            }
            else {
                cur_string += c;
            }
        }
        return cur_string;
    }
};