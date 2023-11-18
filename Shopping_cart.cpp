#include<bits/stdc++.h>

using namespace std;

int main() {
    // Vector storing the product name
    vector<string> products = {"Leather wallet", "Umbrella", "Cigarette", "Honey"};

    // Vector of vector to store Unit Price GSt and quantity;
    vector<vector<int>> PriceGstQuantity;

    PriceGstQuantity = {{1100, 18, 1},
                        {900, 12, 4},
                        {200, 28, 3},
                        {100, 0, 2}};

    string maxPriceProduct;

    int maxPrize = 0;
    int TotalSum = 0;


    pair<vector<string>, vector<vector<int>>> Table = {products, PriceGstQuantity};
    //Loop to calculate the total price and Find the maxPrice product
    int i = 0;
    for (auto x : Table.first) {
        

        int currPrice = Table.second[i][0] * ((100 + Table.second[i][1])) * Table.second[i][2]/100;
        if (Table.second[i][0] >= 500) {
            currPrice*=0.95;
        }
        TotalSum += currPrice;
        if (maxPrize < currPrice) {
            maxPrize = currPrice;
            maxPriceProduct = x;
        }
        i++;
    }

    cout << "Product for which we paid maximum: "<< maxPriceProduct <<" Its price is "<<maxPrize<< "\n Total Price for all products: " << TotalSum;

    return 0;
}
