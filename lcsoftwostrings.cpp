#include<bits/stdc++.h>
using namespace std;
typedef long int ll;
string lcs(string[] strings)
{
    if (strings.length() == 0)
        return "";
    if (strings.length() == 1)
        return strings[0];
    int max = -1;
    int cacheSize = 1;
    for (int i = 0; i < strings.Length; i++)
    {
        cacheSize *= strings[i].length();
        if (strings[i].length() > max)
            max = strings[i].length();
    }
    string[] cache = new string[cacheSize];
    int[] indexes = new int[strings.Length];
    for (int i = 0; i < indexes.Length; i++)
        indexes[i] = strings[i].Length - 1;
    return lcsBack(strings, indexes, cache);
}
string lcsBack(string[] strings, int[] indexes, string[] cache)
{
    for (int i = 0; i < indexes.Length; i++ )
        if (indexes[i] == -1)
            return "";
    bool match = true;
    for (int i = 1; i < indexes.Length; i++)
    {
        if (strings[0][indexes[0]] != strings[i][indexes[i]])
        {
            match = false;
            break;
        }
    }
    if (match)
    {
        int[] newIndexes = new int[indexes.Length];
        for (int i = 0; i < indexes.Length; i++)
            newIndexes[i] = indexes[i] - 1;
        string result = lcsBack(strings, newIndexes, cache) + strings[0][indexes[0]];
        cache[calcCachePos(indexes, strings)] = result;
        return result;
    }
    else
    {
        string[] subStrings = new string[strings.Length];
        for (int i = 0; i < strings.Length; i++)
        {
            if (indexes[i] <= 0)
                subStrings[i] = "";
            else
            {
                int[] newIndexes = new int[indexes.Length];
                for (int j = 0; j < indexes.Length; j++)
                    newIndexes[j] = indexes[j];
                newIndexes[i]--;
                int cachePos = calcCachePos(newIndexes, strings);
                if (cache[cachePos] == null)
                    subStrings[i] = lcsBack(strings, newIndexes, cache);
                else
                    subStrings[i] = cache[cachePos];
            }
        }
        string longestString = "";
        int longestLength = 0;
        for (int i = 0; i < subStrings.Length; i++)
        {
            if (subStrings[i].Length > longestLength)
            {
                longestString = subStrings[i];
                longestLength = longestString.length();
            }
        }
         longestString=cache[calcCachePos(indexes, strings)];
        return longestString;
    }
}
int calcCachePos(int[] indexes, string[] strings)
{
    int factor = 1;
    int pos = 0;
    for (int i = 0; i < indexes.Length; i++)
    {
        pos += indexes[i] * factor;
        factor *= strings[i].Length;
    }
    return pos;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scnaf();
    }
    return 0;
}
