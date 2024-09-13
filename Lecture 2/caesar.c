#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char ronate(char c, int k);

int main(int argc, string argv[])
{
    // 检查程序是否只带有一个命令行参数。
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // 确保这个参数只包含数字
    bool IfIsDigits = (only_digits(argv[1]));
    if (IfIsDigits == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // 将这个参数转换为整数，用于后续的字符旋转。
    int key = atoi(argv[1]);
    // 提示用户输入明文。
    string plaintext = get_string("Plaintext: ");
    // 对明文中的每个字符进行旋转，如果是字母，则根据给定的旋转次数进行旋转。
    printf("ciphertext: ");
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        char c = ronate(plaintext[i], key);
        printf("%c", c);
    }
    printf("\n");
    return 0;
}

bool only_digits(string s)
{
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char ronate(char c, int k)
{
    if (isupper(c))
    {
        char a = ((c - 65 + k) % 26 + 65);
        return a;
    }
    else if (islower(c))
    {
        char b = ((c - 97 + k) % 26 + 97);
        return b;
    }
    else
    {
        return c;
        // 将ASC2转化为字母索引
        // shift 字母索引用公式`ci = (pi + key) %26`
        // shift 结果为ASC2
    }
}
