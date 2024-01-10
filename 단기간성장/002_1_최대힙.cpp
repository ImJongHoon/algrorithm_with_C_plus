#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> heap;

//인자로 index 받기
void swap(int a, int b) {
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

void pushHeap(int data, int index) {
    //일단 집어넣고.
    heap[index] = data;

    int temp;

    while (index != 1) {
        if (heap[index / 2] > heap[index]) {
            break;
        }

        swap(index, index/2);

        index = index / 2;
    }
}

int popHeap(int size) {
    int ret = heap[1];
    heap[1] = heap[size+1];

    int index = 1;
    //index * 2 + 1 = 오른쪽 자식이 더 크다고 탈출해버리면 왼쪽 자식이 존재하는 경우 확인을 못할 수 있음.
    int left;
    int right;
    int child;
    while (index * 2 <= size) {
        left = index * 2;
        right = index * 2 + 1;

        //오른쪽 자식이 존재할때
        if (right <= size) {
            //동시에 왼쪽 자식이 더 클때
            if (heap[index * 2] > heap[index * 2 + 1]) {
                //부모가 더 크면 탈출
                if (heap[index * 2] < heap[index]) {
                    break;
                }
                swap(index, index*2);
                index = index * 2;
            }
            //동시에 오른쪽 자식이 더 클때
            else if (heap[index * 2 + 1] >= heap[index * 2]) {
                //부모가 더 크면 탈출
                if (heap[index * 2 + 1] < heap[index]) {
                    break;
                }
                swap(index, index * 2 + 1);
                index = index * 2 + 1;
            }
        }
        else {
            //부모가 더 크면 탈출
            if (heap[index * 2] < heap[index]) {
                break;
            }
            swap(index, index * 2);
            index = index * 2;
        }
        
    }

    return ret;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int num;
    cin >> num;

    heap = vector<int>(num + 1, 0);

    int data;
    int count=0;

    for (int i = 0; i < num; i++) {
        cin >> data;

        if (data == 0) {
            //크기가 0이면,
            if (count == 0) {
                cout << 0 << "\n";
            }
            else {
                count--;
                cout << popHeap(count) << "\n"; 
            }
        }
        else {
            count++;
            pushHeap(data, count);
        }
    }

    return 0;
}