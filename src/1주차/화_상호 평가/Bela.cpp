#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";

    for (int i = 0; i < scores.size(); i++) {
        int sum = 0;
        int mine = 0;
        int count = scores.size();
        vector<int> column;
        for (int j = 0; j < scores.size(); j++) {
            if (j == i) {
                mine = scores[j][i];
            }
            column.push_back(scores[j][i]);
            sum += scores[j][i];
        }
        sort(column.begin(), column.end());
        if (column.front() == mine &&
            column.front() != column[1]) {
            sum -= mine;
            count--;
        }
        if (column.back() == mine &&
            column.back() != column[column.size() - 2]) {
            sum -= mine;
            count--;
        }
        double average = sum / count;
        if (average >= 90) {
            answer += 'A';
        }
        else if (average >= 80) {
            answer += 'B';
        }
        else if (average >= 70) {
            answer += 'C';
        }
        else if (average >= 50) {
            answer += 'D';
        }
        else {
            answer += 'F';
        }
    }

    return answer;
}