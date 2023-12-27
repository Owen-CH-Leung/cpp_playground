#include "src/custom_string.h"
#include "gtest/gtest.h"

TEST(CustomString, DefaultConstructor) {
    CustomString custom_str;
    ASSERT_EQ(custom_str.size(), 0);
    ASSERT_STREQ(custom_str.c_str(), nullptr);
    ASSERT_TRUE(custom_str.IsEmpty());
}

TEST(CustomString, StringConstructor) {
    string str("Hello World");
    CustomString custom_str(str);
    ASSERT_EQ(custom_str.size(), 11);
    ASSERT_STREQ(custom_str.c_str(), "Hello World");
    ASSERT_EQ(str.size(), 11);
    ASSERT_STREQ(str.c_str(), "Hello World");
}

TEST(CustomString, CStringConstructor) {
    CustomString custom_str("Goodbye World");
    ASSERT_EQ(custom_str.size(), 13);
    ASSERT_STREQ(custom_str.c_str(), "Goodbye World");
}

TEST(CustomString, StringMoveConstructor) {
    string str("Test Test");
    CustomString custom_str(move(str));
    ASSERT_EQ(custom_str.size(), 9);
    ASSERT_STREQ(custom_str.c_str(), "Test Test");
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), "");
}

TEST(CustomString, CustomStringConstructor) {
    CustomString custom_str1("MyCustomString");
    CustomString custom_str2(custom_str1);
    ASSERT_EQ(custom_str2.size(), 14);
    ASSERT_STREQ(custom_str2.c_str(), "MyCustomString");
    ASSERT_EQ(custom_str1.size(), 14);
    ASSERT_STREQ(custom_str1.c_str(), "MyCustomString");
}

TEST(CustomString, CustomStringMoveConstructor) {
    CustomString custom_str1("MyCustomString");
    CustomString custom_str2(move(custom_str1));
    ASSERT_EQ(custom_str2.size(), 14);
    ASSERT_STREQ(custom_str2.c_str(), "MyCustomString");
    ASSERT_EQ(custom_str1.size(), 0);
    ASSERT_STREQ(custom_str1.c_str(), nullptr);
    ASSERT_TRUE(custom_str1.IsEmpty());

}

TEST(CustomString, CustomStringCopyAssignmentConstructor) {
    CustomString custom_str1("ABCDEF");
    CustomString custom_str2;
    custom_str2 = custom_str1;
    ASSERT_EQ(custom_str2.size(), 6);
    ASSERT_STREQ(custom_str2.c_str(), "ABCDEF");
    ASSERT_EQ(custom_str1.size(), 6);
    ASSERT_STREQ(custom_str1.c_str(), "ABCDEF");
    ASSERT_FALSE(custom_str1.IsEmpty());
}

TEST(CustomString, CustomStringMoveAssignmentConstructor) {
    CustomString custom_str1("XYZ");
    CustomString custom_str2;
    custom_str2 = move(custom_str1);
    ASSERT_EQ(custom_str2.size(), 3);
    ASSERT_STREQ(custom_str2.c_str(), "XYZ");
    ASSERT_EQ(custom_str1.size(), 0);
    ASSERT_STREQ(custom_str1.c_str(), nullptr);
    ASSERT_TRUE(custom_str1.IsEmpty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}