#include <iostream>
#include <string>

char choose_language();
void process_english();
void process_russian();
void calculate_and_display_bmi(uint age, float height, float weight, bool is_english);
void display_big_bmi_art();


void display_big_bmi_art() {
    std::cout << R"(
 _               _                 _            _       _             
| |__  _ __ ___ (_)       ___ __ _| | ___ _   _| | __ _| |_ ___  _ __ 
| '_ \| '_ ` _ \| |_____ / __/ _` | |/ __| | | | |/ _` | __/ _ \| '__|
| |_) | | | | | | |_____| (_| (_| | | (__| |_| | | (_| | || (_) | |   
|_.__/|_| |_| |_|_|      \___\__,_|_|\___|\__,_|_|\__,_|\__\___/|_|
    
)" << std::endl;
}

char choose_language() {

    char input;
    std::cout << "Choose language (r/e): ";
    std::cin >> input;
    
    return input;
}

void process_english() {

    char name[70];
    uint age;
    float height;
    float weight;

    
    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Enter your age: ";
    std::cin >> age;
    
    std::cout << "Enter your height: ";
    std::cin >> height;

    std::cout << "Enter your weight: ";
    std::cin >> weight;

    calculate_and_display_bmi(age, height, weight, true);
 
}

void process_russian() {

    char name[70];
    uint age;
    float height;
    float weight;

    
    std::cout << "Введите ваше имя: ";
    std::cin >> name;

    std::cout << "Введите ваше возраст: ";
    std::cin >> age;
    
    std::cout << "Введите ваш рост: ";
    std::cin >> height;

    std::cout << "Введите ваш вес: ";
    std::cin >> weight;

    calculate_and_display_bmi(age, height, weight, false);
    
}

void calculate_and_display_bmi(uint age, float height, float weight, bool is_english) {

    float bmi = weight / (height * height);
    
    if (is_english) {
        std::cout << "BMI: " << bmi << std::endl;

    if (bmi < 18.5) {
            std::cout << "Status: Underweight" << std::endl;
        } else if (bmi < 25) {
            std::cout << "Status: Normal" << std::endl;
        } else if (bmi < 30) {
            std::cout << "Status: Overweight" << std::endl;
        } else {
            std::cout << "Status: Obesity" << std::endl;
        }

    } else {
        std::cout << "ИМТ: " << bmi << std::endl;

    if (bmi < 18.5) {
            std::cout << "Статус: Ожирение" << std::endl;
        } else if (bmi < 25) {
            std::cout << "Статус: Избыточный вес" << std::endl;
        } else if (bmi < 30) {
            std::cout << "Статус: Нормальный" << std::endl;
        } else {
            std::cout << "Статус: Нормальный" << std::endl;
        }
    }
}