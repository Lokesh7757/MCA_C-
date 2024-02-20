#include<iostream>
#include<iomanip>

class WeatherReport {
private:
    int day_of_month;
    double hightemp;
    double lowtemp;
    double amount_rain;
    double amount_snow;

public:
    // Default constructor
    WeatherReport() : day_of_month(1), hightemp(0.0), lowtemp(0.0), amount_rain(0.0), amount_snow(0.0) {}

    // Parameterized constructor
    WeatherReport(int day, double high, double low, double rain, double snow)
        : day_of_month(day), hightemp(high), lowtemp(low), amount_rain(rain), amount_snow(snow) {}

    // Function to input values from the user
    void inputValues() {
        std::cout << "Enter day of month: ";
        std::cin >> day_of_month;
        std::cout << "Enter high temperature: ";
        std::cin >> hightemp;
        std::cout << "Enter low temperature: ";
        std::cin >> lowtemp;
        std::cout << "Enter amount of rain: ";
        std::cin >> amount_rain;
        std::cout << "Enter amount of snow: ";
        std::cin >> amount_snow;
    }

    // Function to display the weather report
    void displayReport() const {
        std::cout << "Day of Month: " << day_of_month << std::endl;
        std::cout << "High Temperature: " << hightemp << " degrees Celsius" << std::endl;
        std::cout << "Low Temperature: " << lowtemp << " degrees Celsius" << std::endl;
        std::cout << "Amount of Rain: " << amount_rain << " mm" << std::endl;
        std::cout << "Amount of Snow: " << amount_snow << " mm" << std::endl;
    }

    // Getters for individual attributes
    int getDayOfMonth() const { return day_of_month; }
    double getHighTemp() const { return hightemp; }
    double getLowTemp() const { return lowtemp; }
    double getAmountRain() const { return amount_rain; }
    double getAmountSnow() const { return amount_snow; }
};

// Function to calculate the average of each attribute for a given array of WeatherReport objects
void calculateAverage(const WeatherReport reports[], int size) {
    double avgHighTemp = 0.0, avgLowTemp = 0.0, avgRain = 0.0, avgSnow = 0.0;

    for (int i = 0; i < size; ++i) {
        avgHighTemp += reports[i].getHighTemp();
        avgLowTemp += reports[i].getLowTemp();
        avgRain += reports[i].getAmountRain();
        avgSnow += reports[i].getAmountSnow();
    }

    avgHighTemp /= size;
    avgLowTemp /= size;
    avgRain /= size;
    avgSnow /= size;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average High Temperature: " << avgHighTemp << " degrees Celsius" << std::endl;
    std::cout << "Average Low Temperature: " << avgLowTemp << " degrees Celsius" << std::endl;
    std::cout << "Average Amount of Rain: " << avgRain << " mm" << std::endl;
    std::cout << "Average Amount of Snow: " << avgSnow << " mm" << std::endl;
}

int main() {
    const int MAX_REPORTS = 30; // Maximum number of daily reports for a month
    WeatherReport monthlyReports[MAX_REPORTS];
    int reportCount = 0;

    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Enter Daily Weather Report\n";
        std::cout << "2. Display Monthly Report\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (reportCount < MAX_REPORTS) {
                    monthlyReports[reportCount].inputValues();
                    reportCount++;
                } else {
                    std::cout << "Monthly report is already full!\n";
                }
                break;

            case 2:
                if (reportCount > 0) {
                    calculateAverage(monthlyReports, reportCount);
                } else {
                    std::cout << "No reports entered yet!\n";
                }
                break;

            case 3:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 3);

    return 0;
}

