#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {

    if(numRows == 1)
        return s;
    
    struct Node {
        char ch;
        struct Node *next;
    };
    
    struct Node *Head = malloc(sizeof(struct Node) * numRows);
    struct Node **current = malloc(sizeof(struct Node*) * numRows);
    struct Node *ptr;
    int len = strlen(s);
    int i, j, flag = 1;

    for(i = 0; i < numRows; i++) {
        Head[i].next = NULL;
        current[i] = &Head[i];
    }

    for( i = 0, j = 0; i < len; i++ ) {
        ptr = malloc(sizeof(struct Node));
        ptr->ch = s[i];
        ptr->next = NULL;
        current[j]->next = ptr;
        current[j] = ptr;

        /*一开始j自减,向下扫描,到底后再自增向上扫描字符串,然后循环*/
        j += flag;
        if( j == numRows  || j == -1) {
            flag = -flag;
            j += flag*2;
        }

    }

    /*将各行元素依次写回s*/
    for(j = 0, i = 0; i < numRows; i++ ) {
        ptr = &Head[i];
        while( ptr->next != NULL ) {
            s[j++] = ptr->next->ch;
            ptr = ptr->next;
        }
    }

    /*释放内存*/
    struct Node *tmp;
    for( i = 0; i < numRows; i++ ) {
        
        ptr = Head[i].next;
        while( ptr != NULL ) {
            tmp = ptr->next;
            free(ptr);
            ptr = tmp;
        }
    }
    free(Head);
    free(current);
    return s;
}

int main()
{
    char str[] = "AB";
    char *ch = convert(str, 1);
    printf("%s\n", ch);
    return 0;
}
