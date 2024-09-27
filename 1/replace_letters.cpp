#include <string>  

std::string replaceLetters(const std::string& text, int n, char old_value, char new_value) {  
    if (n <= 0) {  
        return text;  
    }

    std::string result = text; 
    int count = 0;  

    for (size_t i = 0; i < result.length(); ++i) { 
        if (result[i] == old_value) {  
            ++count;  
            if (count % n == 0) {  
                result[i] = new_value;  
            }
        }
    }

    return result;  
}