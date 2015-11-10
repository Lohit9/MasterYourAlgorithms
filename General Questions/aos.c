#include "aos.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <assert.h>

char *my_strdup(const char *s) {
    
    char *new = malloc (sizeof(char) * (strlen(s)+1));
    strcpy(new,s);
    return new;
    

}

struct aos *create_aos(int max) {
    assert(max > 0);
    int bytes1= sizeof (struct aos);
    int bytes2= sizeof(char *) * max;
    struct aos *ret = malloc(bytes1);
    ret->strings = malloc(bytes2);
    for(int i = 0; i < max; i++)
        ret->strings[i] = NULL;
    ret->max = max;
    return ret;
}

void destroy_aos(struct aos *a) {
    for(int i = 0; i < a->max; i++)
        free(a->strings[i]);
    free(a->strings);
    free(a);
    return;
}

int aos_count(struct aos *a) {
    assert(a != NULL);
    int cnt = 0;
    for(int i = 0; i < a->max; i++)
        if(a->strings[i] != NULL)
            cnt++;
    return cnt;
}

char *aos_get(struct aos *a, int i) {
    assert(a != NULL);
    if(i < 0 || i >= a->max) return NULL;
    return a->strings[i];
}

void aos_set(struct aos *a, const char *s, int i) {
    //assert(i == 5);
    assert(a != NULL);
    assert(0 <= i && i < a->max);
    if(a->strings[i] != NULL)
        free(a->strings[i]);
    if(s == NULL) return;
    a->strings[i] = my_strdup(s);
    return;
}

   aos_add(struct aos *a, const char *s) {
    assert(a != NULL);
    assert(s != NULL);
    int k = 0;
    while(k < a->max && a->strings[k] != NULL) k++;
    if(k == a->max) return -1;
    aos_set(a, s, k);
    return k;
}

int my_strcmp(char *a, char *b) {
    if(a == b) return 0;
    if(b == NULL) return -1;
    if(a == NULL) return 1;
    return strcmp(a, b);
}

void aos_sort(struct aos *a) {
    assert(a != NULL);
    int len = 0;
    //while(len < a->max && a->strings[len] != NULL) len++;--> this is redundant
    bool swapped = true;
    while(swapped) {
        swapped = false;
        for(int i = 0; i < a->max; i++) {
            for(int j = i+1; j < a->max; j++) {
                if(my_strcmp(a->strings[i], a->strings[j]) == 1) {
                    char *temp = a->strings[i];
                    a->strings[i] = a->strings[j];
                    a->strings[j] = temp;
                    swapped = true;
                }
            }
        }
    }
    return;
}
// Below are a few tests, these are not rigourous!
int main()
{
struct aos *a = create_aos(10);
assert(aos_get(a,5) == NULL);
aos_set(a,"apple",5);
assert(strcmp(aos_get(a,5),"apple") == 0);
assert(aos_add(a,"zebra") == 0);
printf("%s\n",aos_get(a,0));
printf("%s\n",aos_get(a,1));
aos_sort(a);
//printf("%s\n",aos_get(a,0));
//printf("%s\n",aos_get(a,1));
printf("%s\n",aos_get(a,5));
assert(strcmp(aos_get(a,0),"apple") == 0);
assert(strcmp(aos_get(a,1),"zebra") == 0);
destroy_aos(a);
}
