#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char choose_language();
void process_english();
void process_russian();
float get_valid_float(const char* prompt, const char* error_message);
int get_valid_int(const char* prompt, const char* error_message);
void calculate_and_display_bmi(int age, float height, float weight, bool is_english);

int main() {
    printf("Health Check CLI\n");
    printf("----------------\n\n");

    char lang = choose_language();
    
    if (lang == 'e') {
        process_english();
    }
    else if (lang == 'r') {
        process_russian();
    }
    else {
        printf("Unsupported language.\n");
    }
    
    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}

char choose_language() {
    printf("Choose language (r/e): ");
    char input[10];
    fgets(input, sizeof(input), stdin);
    

    char lang = tolower(input[0]);
    return lang;
}

void process_english() {
    char name[100];
    int age;
    float height, weight;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; 

    age = get_valid_int("Enter your age: ", "Invalid age input");
    height = get_valid_float("Enter your height (in meters): ", "Invalid height input");
    weight = get_valid_float("Enter your weight (in kg): ", "Invalid weight input");

    calculate_and_display_bmi(age, height, weight, true);
}

void process_russian() {
    char name[100];
    int age;
    float height, weight;

    printf("Введите ваше имя: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; 

    age = get_valid_int("Введите ваш возраст: ", "Неверный ввод возраста");
    height = get_valid_float("Введите ваш рост (в метрах): ", "Неверный ввод роста");
    weight = get_valid_float("Введите ваш вес (в кг): ", "Неверный ввод веса");

    calculate_and_display_bmi(age, height, weight, false);
}

float get_valid_float(const char* prompt, const char* error_message) {
    float value;
    char buffer[100];
    
    while (1) {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        
        if (sscanf(buffer, "%f", &value) == 1) {
            return value;
        }
        printf("%s\n", error_message);
    }
}

int get_valid_int(const char* prompt, const char* error_message) {
    int value;
    char buffer[100];
    
    while (1) {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        
        if (sscanf(buffer, "%d", &value) == 1) {
            return value;
        }
        printf("%s\n", error_message);
    }
}

void calculate_and_display_bmi(int age, float height, float weight, bool is_english) {
    float bmi = weight / (height * height);

    if (is_english) {
        printf("\nBMI: %.1f\n", bmi);
        
        if (bmi < 18.5) {
            printf("Status: Underweight\n");
        }
        else if (bmi < 25) {
            printf("Status: Normal\n");
        }
        else if (bmi < 30) {
            printf("Status: Overweight\n");
        }
        else {
            printf("Status: Obesity\n");
        }

        if (age <= 17 && bmi >= 25) {
            printf("Recommendation: Consult with doctor!\n");
        }
    }
    else {
        printf("\nИМТ: %.1f\n", bmi);
        
        if (bmi < 18.5) {
            printf("Статус: Недовес\n");
        }
        else if (bmi < 25) {
            printf("Статус: Норма\n");
        }
        else if (bmi < 30) {
            printf("Статус: Избыточный\n");
        }
        else {
            printf("Статус: Ожирение\n");
        }

        if (age <= 17 && bmi >= 25) {
            printf("Рекомендация: Проконсультируйтесь с доктором!\n");
        }
    }
}
