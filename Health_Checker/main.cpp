#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class HealthChecker {
public:
    void Run() {
        std::string lang = ChooseLanguage();
        
        if (lang == "en") {
            ProcessEnglish();
        }
        else if (lang == "ru") {
            ProcessRussian();
        }
        else {
            std::cout << "Unsupported language.\n";
        }
    }

private:
    std::string ChooseLanguage() {
        std::cout << "Choose language (ru/en): ";
        std::string input;
        std::getline(std::cin, input);
        
        for (char &c : input) {
            c = tolower(c);
        }
        
        return input;
    }

    void ProcessEnglish() {
        std::string name;
        int age;
        float height, weight;

        std::cout << "Enter your name: ";
        std::getline(std::cin, name);

        age = GetValidNumber<int>("Enter your age: ", "Invalid age input");
        height = GetValidNumber<float>("Enter your height (in meters): ", "Invalid height input");
        weight = GetValidNumber<float>("Enter your weight (in kg): ", "Invalid weight input");

        CalculateAndDisplayBMI(age, height, weight, true);
    }

    void ProcessRussian() {
        std::string name;
        int age;
        float height, weight;

        std::cout << "Введите ваше имя: ";
        std::getline(std::cin, name);

        age = GetValidNumber<int>("Введите ваш возраст: ", "Неверный ввод возраста");
        height = GetValidNumber<float>("Введите ваш рост (в метрах): ", "Неверный ввод роста");
        weight = GetValidNumber<float>("Введите ваш вес (в кг): ", "Неверный ввод веса");

        CalculateAndDisplayBMI(age, height, weight, false);
    }

    template<typename T>
    T GetValidNumber(const std::string& prompt, const std::string& errorMessage) {
        T value;
        while (true) {
            std::cout << prompt;
            std::cin >> value;
            
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << errorMessage << std::endl;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            }
        }
    }

    void CalculateAndDisplayBMI(int age, float height, float weight, bool isEnglish) {
        float bmi = weight / (height * height);

        if (isEnglish) {
            std::cout << "\nBMI: " << std::fixed << std::setprecision(1) << bmi << std::endl;
            
            if (bmi < 18.5) {
                std::cout << "Status: Underweight\n";
            }
            else if (bmi < 25) {
                std::cout << "Status: Normal\n";
            }
            else if (bmi < 30) {
                std::cout << "Status: Overweight\n";
            }
            else {
                std::cout << "Status: Obesity\n";
            }

            if (age <= 17 && bmi >= 25) {
                std::cout << "Recommendation: Consult with doctor!\n";
            }
        }
        else {
            std::cout << "\nИМТ: " << std::fixed << std::setprecision(1) << bmi << std::endl;
            
            if (bmi < 18.5) {
                std::cout << "Статус: Недовес\n";
            }
            else if (bmi < 25) {
                std::cout << "Статус: Норма\n";
            }
            else if (bmi < 30) {
                std::cout << "Статус: Избыточный\n";
            }
            else {
                std::cout << "Статус: Ожирение\n";
            }

            if (age <= 17 && bmi >= 25) {
                std::cout << "Рекомендация: Проконсультируйтесь с доктором!\n";
            }
        }
    }
};

int main() {
    std::cout << "Health Check CLI\n";
    std::cout << "----------------\n\n";

    HealthChecker checker;
    checker.Run();
    
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}