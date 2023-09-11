#include <stdio.h>
#include <stdlib.h>

struct Queue {
    // Định nghĩa cấu trúc dữ liệu Queue
    // Bao gồm các thành phần như front, rear, size, capacity, và array.
    int front; // front
    int rear; // rear
    int size; // size
    int capacity; // capacity
    int* array; // array
};

struct Queue* createQueue(unsigned capacity) {
    // Triển khai hàm tạo Queue mới
    struct Queue *queue =(struct Queue*) malloc(sizeof(struct Queue));

    queue->capacity = capacity;
    queue->front = 0;
    queue->size =0;
    queue-> rear = capacity-1;
    queue->array = (int *) malloc(queue->capacity * sizeof(int));

    return queue;
}

int isFull(struct Queue* queue) {
    // Triển khai hàm kiểm tra Queue có đầy không
    if (queue->size ==queue->capacity){
        return 1;
    }
    else return 0;
    
}

int isEmpty(struct Queue* queue) {
    // Triển khai hàm kiểm tra Queue có trống không
    if (queue->size != queue->capacity){
        return 1;
    }
    else return 0;
}

void enqueue(struct Queue* queue, int item) {
    // Triển khai hàm thêm phần tử vào Queue
     if (isFull(queue)==1)
        return;
    queue->rear = (queue->rear + 1) % queue->capacity; 
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    // Triển khai hàm lấy phần tử từ Queue
    if (isEmpty(queue)==0)
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity; 
    queue->size = queue->size - 1;
    return item;
}

int main() {
    
    struct Queue* queue = createQueue(5);

    // Thêm phần tử vào Queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Lấy phần tử ra khỏi Queue và in ra
    printf("%d da duoc lay ra khoi Queue\n", dequeue(queue));
    printf("%d da duoc lay ra khoi Queue\n", dequeue(queue));

    // Thêm phần tử mới vào Queue
    enqueue(queue, 50);

    // In ra phần tử ở đầu và cuối Queue
    printf("PHan tu dau tien la %d\n", queue->array[queue->front]);
    printf("PHan tu cuoi cung la %d\n", queue->array[queue->rear]);

    return 0;
}
