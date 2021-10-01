/* Program of single linked list*/
// @its-kumar

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node* link;
};
typedef struct Node node;
node* start = NULL;

void create_list();
void display();
void count();
void search(int data);
void addatbeg(int data);
void addatend(int data);
void addafter(int data, int item);
void addbefore(int data, int item);
void addatpos(int data, int pos);
void del(int data);
void reverse();

main() {
    int choice, data, item, pos;

    while (1) {
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Search\n");
        printf("5.Add to empty list / Add at beginning\n");
        printf("6.Add at end\n");
        printf("7.Add after node\n");
        printf("8.Add before node\n");
        printf("9.Add at position\n");
        printf("10.Delete\n");
        printf("11.Reverse\n");
        printf("12.Quit\n\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n\n");

        switch (choice) {
        case 1:
            create_list();
            break;
        case 2:
            display();
            break;
        case 3:
            count();
            break;
        case 4:
            printf("Enter the element to be searched : ");
            scanf("%d", &data);
            search(data);
            break;
        case 5:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            addatbeg(data);
            break;
        case 6:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            addatend(data);
            break;
        case 7:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element after which to insert : ");
            scanf("%d", &item);
            addafter(data, item);
            break;
        case 8:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element before which to insert : ");
            scanf("%d", &item);
            addbefore(data, item);
            break;
        case 9:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the position at which to insert : ");
            scanf("%d", &pos);
            addatpos(data, pos);
            break;
        case 10:
            printf("Enter the element to be deleted : ");
            scanf("%d", &data);
            del(data);
            break;
        case 11:
            reverse();
            break;
        case 12:
            exit(1);
        default:
            printf("Wrong choice\n");
        } /*End of switch */
    }	  /*End of while */
} /*End of main()*/

void create_list() {
    int i, n, data;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    if (n == 0)
        return;

    printf("Enter the element to be inserted : ");
    scanf("%d", &data);
    addatbeg(data);

    for (i = 2; i <= n; i++) {
        printf("Enter the element to be inserted : ");
        scanf("%d", &data);
        addatend(data);
    }
    return;
} /*End of create_list()*/

void display() {
    node* p;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    p = start;
    printf("List is :\n");
    while (p != NULL) {
        printf("%d -> ", p->info);
        p = p->link;
    }
    printf("\n\n");
} /*End of display() */

void count() {
    node* p;
    int cnt = 0;
    p = start;
    while (p != NULL) {
        p = p->link;
        cnt++;
    }
    printf("Number of elements are %d\n", cnt);
} /*End of count() */

void search(int item) {
    node* p = start;
    int pos = 1;
    while (p != NULL) {
        if (p->info == item) {
            printf("Item %d found at position %d\n", item, pos);
            return;
        }
        p = p->link;
        pos++;
    }
    printf("Item %d not found in list\n", item);
} /*End of search()*/

void addatbeg(int data) {
    node* tmp;
    tmp = (node*)malloc(sizeof(node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
    return;
} /*End of addatbeg()*/

void addatend(int data) {
    node* p, * tmp;
    tmp = (node*)malloc(sizeof(node));
    tmp->info = data;
    p = start;
    while (p->link != NULL)
        p = p->link;
    p->link = tmp;
    tmp->link = NULL;
    return;
} /*End of addatend()*/

void addafter(int data, int item) {
    node* tmp, * p;
    p = start;
    while (p != NULL) {
        if (p->info == item) {
            tmp = (node*)malloc(sizeof(node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;
    }
    printf("%d not present in the list\n", item);
    return start;
} /*End of addafter()*/

void addbefore(int data, int item) {
    node* tmp, * p;
    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }
    /*If data to be inserted before first node*/
    if (item == start->info) {
        tmp = (node*)malloc(sizeof(node));
        tmp->info = data;
        tmp->link = start;
        start = tmp;
        return start;
    }
    p = start;
    while (p->link != NULL) {
        if (p->link->info == item) {
            tmp = (node*)malloc(sizeof(node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;
    }
    printf("%d not present in the list\n", item);
    return start;
} /*End of addbefore()*/

void addatpos(int data, int pos) {
    node* tmp, * p;
    int i;
    tmp = (node*)malloc(sizeof(node));
    tmp->info = data;
    if (pos == 1) {
        tmp->link = start;
        start = tmp;
        return start;
    }
    p = start;
    for (i = 1; i < pos - 1 && p != NULL; i++)
        p = p->link;
    if (p == NULL)
        printf("There are less than %d elements\n", pos);
    else {
        tmp->link = p->link;
        p->link = tmp;
    }
    return start;
} /*End of addatpos()*/

void del(int data) {
    node* tmp, * p;
    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }
    /*Deletion of first node*/
    if (start->info == data) {
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }
    /*Deletion in between or at the end*/
    p = start;
    while (p->link != NULL) {
        if (p->link->info == data) {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return start;
        }
        p = p->link;
    }
    printf("Element %d not found\n", data);
    return start;
} /*End of del()*/

void reverse() {
    node* prev, * ptr, * next;
    prev = NULL;
    ptr = start;
    while (ptr != NULL) {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }
    start = prev;
    return start;
} /*End of reverse()*/
