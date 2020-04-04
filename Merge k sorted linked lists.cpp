class Compare{
    public:
        bool operator()(ListNode *l1,ListNode *l2){
            return l1->val > l2->val;
        }
};
ListNode* Solution::mergeKLists(vector<ListNode*> &v) {
   
    priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
    if(v.size()==0) return NULL;
    for(int i=0;i<v.size();i++) pq.push(v[i]);
    ListNode *head,*popped;
    popped = pq.top(); pq.pop();
    head = popped;
    if(popped->next) pq.push(popped->next);
    ListNode *temp = head;
    while(!pq.empty()){
        popped = pq.top();
        temp->next = popped;
        pq.pop();
        temp=temp->next;
        if(popped->next) pq.push(popped->next);
    }
    return head;
}
