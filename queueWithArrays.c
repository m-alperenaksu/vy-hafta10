#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define QUEUE_SIZE 5

struct queue {
    int front;
    int rear;
    int count;
    int data[QUEUE_SIZE];
};

void initialize(struct queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

void enqueue(struct queue *q, int data) {
    if (q->count == QUEUE_SIZE) {
        printf("Kuyruk dolu.\n");
        return;
    }
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->data[q->rear] = data;
    q->count++;
}

int dequeue(struct queue *q) {
    if (q->count == 0) {
        printf("Kuyruk boþ\n");
        return -1;
    }
    int data = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;
    return data;
}

void print_queue(struct queue * q){ // Bunda bi hata var ama çözemedim!!!!!!!
    if(q->count == 0){
        printf("Kuyruk boþtur.\n");
        return;
    }
    int temp = q->front;

    do{
        printf("%d", q->data[temp]);
        if(temp == QUEUE_SIZE - 1)
            temp = 0;
        else
            temp++;

        /*
        temp++;
        temp %= QUEUE_SIZE;  BU ÞEKÝLDE DE YAZABÝLÝRÝZ.
        */
    }while(temp != q->rear);
}

void reset_queue(struct queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
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
