#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>


struct Node {


    int data;

    struct Node* nxp;
};


struct Node* XOR(struct Node* a, struct Node* b)
{
    return (struct Node*)((uintptr_t)(a)
                          ^ (uintptr_t)(b));
}


struct Node* insert(struct Node** head, int value)
{
   
    if (*head == NULL) {

       
        struct Node* node
            = (struct Node*)malloc(
                sizeof(struct Node));

      
        node->data = value;

        node->nxp = XOR(NULL, NULL);

        *head = node;
    }

   
    else {

        struct Node* curr = *head;

        struct Node* prev = NULL;

        struct Node* node
            = (struct Node*)malloc(
                sizeof(struct Node));

        curr->nxp = XOR(node,
                        XOR(NULL, curr->nxp));


        node->nxp = XOR(NULL, curr);


        *head = node;


        node->data = value;
    }
    return *head;
}

void printList(struct Node** head)
{

    struct Node* curr = *head;


    struct Node* prev = NULL;


    struct Node* next;


    while (curr != NULL) {


        printf("%d ", curr->data);

        next = XOR(prev, curr->nxp);


        prev = curr;

        curr = next;
    }
}


struct Node* delEnd(struct Node** head)
{
    // Base condition
    if (*head == NULL)
        printf("List is empty");
    else {


        struct Node* curr = *head;


        struct Node* prev = NULL;


        struct Node* next;


        while (XOR(curr->nxp, prev) != NULL) {


            next = XOR(prev, curr->nxp);


            prev = curr;


            curr = next;
        }

        if (prev != NULL)
            prev->nxp = XOR(XOR(prev->nxp, curr), NULL);


        else
            *head = NULL;


        free(curr);
    }


    return *head;
}


int main()
{
	struct Node* head = NULL;
	int ch,key;
	while(1)
    {
        printf("\n1.INSERT\n2.DELETE FROM END\n3.PRINT\n4.EXIT\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the elements: ");
                scanf("%d",&key);
                insert(&head,key);
                break;
            case 2:
                delEnd(&head);
                if (head == NULL)
                printf("List is empty");
                break;
            case 3:
                printList(&head);
                printf("\n");
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid input");
        }

    }
return(0);
}
