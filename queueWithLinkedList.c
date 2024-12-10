#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct node{
    int data;
    struct node * next;
};

struct queue{
    struct node * front;
    struct node * rear;
    int count;
};

void initialize(struct queue * q){
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(struct queue *q, int data){
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(q->count == 0){
        q->front = temp;
        q->rear = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
    q->count++;
}

int dequeue(struct queue * q){
    if(q->count == 0){
        printf("Kuyruk boş\n");
        return 0;
    }
    struct node * temp = q->front;
    int data = q->front->data;
    q->front = q->front->next;
    q->count--;
    if(q->front == NULL) // BU DURUMDA REAR'İ NULL'LAMAK ÖNEMLİ. SINAVDA BELKİ ÇIKAR!!
        q->rear = NULL;
    free(temp);
    return data;
}

void print_queue(struct queue * q){
    if(q->count == 0){
        printf("Boş kuyruk\n");
        return;
    }
    struct node * temp = q->front;
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
    //for döngüsüyle de counter'ı kullanarak da yazabilirsin.
}

void reset_queue(struct queue * q){
    if(q->count == 0){
        printf("Kuyruk zaten boş\n");
        return;
    }
    int x;
    while(q->count != 0){
        x = dequeue(q);
    }

    //for döngüsüyle de counter kullanarak yapabilirsin.
}

int main() {
    setlocale(LC_ALL, "Turkish");
    int secim, data;
    struct queue q;
    initialize(&q);

    while (1) {
        printf("\nQueue with Array\n");
        printf("\nAþaðýdaki iþlemlerden birini seçiniz:\n");
        printf("1 - Kuyruða eleman ekleme (Enqueue)\n");
        printf("2 - Kuyruktan eleman çýkarma (Dequeue)\n");
        printf("3 - Kuyruðu boþaltma (Reset)\n");
        printf("4 - Elemanlarý listele (Print)\n");
        printf("5 - Çýkýþ\n");

        printf("\nSeçiminizi yapýnýz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("\nLütfen eklemek istediðiniz deðeri giriniz: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                if (data != -1)
                    printf("Çýkarýlan eleman: %d\n", data);
                break;
            case 3:
                reset_queue(&q);
                printf("Kuyruk sýfýrlandý.\n");
                break;
            case 4:
                print_queue(&q);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nYanlýþ seçim\n");
                break;
        }
    }
}
