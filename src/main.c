#include <stdio.h>
#include <stdlib.h>

int main(void) {
    typedef struct node {
        signed int data;
        struct node *next;
    } NODE;
    typedef struct list {
        NODE *head;
    } LIST;

    //リストの作成
    LIST new_list(void) {
        //head -> NULL
        LIST new_list = {NULL};
        return new_list;
    }

    //要素の追加
    LIST append_list(signed int num, LIST list) {
        NODE *new_node = (NODE *)malloc(sizeof(NODE));
        if (list.head == NULL) {
            new_node->data = num;
            new_node->next = NULL;
            list.head = new_node;
        } else {
            new_node->data = num;
            new_node->next = list.head;
            list.head = new_node;
        }
        return list;
    }

    //リストの表示
    void print_list(LIST list) {
        //最後尾のアドレスを代入
        struct node *ptr = list.head;
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            //一つ前のノードのアドレスを代入
            ptr=ptr->next;
        }
        printf("NULL\n");
    }

    LIST sample_list = new_list();
    sample_list = append_list(1, sample_list);
    sample_list = append_list(2, sample_list);
    sample_list = append_list(-1, sample_list);
    sample_list = append_list(-10, sample_list);
    sample_list = append_list(-10, sample_list);
    print_list(sample_list);
    return 0;
}
