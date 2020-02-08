#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

struct Process {
    char name[11];
    int time;
    Process() {
        time = 0;
    }
    Process(char str[], int t) {
        strcpy(name, str);
        time = t;
    }
    char* getName() {
        return name;
    }
    int getTime() {
        return time;
    }
    void run(int t) {
        time = time - t;
    }
};

struct Queue {
    Process p[100010];
    int head = 0;
    int tail = 0;
    Queue() {
        head = 0;
        tail = 0;
    }
    void init() {
        head = tail = 0;
    }
    void enqueue(Process x) {
        p[tail] = x;
        tail++;
    }
    Process dequeue() {
        Process res = p[head];
        head++;
        return res;
    }
    int getSize() {
        return tail - head;
    }
};

int main() {
    char name[20];
    int time;
    int n, q;
    int passedTime = 0;
    Queue queue;
    queue.init();
    scanf("%d %d", &n, &q);

    while(n--) {
        scanf("%s %d", name, &time);
        Process p(name, time);
        queue.enqueue(p);
    }

    while(queue.getSize()) {
        Process p = queue.dequeue();
        passedTime += min(q, p.getTime());
        p.run(q);
        if(p.getTime() > 0) queue.enqueue(p);
        else printf("%s %d\n", p.getName(), passedTime);
    }
}