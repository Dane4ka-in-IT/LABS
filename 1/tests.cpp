#include <gtest/gtest.h>
#include "replace_letters.h"

TEST(ReplaceLettersTest, BasicTest) {
    std::string input = "Vader said: No, I am your father!";
    int n = 2;
    char old_value = 'a';
    char new_value = 'o';
    std::string expected = "Vader soid: No, I am your fother!";

    std::string result = replaceLetters(input, n, old_value, new_value);

    EXPECT_EQ(result, expected);
}

TEST(ReplaceLettersTest, NoReplacement) {
    std::string input = "Hello, World!";
    std::string expected = "Hello, World!";

    std::string result1 = replaceLetters(input, 0, 'o', 'x');
    std::string result2 = replaceLetters(input, -1, 'o', 'x');
    std::string result3 = replaceLetters(input, 5, 'z', 'x');

    EXPECT_EQ(result1, expected);
    EXPECT_EQ(result2, expected);
    EXPECT_EQ(result3, expected);
}

TEST(ReplaceLettersTest, EveryOccurrence) {
    std::string input = "abracadabra";
    int n = 1;
    char old_value = 'a';
    char new_value = 'x';
    std::string expected = "xbrxcxdxbrx";

    std::string result = replaceLetters(input, n, old_value, new_value);

    EXPECT_EQ(result, expected);
}

TEST(ReplaceLettersTest, EveryThirdOccurrence) {
    std::string input = "abracadabra";
    int n = 3;
    char old_value = 'a';
    char new_value = 'x';
    std::string expected = "abracxdabra";

    std::string result = replaceLetters(input, n, old_value, new_value);

    EXPECT_EQ(result, expected);
}

TEST(ReplaceLettersTest, EmptyString) {
    std::string input = "";
    int n = 2;
    char old_value = 'a';
    char new_value = 'b';
    std::string expected = "";

    std::string result = replaceLetters(input, n, old_value, new_value);

    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}