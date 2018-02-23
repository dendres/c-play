#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>

typedef struct Pair Pair;

struct Pair {
        char* first;
        char* snd;
};


Pair **partlist(char **arr, int sz)
{
        /* int i, j; */
        Pair **out = malloc((long unsigned int)(sz - 1) * sizeof(*out));

        /*
        for (i = 0; i < (sz - 1); i++) {
                for( j = 0; j < i; j++) {
                        out[i] = malloc(sizeof(Pair));
                        out[i]->first = strcat(out[i]->first, arr[j]);
                }
                for (j = i; j < (sz - 1); j++) {
                        out[i] = malloc(sizeof(Pair));
                        out[i]->snd = strcat(out[i]->snd, arr[i]);
                }
        }
        */
        return out;
}




void print_pair(Pair *p)
{
        printf("{%s,%s}", p->first, p->snd);
}


void print_pair_list(Pair **arr, int sz)
{
        int i;
        for(i = 0; i < sz; i++){
                printf("{%s,%s}", arr[i]->first, arr[i]->snd);
        }
        printf("\n");
}


int main()
{
        /*
        Pair **pairs = malloc(3 * sizeof(*pairs));


        printf("s[0] = %s\n", s[0]);

        pairs[0] = malloc(sizeof(Pair));
        pairs[1] = malloc(sizeof(Pair));
        pairs[2] = malloc(sizeof(Pair));
        pairs[0]->first = "a";
        pairs[0]->snd = "b";

        print_pair_list(pairs, 3);
        */

        Pair **result;
        char* s[4] = {"cdIw", "tzIy", "xDu", "rThG"};
        result = partlist(s, 4);

        print_pair_list(result, 3);

        return 0;
}



/*
void dotest(char** arr, int sz, char *expr) {
        Pair** act = partlist(arr, sz);
        char* sact = array2StringData(act, sz - 1);
        if(strcmp(sact, expr) != 0)
                printf("partList. Error. Expected \n%s\n but got \n%s\n", expr, sact);
        cr_assert_str_eq(sact, expr, "");
        free(sact); sact = NULL;
}

Test(partList, ShouldPassAllTheTestsProvided) {
        {
                char* s[4] = {"cdIw", "tzIy", "xDu", "rThG"};
                char* sol = "{{cdIw, tzIy xDu rThG}{cdIw tzIy, xDu rThG}{cdIw tzIy xDu, rThG}}";
                dotest(s, 4, sol);
        }
        {
                char* s[5] = {"I", "wish", "I", "hadn't", "come"};
                char* sol = "{{I, wish I hadn't come}{I wish, I hadn't come}{I wish I, hadn't come}{I wish I hadn't, come}}";
                dotest(s, 5, sol);
        }
        {
                char* s[4] = {"vJQ", "anj", "mQDq", "sOZ"};
                char* sol = "{{vJQ, anj mQDq sOZ}{vJQ anj, mQDq sOZ}{vJQ anj mQDq, sOZ}}";
                dotest(s, 4, sol);
        }
}

*/
