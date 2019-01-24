/*given a list of votes {id, timestamp} and a threshold n return the set of votes greater than n in the last hour.*/
struct vote{
    int name;
    int timestamp;
}
struct node{
    vote v;
    node* next;
    node(int name, int ts){
        v.name = name;
        v.timestamp = ts;
        next = 0;
    }
}
class  timed_pairs{
    private:
        unordered_map<int, int> counts;//<vote.name, count>
        node* head;// the linked list of last hour
        node* tail;// the linked list of last hour
        unordered_set<int> top_votes;
        int threshold;
    public:
        timed_pairs(int n):threshold(n){;}
        void insert(const vote v){ //O(n)
            // 1. insert to the tail of the list
            node* newnode = new node(v);
            tali->next = newnode;

            // 2. update the counts 
            counts[v.name]++; // todo: check if it is the first time it is inserted

            // 3.  update the top voted set
            if(counts[v.name]==threshold)
                top_votes.insert(v.name);
            
            //4. handle the expired values
            node* cur = head;
            if(cur != 0){
                cur_ts = cur->v.timestamp;
                while(cur_ts < (v.timestamp-60+1)){// if out of the last hour remove it and update counsts and top_votes
                    
                    // 1. update the counts hash table
                    int pre_count = counts[cur->v.name];
                    counts[cur->v.name]--;
                    
                    // 2. update the top voted list
                    if(pre_count == threshold)
                        top_votes.remove(cur->v.name);

                    // 3. remove the expired element from the list
                    if(cur->next != 0){ // update the linked list
                        cur = cur->next;
                        delete head;
                        head = cur;
                        cur_ts = cur->v.timestamp;
                    }
                    else{
                        cur = 0;
                        head = 0;
                        tail = 0;
                        break;
                    }
                }
            }
        } 
        unordered_set<int> get_top(){
            return top_votes;
        }

};