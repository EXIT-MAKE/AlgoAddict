using System;

namespace Monday {
    public class MainClass {
        private int GetShortOfMoney(int price, int money, int count) {
            int priceSum = 0;

            for (int i = 1; i < count + 1; i++) {
                priceSum += i * price; 
            }

            int result = money - priceSum;

            return result < 0 ? Math.Abs(result) : 0;
        }
    }
}
