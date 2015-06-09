// Next Fibonacci

#include <stdio.h>

int first=1;
int second=1;
int flag=1;

int next_fib(void) {
    if (flag<=2)
    {
           flag++;
        return 1;}
  int fib = first+second;
    first =second;
    second = fib;
    return fib;

}

/*int main()
{
    printf("%d",next_fib());
    printf("%d",next_fib());
    printf("%d",next_fib());
    printf("%d",next_fib());
    printf("%d",next_fib());
}*/