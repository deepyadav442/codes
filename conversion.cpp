#include <bits/stdc++.h>
void convert_to_words(char *num)
{
    int len = strlen(num);  // Get number of digits in given number
    char *single_digits[] = { "zero", "one", "two", "three", "four",
                              "five", "six", "seven", "eight", "nine"};
    char *two_digits[] = {"", "ten", "eleven", "twelve", "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *tens_multiple[] = {"", "", "twenty", "thirty", "forty", "fifty",
                             "sixty", "seventy", "eighty", "ninety"};

    char *tens_power[] = {"hundred", "thousand"};


    /* For single digit number */
    if (len == 1) {
        printf("%s\n", single_digits[*num - '0']);
        return;
    }

     /* Iterate while num is not '\0' */
     while (*num != '\0') {

            {
            if (*num == '1') {
                int sum = *num - '0' + *(num + 1)- '0';
                printf("%s\n", two_digits[sum]);
                return;
            }
            else if (*num == '2' && *(num + 1) == '0') {
                printf("twenty\n");
                return;
            }

            /* Rest of the two digit numbers i.e., 21 to 99 */
            else {
                int i = *num - '0';
                printf("%s", i? tens_multiple[i]: "");
                ++num;
                if (*num != '0')
                    printf("-%s", single_digits[*num - '0']);
                printf("\n");

            }
        }
        ++num;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    char s[101];
    scanf("%s",s);
    convert_to_words(s);
    //convert_to_words("89");
    }
    return 0;
}
