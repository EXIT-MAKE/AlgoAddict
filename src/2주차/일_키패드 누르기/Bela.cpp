#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int keypad[12][1][2] = // n번째 키패드를 좌표로 나타냄
    {
        {{3,1}},{{0,0}},{{0,1}},{{0,2}},{{1,0}},{{1,1}},
        {{1,2}},{{2,0}},{{2,1}},{{2,2}},{{3,0}},{{3,2}}
    };
    int l_pos = 10; // *
    int r_pos = 11; // #
    int x = 0;
    int y = 0;
    int l_dis = 0;
    int r_dis = 0;
    for (auto n : numbers)
    {
        // 1, 4, 7 왼손
        if (n == 1 || n == 4 || n == 7)
        {
            answer += 'L';
            l_pos = n;
        }
        // 3, 6, 9 오른손
        else if (n == 3 || n == 6 || n == 9)
        {
            answer += 'R';
            r_pos = n;
        }
        // 가까운 손
        else
        {
            // 왼손 거리
            x = keypad[n][0][0] - keypad[l_pos][0][0];
            y = keypad[n][0][1] - keypad[l_pos][0][1];
            if (x <= 0) x *= -1;
            if (y <= 0) y *= -1;
            l_dis = x + y;

            // 오른손 거리
            x = keypad[n][0][0] - keypad[r_pos][0][0];
            y = keypad[n][0][1] - keypad[r_pos][0][1];
            if (x <= 0) x *= -1;
            if (y <= 0) y *= -1;
            r_dis = x + y;

            if (l_dis < r_dis) // 왼손이 가까움
            {
                answer += 'L';
                l_pos = n;
            }
            else if (l_dis > r_dis) // 오른손이 가까움
            {
                answer += 'R';
                r_pos = n;
            }
            else // 거리가 같다면
            {
                if (hand == "left") // 왼손잡이
                {
                    answer += 'L';
                    l_pos = n;
                }
                else // 오른손잡이
                {
                    answer += 'R';
                    r_pos = n;
                }
            }
        }
    }
    return answer;
}