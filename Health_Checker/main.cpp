#include <iostream>
#include <string>
#include "func.h"

int main() {

    display_big_bmi_art();

    char lang = choose_language();

    if (lang == 'e') {
        process_english();
    } else if (lang == 'r') {
        process_russian();
    } else {
        std::cout << "Unsupported language";
    }

    std::cout << std::endl << "Press Enter to exit...";
    std::cin.ignore();


    return 0;
}
