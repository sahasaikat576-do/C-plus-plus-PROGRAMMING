#include <iostream>
using namespace std;

class TrafficMonitor {
private:
    int **trafficData;  // 2D array to store traffic data
    int N;              // Number of zones
    int M;              // Number of time intervals

public:
    // Constructor to initialize traffic data and allocate memory for the 2D array
    TrafficMonitor(int zones, int intervals) {
        N = zones;
        M = intervals;

        // Dynamically allocate memory for the 2D array
        trafficData = new int*[N];
        for (int i = 0; i < N; i++) {
            trafficData[i] = new int[M];
        }
    }

    // Destructor to deallocate memory
    ~TrafficMonitor() {
        for (int i = 0; i < N; i++) {
            delete[] trafficData[i];
        }
        delete[] trafficData;
    }

    // Method to input traffic data for all zones and intervals
    void inputTrafficData() {
        cout << "Enter the traffic data for " << N << " zones and " << M << " time intervals:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << "Enter the number of vehicles in zone " << i + 1 << " at time interval " << j + 1 << ": ";
                cin >> trafficData[i][j];
            }
        }
    }

    // Method to calculate and return the busiest zone using pointers
    int* getBusiestZone() {
        int* busiestZone = nullptr;
        int maxVehicles = -1;

        for (int i = 0; i < N; i++) {
            int totalVehicles = 0;

            // Calculate the total number of vehicles for the current zone
            for (int j = 0; j < M; j++) {
                totalVehicles += trafficData[i][j];
            }

            // Update busiest zone if this zone has more vehicles
            if (totalVehicles > maxVehicles) {
                maxVehicles = totalVehicles;
                busiestZone = &trafficData[i][0]; // Pointing to the first element of the busiest zone
            }
        }

        return busiestZone;
    }

    // Method to display the traffic data
    void displayTrafficData() {
        cout << "Traffic Data:\n";
        for (int i = 0; i < N; i++) {
            cout << "Zone " << i + 1 << ": ";
            for (int j = 0; j < M; j++) {
                cout << trafficData[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Method to print the busiest zone's data
    void printBusiestZoneData(int* busiestZone) {
        if (busiestZone != nullptr) {
            cout << "Busiest Zone Traffic Data: ";
            for (int j = 0; j < M; j++) {
                cout << busiestZone[j] << " ";
            }
            cout << endl;
        } else {
            cout << "No data available.\n";
        }
    }
};

int main() {
    int N, M;

    // Get the number of zones and time intervals
    cout << "Enter the number of zones: ";
    cin >> N;
    cout << "Enter the number of time intervals: ";
    cin >> M;

    // Create the TrafficMonitor object
    TrafficMonitor monitor(N, M);

    // Input traffic data
    monitor.inputTrafficData();

    // Display the traffic data
    monitor.displayTrafficData();

    // Get the busiest zone using pointers
    int* busiestZone = monitor.getBusiestZone();

    // Print the data of the busiest zone
    monitor.printBusiestZoneData(busiestZone);

    return 0;
}
