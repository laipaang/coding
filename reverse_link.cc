// 反转链表

struct LinkNode {
    int val;
    LinkNode* next;

    // 默认构造函数
    LinkNode() : val(0), next(nullptr) {}
}

LinkNode* reverse_link(LinkNode* head) {
    LinkNode dummy;
    while (head) {
        LinkNode* tmp = head;
        head = head->next;
        tmp->next = dummy.next;
        dummy.next = tmp;
    }

    return dummy.next;
}

