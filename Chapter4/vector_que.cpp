#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    char name[20];
    int time;

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
    vector<Process> p;

    void init() {
        p.erase(p.begin(), p.end());
    }
    void enqueue(Process x) {
        p.push_back(x);
    }
    Process dequeue() {
        Process res = p.at(0);
        p.erase(p.begin());
        return res;
    }
    int getSize() {
        return p.size();
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