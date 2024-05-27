#include"TowerofHanoi.h"

void MoveDisk(int n, int src, int des) {
    cout << "Di chuyen dia " << n << " tu coc " << src << " sang coc " << des << "\n";
}

void Tower(int n, int col1, int col2, int col3) {
    Stack nStack, col1Stack, col2Stack, col3Stack, stageStack;
    
    Init(nStack);
    Init(col1Stack);
    Init(col2Stack);
    Init(col3Stack);
    Init(stageStack);

    Push(nStack, n);
    Push(col1Stack, col1);
    Push(col2Stack, col2);
    Push(col3Stack, col3);
    Push(stageStack, 0);


    while (!IsEmpty(nStack)) {
        int n = Top(nStack);
        int col1 = Top(col1Stack);
        int col2 = Top(col2Stack);
        int col3 = Top(col3Stack);
        int stage = Top(stageStack);



        if (n == 0) {
            Pop(nStack);
            Pop(col1Stack);
            Pop(col2Stack);
            Pop(col3Stack);
            Pop(stageStack);

            continue;
        }

        switch (stage) {
        case 0:
            setTop(stageStack, 1);
            Push(nStack, n - 1);
            Push(col1Stack, col1);
            Push(col2Stack, col3);
            Push(col3Stack, col2);
            Push(stageStack, 0);

            break;
        case 1:
            MoveDisk(n,col1, col3);
            setTop(stageStack, 2);
            break;
        case 2:
            setTop(stageStack, 3);
            Push(nStack, n - 1);
            Push(col1Stack, col2);
            Push(col2Stack, col1);
            Push(col3Stack, col3);
            Push(stageStack, 0);
            break;
        case 3:
            Pop(nStack);
            Pop(col1Stack);
            Pop(col2Stack);
            Pop(col3Stack);
            Pop(stageStack);
            break;
        }
    }
}