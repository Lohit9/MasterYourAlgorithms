#include <iostream>
#include <string>
using namespace std;

void reverse(char* str)
{
    char *ptrEnd = str;
    char temp;

    if (str)
    {
        while (*ptrEnd)
        {
            ptrEnd++;
        }
        ptrEnd--;

        while (str < ptrEnd)
        {
            temp = *str;
            *str++ = *ptrEnd;
            *ptrEnd-- = temp;
        }
    }
}

int main()
{
  return 0;
}
