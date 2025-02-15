class ProductOfNumbers {
    public:
    vector<int>prod;
    ProductOfNumbers() {
        prod = {1};
    }
    void add(int num) {
        if (num == 0)
            prod = {1};
        else
            prod.push_back(prod.back()*num);
    }
    int getProduct(int k) {
        if (prod.size()-1 < k)
            return 0;
        return prod.back() / prod[prod.size()-k-1];
    }
};