function solution(price, money, count) {
  const change = money - ((count * (count + 1)) / 2) * price;
  if (change < 0) return -change;
  return 0;
}
