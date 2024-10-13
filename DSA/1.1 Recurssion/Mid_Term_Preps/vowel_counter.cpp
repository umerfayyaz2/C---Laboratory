#include <iostream>
#include <cctype>
using namespace std;

int vowel_counter(const string &text, int current_index = 0)
{
    if (current_index == text.length())
    {
        return 0;
    }

    char current_char = tolower(text[current_index]);

    bool vowel_checker = (current_char == 'a' || current_char == 'e' || current_char == 'i' || current_char == 'o' || current_char == 'u');

    int total_vowel_counter = vowel_counter(text, current_index + 1);

    return vowel_checker ? total_vowel_counter + 1 : total_vowel_counter;
}