class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        count.resize(3);
        count[0] = big;
        count[1] = medium;
        count[2] = small;
    }
    
    bool addCar(int carType) {
        if (count[carType - 1] <= 0) return false;
        count[carType - 1]--;
        return true;
    }

private:
    vector<int> count;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
