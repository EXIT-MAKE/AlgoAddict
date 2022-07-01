#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int keypad[12][1][2] = // n��° Ű�е带 ��ǥ�� ��Ÿ��
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
        // 1, 4, 7 �޼�
        if (n == 1 || n == 4 || n == 7)
        {
            answer += 'L';
            l_pos = n;
        }
        // 3, 6, 9 ������
        else if (n == 3 || n == 6 || n == 9)
        {
            answer += 'R';
            r_pos = n;
        }
        // ����� ��
        else
        {
            // �޼� �Ÿ�
            x = keypad[n][0][0] - keypad[l_pos][0][0];
            y = keypad[n][0][1] - keypad[l_pos][0][1];
            if (x <= 0) x *= -1;
            if (y <= 0) y *= -1;
            l_dis = x + y;

            // ������ �Ÿ�
            x = keypad[n][0][0] - keypad[r_pos][0][0];
            y = keypad[n][0][1] - keypad[r_pos][0][1];
            if (x <= 0) x *= -1;
            if (y <= 0) y *= -1;
            r_dis = x + y;

            if (l_dis < r_dis) // �޼��� �����
            {
                answer += 'L';
                l_pos = n;
            }
            else if (l_dis > r_dis) // �������� �����
            {
                answer += 'R';
                r_pos = n;
            }
            else // �Ÿ��� ���ٸ�
            {
                if (hand == "left") // �޼�����
                {
                    answer += 'L';
                    l_pos = n;
                }
                else // ����������
                {
                    answer += 'R';
                    r_pos = n;
                }
            }
        }
    }
    return answer;
}