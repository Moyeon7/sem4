#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

struct Node {
    int frequency;
    char character;
    struct Node *next, *left, *right;
};

struct Node *start = NULL;

int greatestFreq = 0;
int treeCount = 1;

void addNode(char chars[], int freqs[], int size) {
    for (int i = 0; i <= size; i++) {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->character = chars[i];
        temp->frequency = freqs[i];
        temp->next = NULL;
        temp->left = NULL;
        temp->right = NULL;

        if (start == NULL) {
            start = temp;
            printf("%c-test0 ", chars[i]);
        }
       
        else if(freqs[i] < start->frequency){
            temp->next = start;
            start = temp;
           printf("%c-test1 ", chars[i]);
            }

        else 
            {
            struct Node *ptr = start;
            while (ptr->next != NULL && ptr->next->frequency<=freqs[i])  
                ptr = ptr->next;
                temp->next = ptr->next;
                ptr->next = temp;
            
           
        }
    }
}

void displayList() {
    struct Node *ptr = start;
    while (ptr != NULL) {
        printf("(%c, %d), ", ptr->character, ptr->frequency);
        ptr = ptr->next;
    }
    printf("\n");
}

void findGreatest() {
    if (start == NULL)
        return;

    struct Node *ptr = start;
    greatestFreq = ptr->frequency;
    while (ptr != NULL) {
        if (ptr->frequency > greatestFreq)
            greatestFreq = ptr->frequency;
        ptr = ptr->next;
    }
}

struct Node *popFront() {
    if (start == NULL)
        return NULL;

    struct Node *temp = start;
    start = start->next;
    return temp;
}

void addInOrder(struct Node *temp) {
    struct Node *ptr = start;
    struct Node *prev = NULL;

    while (ptr != NULL && ptr->frequency <= temp->frequency) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (prev == NULL) {
        temp->next = start;
        start = temp;
    } else {
        temp->next = ptr;
        prev->next = temp;
    }
}

void buildHuffmanTree() {
    if (start == NULL)
        return;

    int iteration = 1;
    while (start->next != NULL) {
        printf("Iteration %d: ", iteration++);
        displayList();

        struct Node *a = popFront();
        struct Node *b = popFront();

        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->character = '#';
        temp->frequency = a->frequency + b->frequency;
        temp->left = a;
        temp->right = b;
        temp->next = NULL;

        if (temp->frequency >= greatestFreq)
            greatestFreq = temp->frequency;
        
        treeCount += 2;
        addInOrder(temp);
    }
}

void printCodes(struct Node *root, int path[], int len) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < len; i++)
            printf("%d", path[i]);
        printf("\t%c\n", root->character);
    }

    path[len] = 0;
    printCodes(root->left, path, len + 1);

    path[len] = 1;
    printCodes(root->right, path, len + 1);
}

void printTree(struct Node *root, int level) {
    if (root == NULL)
        return;

    printTree(root->right, level + 1);
    printf("\n");
    for (int i = 0; i < level; i++)
        printf("    ");
    if (root->character == '#')
        printf("*");
    else
        printf("%c", root->character);
    printf("(%d)", root->frequency);
    printTree(root->left, level + 1);
}

void createListsFromInput() {
    char input[N];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character

    int freq[256] = {0}; // Assuming ASCII characters
    for (int i = 0; input[i] != '\0'; i++)
        freq[(int)input[i]]++;

    int size = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0)
            size++;
    }
    char chars[size];
    int frequencies[size];
    int j = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            chars[j] = (char)i;
            frequencies[j] = freq[i];
            j++;
        }
    }
    addNode(chars, frequencies, size - 1);
}
int main() {
    createListsFromInput();
    printf("Initial List: ");
    
    displayList();
    findGreatest();
    buildHuffmanTree();

    printf("Iteration 12: ");
    displayList();
    
    printf("\nHuffman Tree:\n");
    printTree(start, 0);
    printf("\n");

    printf("\nHuffman Codes:\n");
    int path[N];
    printCodes(start, path, 0);

    return 0;
}


//dogs do not spot hot pots or cats