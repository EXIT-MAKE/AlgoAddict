using namespace std;

long long solution(int price, int money, int count)
{
    long answer = 0;
    long sum = 0;

    for (int i = 1; i <= count; i++) {
        sum += i;
    }

    sum *= price;
    answer = sum - money;

    return answer >= 0 ? answer : 0;
}