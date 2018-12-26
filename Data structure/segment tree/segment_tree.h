#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H
class Segment_tree{
    private:
        int* tree;
        int N;// size of the data array that is number of leaf nodes
        int Operation(int op1, int op2);
    public:
        Segment_tree(int* data, int s);
        bool update_point(int index, int value);
        int range_query(int left, int right);
        void dump_tree();
        ~Segment_tree();

};
#endif