#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int Coleman_Liau_index(string text);

int main(void)
{
    string text = get_string("Text: ");
    int index = Coleman_Liau_index(text);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    // Return the number of letters in text
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text)
{
    // Return the number of words in text
    int words = 1;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    return words;
}
// if there are 'n' spaces,there are (n + 1) words in crentain sentence.

int count_sentences(string text)
{
    // suppose any sentences end with \? \. \!
    int sentences = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}

// Compute the Coleman-Liau index
// L
// 代表文本中每100个单词的平均字母数。这是通过将文本中的字母总数除以单词总数，然后乘以100来计算的。
// S 代表文本中每100个单词的平均句子数。这通过将文本中的句子总数除以单词总数，然后乘以100来计算。
int Coleman_Liau_index(string text)
{
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = ((float) letters / words * 100);
    float S = ((float) sentences / words * 100);
    int index = round((float) 0.0588 * L - 0.296 * S - 15.8);
    return index;
}
