#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iomanip>
#include <cctype>

void pressEnterToContinue() {
    char c;
    std::cout << "Press Enter to continue...";
    std::cin.ignore(1024, '\n');
    do { std::cin.get(c); } while (c != '\n' && c != EOF);
}

int main() {
    std::string fileName;
    std::cout << "Enter filename: ";
    std::cin >> fileName;

    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file. Make sure the file is in the correct directory.\n";
        return 1;
    }

    std::unordered_map<char, int> frequencyMap;
    int totalLetters = 0;
    char c;
    while (file >> std::noskipws >> c) {
        if (std::isalpha(c)) {
            c = std::tolower(c); // Convert to lowercase
            frequencyMap[c]++;
            totalLetters++;
        }
    }

    file.close();
    std::cout << "Total number of letters: " << totalLetters << '\n';
    std::cout << "Frequency:\n";
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        char lowercaseLetter = std::tolower(letter);
        int count = frequencyMap[lowercaseLetter];
        if (count > 0) {
            double frequency = static_cast<double>(count) / totalLetters * 100.0;
            std::cout << "'" << letter << "'" << ": " << std::fixed << std::setprecision(3) << frequency << '\n';
        }
    }

    //std::cout << "Total number of letters: " << totalLetters << '\n';

    pressEnterToContinue();
    return 0;
}

