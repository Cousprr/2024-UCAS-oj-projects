#include "staticList.h"
const int radix = 10;
template <class T>
;
void Sort(staticlinkList<T> &L, int d)
{
    int rear[radix], front[radix]; // 队尾与队头指针
    int i, j, k, last, current, n = L.Length();
    for (i = 0; i < n; i++)
        L[i].link = i + 1;
    L[n].link = 0; // 初始化, 循环链表
    current = 1;   // 取表元素计数
    for (i = d; i >= 1; i--)
    { // 按排序码key[i]分配
        for (j = 0; j < radix; j++)
            front[j] = 0;
        while (current != 0)
        {                                // 分配
            k = getDigit(L[current], i); // 取第i个排序码
            if (front[k] == 0)
                front[k] = current;
            // 第k个队列空, 该元素为队头
            else
                L[rear[k]].link = current; // 不空, 尾链接
            rear[k] = current;             // 该元素成为新的队尾
            current = L[current].link;     // 下一个元素
        }
        j = 0; // 依次从各队列收集并拉链
        while (front[j] == 0)
            j++;                        // 跳过空队列
        L[0].link = current = front[j]; // 新链表的链
        last = rear[j];                 // 非空队列链尾
        for (k = j + 1; k < radix; k++) // 连接其余队列
            if (front[k] != 0)
            { // 队列非空
                L[last].link = front[k];
                // 前一非空队列队尾链接到第k队列队头
                last = rear[k]; // 记第k队列队尾
            }
        L[last].link = 0; // 新链表表尾
    } // 下一趟分配与收集
};