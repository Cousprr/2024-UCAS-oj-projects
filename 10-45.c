#include "staticList.h"
const int radix = 10;
template <class T>
;
void Sort(staticlinkList<T> &L, int d)
{
    int rear[radix], front[radix]; // ��β���ͷָ��
    int i, j, k, last, current, n = L.Length();
    for (i = 0; i < n; i++)
        L[i].link = i + 1;
    L[n].link = 0; // ��ʼ��, ѭ������
    current = 1;   // ȡ��Ԫ�ؼ���
    for (i = d; i >= 1; i--)
    { // ��������key[i]����
        for (j = 0; j < radix; j++)
            front[j] = 0;
        while (current != 0)
        {                                // ����
            k = getDigit(L[current], i); // ȡ��i��������
            if (front[k] == 0)
                front[k] = current;
            // ��k�����п�, ��Ԫ��Ϊ��ͷ
            else
                L[rear[k]].link = current; // ����, β����
            rear[k] = current;             // ��Ԫ�س�Ϊ�µĶ�β
            current = L[current].link;     // ��һ��Ԫ��
        }
        j = 0; // ���δӸ������ռ�������
        while (front[j] == 0)
            j++;                        // �����ն���
        L[0].link = current = front[j]; // ���������
        last = rear[j];                 // �ǿն�����β
        for (k = j + 1; k < radix; k++) // �����������
            if (front[k] != 0)
            { // ���зǿ�
                L[last].link = front[k];
                // ǰһ�ǿն��ж�β���ӵ���k���ж�ͷ
                last = rear[k]; // �ǵ�k���ж�β
            }
        L[last].link = 0; // �������β
    } // ��һ�˷������ռ�
};