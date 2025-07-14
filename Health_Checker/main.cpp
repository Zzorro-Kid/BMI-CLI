#include <iostream>
#include <string>

int main() {
    std::string name;
    std::string lang;
    int age;
    float height, weight;

    std::cout << "Choose language (ru/en): ";
    std::cin >> lang;

    if (lang == "en") {
        std::cout << "Enter your name: ";
        std::cin >> name;

        std::cout << "Enter your age: ";
        std::cin >> age;

        std::cout << "Enter your height (in meters): ";
        std::cin >> height;

        std::cout << "Enter your weight (in kg): ";
        std::cin >> weight;

        float BMI = weight / (height * height);

        if (BMI < 18.5) {
            std::cout << "Status: Underweight\n";
        } else if (BMI < 25) {
            std::cout << "Status: Normal\n";
        } else if (BMI < 30) {
            std::cout << "Status: Overweight\n";
        } else {
            std::cout << "Status: Obesity\n";
        }

        if (age <= 17 && BMI >= 25) {
            std::cout << "Recommendation: Consult with doctor!\n";
        }

    } else if (lang == "ru") {
        std::cout << "Введите ваше имя: ";
        std::cin >> name;

        std::cout << "Введите ваш возраст: ";
        std::cin >> age;

        std::cout << "Введите ваш рост (в метрах): ";
        std::cin >> height;

        std::cout << "Введите ваш вес (в кг): ";
        std::cin >> weight;

        float BMI = weight / (height * height);

        if (BMI < 18.5) {
            std::cout << "Статус: Недовес\n";
        } else if (BMI < 25) {
            std::cout << "Статус: Норма\n";
        } else if (BMI < 30) {
            std::cout << "Статус: Избыточный\n";
        } else {
            std::cout << "Статус: Ожирение\n";
        }

        if (age <= 17 && BMI >= 25) {
            std::cout << "Рекомендация: Проконсультируйтесь с доктором!\n";
        }

    } else {
        std::cout << "Unsupported language.\n";
    }

    return 0;
}
