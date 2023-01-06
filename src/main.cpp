#include <iostream>

std::string encrypt_caesar(std::string txt, int k) {
    
    for (int i = 0; i < txt.length(); ++i) {
        
        while (k < 0) {
            k += 26;
        }
       
        if (txt[i] >= 'a' && txt[i] <= 'z') {
            txt[i] = (txt[i] - 97 + k) % 26 + 97;
        }
        else if (txt[i] >= 'A' && txt[i] <= 'Z') {
            txt[i] = (txt[i] - 65 + k) % 26 + 65;
        }
        else if (txt[i] == ' ') {
            txt[i] = ' ';
        }
        else {
            txt[i] = '\0';
        }
    }
    return txt;
}

int main() {
    int key;
    std::string text;

    std::cout << "Hello!\n";
    std::cout << "Do you want to encrypt the text or decrypt it ?\n";
    std::cout << "Answer ('e' or 'd'): ";
    std::getline(std::cin, text);
    
    while (text != "e" and text != "d") {
        std::cout << "\t\terror\n";
        std::cout << "Please try again!\n";
        std::cout << "Do you want to encrypt the text or decrypt it ?\n";
        std::cout << "Answer ('e' or 'd'): ";
        std::getline(std::cin, text);
    }

   
    if (text == "e") {
        std::cout << "\t-------E-N-C-R-Y-P-T-------\n";
        std::cout << "Please input text: ";
        std::getline(std::cin, text);
        std::cout << "Please input key: ";
        std::cin >> key;

        std::cout << "\nYour text - " << text << std::endl;
        std::cout << "Text encrypt - " << encrypt_caesar(text, key) << std::endl;
    }
    else {
        std::cout << "\t-------D-E-C-R-Y-P-T-------\n";
        std::cout << "Please input text: ";
        std::getline(std::cin, text);
        std::cout << "Please input key: ";
        std::cin >> key;

        std::cout << "\nYour text - " << text << std::endl;
        
        std::cout << "Text decrypt - " << encrypt_caesar(text, -key) << std::endl;
    }
}