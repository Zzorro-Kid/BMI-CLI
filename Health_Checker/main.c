#include <stdio.h>
#include <string.h>

int main() {

    char name[50];
    char lang[3];
    int age;
    float height, weight;

    printf("Choose language (ru/en): ");
    scanf("%2s", &lang);

    if (strcmp(lang, "en") == 0) {

      printf("Enter your name: ");
      scanf("%s", &name);

      printf("Enter your age: ");
      scanf("%d", &age);

      printf("Enter your height: ");
      scanf("%f", &height);

      printf("Enter your weight: ");
      scanf("%f", &weight);

      int BMI = weight / (height * height);

      if (BMI < 18.5) {
        printf("Status: Underweight\n");

    } else if (BMI >= 18.5 && BMI < 25) {
        printf("Status: Normal\n");

    } else if (BMI >= 25 && BMI < 30) {
        printf("Status: Overweight\n");

    } else if (BMI >= 30) {
        printf("Status: Obesity\n");
    } 

      if (age <= 17 && BMI >= 25) {
        printf("Recommendation: Consult with doctor!");
    }

  }
    
    if (strcmp(lang, "ru") == 0) {

      printf("Введите ваше имя: ");
      scanf("%s", &name);

      printf("Введите ваш возраст: ");
      scanf("%d", &age);

      printf("Введите ваш рост: ");
      scanf("%f", &height);

      printf("Введите ваш вес: ");
      scanf("%f", &weight);

      int BMI = weight / (height * height);

      if (BMI < 18.5) {
        printf("Статус: Недовес\n");

    } else if (BMI >= 18.5 && BMI < 25) {
        printf("Статус: Норма\n");

    } else if (BMI >= 25 && BMI < 30) {
        printf("Статус: Избыточный\n");

    } else if (BMI >= 30) {
        printf("Статус: Ожирение\n");
    } 

      if (age <= 17 && BMI >= 25) {
        printf("Рекомендация: Проконсультируйтесь с доктором!");
    }

  }

  return 0;

}