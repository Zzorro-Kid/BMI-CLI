using System;

namespace HealthCheckerCLI
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Health Check CLI");
            Console.WriteLine("----------------\n");

            var checker = new HealthChecker();
            checker.Run();
            
            Console.WriteLine("\nPress any key to exit...");
            Console.ReadKey();
        }
    }

    public class HealthChecker
    {
        public void Run()
        {
            string? lang = ChooseLanguage();
            
            if (lang == "en")
            {
                ProcessEnglish();
            }
            else if (lang == "ru")
            {
                ProcessRussian();
            }
            else
            {
                Console.WriteLine("Unsupported language.");
            }
        }

        private string? ChooseLanguage()
        {
            Console.Write("Choose language (ru/en): ");
            return Console.ReadLine()?.ToLower();
        }

        private void ProcessEnglish()
        {
            Console.Write("Enter your name: ");
            string? name = Console.ReadLine();

            Console.Write("Enter your age: ");
            if (!int.TryParse(Console.ReadLine(), out int age))
            {
                Console.WriteLine("Invalid age input");
                return;
            }

            Console.Write("Enter your height (in meters): ");
            if (!float.TryParse(Console.ReadLine(), out float height))
            {
                Console.WriteLine("Invalid height input");
                return;
            }

            Console.Write("Enter your weight (in kg): ");
            if (!float.TryParse(Console.ReadLine(), out float weight))
            {
                Console.WriteLine("Invalid weight input");
                return;
            }

            CalculateAndDisplayBMI(age, height, weight, isEnglish: true);
        }

        private void ProcessRussian()
        {
            Console.Write("Введите ваше имя: ");
            string? name = Console.ReadLine();

            Console.Write("Введите ваш возраст: ");
            if (!int.TryParse(Console.ReadLine(), out int age))
            {
                Console.WriteLine("Неверный ввод возраста");
                return;
            }

            Console.Write("Введите ваш рост (в метрах): ");
            if (!float.TryParse(Console.ReadLine(), out float height))
            {
                Console.WriteLine("Неверный ввод роста");
                return;
            }

            Console.Write("Введите ваш вес (в кг): ");
            if (!float.TryParse(Console.ReadLine(), out float weight))
            {
                Console.WriteLine("Неверный ввод веса");
                return;
            }

            CalculateAndDisplayBMI(age, height, weight, isEnglish: false);
        }

        private void CalculateAndDisplayBMI(int age, float height, float weight, bool isEnglish)
        {
            float bmi = weight / (height * height);

            if (isEnglish)
            {
                Console.WriteLine($"\nBMI: {bmi:F1}");
                
                if (bmi < 18.5)
                {
                    Console.WriteLine("Status: Underweight");
                }
                else if (bmi < 25)
                {
                    Console.WriteLine("Status: Normal");
                }
                else if (bmi < 30)
                {
                    Console.WriteLine("Status: Overweight");
                }
                else
                {
                    Console.WriteLine("Status: Obesity");
                }

                if (age <= 17 && bmi >= 25)
                {
                    Console.WriteLine("Recommendation: Consult with doctor!");
                }
            }
            else
            {
                Console.WriteLine($"\nИМТ: {bmi:F1}");
                
                if (bmi < 18.5)
                {
                    Console.WriteLine("Статус: Недовес");
                }
                else if (bmi < 25)
                {
                    Console.WriteLine("Статус: Норма");
                }
                else if (bmi < 30)
                {
                    Console.WriteLine("Статус: Избыточный");
                }
                else
                {
                    Console.WriteLine("Статус: Ожирение");
                }

                if (age <= 17 && bmi >= 25)
                {
                    Console.WriteLine("Рекомендация: Проконсультируйтесь с доктором!");
                }
            }
        }
    }
}