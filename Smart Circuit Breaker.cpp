#include <iostream>
using namespace std;

class SmartCircuitBreaker {
private:
    double maxCurrent;
    double maxVoltage;

public:
    SmartCircuitBreaker(double currentLimit, double voltageLimit) {
        maxCurrent = currentLimit;
        maxVoltage = voltageLimit;
    }

    void checkSystem(double voltage, double current) {

        cout << "----- Smart Circuit Breaker -----" << endl;
        cout << "Supply Voltage : " << voltage << " V" << endl;
        cout << "Load Current   : " << current << " A" << endl;

        if (current > maxCurrent) {
            cout << "Fault: Overcurrent detected!" << endl;
            cout << "Circuit Breaker: TRIPPED" << endl;
            cout << "Load: DISCONNECTED" << endl;
        }
        else if (voltage > maxVoltage) {
            cout << "Fault: Overvoltage detected!" << endl;
            cout << "Circuit Breaker: TRIPPED" << endl;
            cout << "Load: DISCONNECTED" << endl;
        }
        else {
            cout << "System Status: NORMAL" << endl;
            cout << "Circuit Breaker: ON" << endl;
            cout << "Load: CONNECTED" << endl;
        }
    }
};

int main() {

    // Circuit breaker limits
    double currentLimit = 20.0;   // Amperes
    double voltageLimit = 250.0;  // Volts

    // Measured values
    double supplyVoltage = 230.0;
    double loadCurrent = 25.0;

    SmartCircuitBreaker breaker(currentLimit, voltageLimit);

    breaker.checkSystem(supplyVoltage, loadCurrent);

    return 0;
}
