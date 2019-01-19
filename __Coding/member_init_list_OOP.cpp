class base{
    private:
        int A;
    public:
        base(int a):A(a){;}
};
class derived:public base{
    private:
        int B;
    public:
        derived(int a, int b):base::base(a), B(b){;} //<================ base class is initialized using "member list initializer"
};

// class derived1:public base{
//     private:
//         int C;
//     public:
//         derived1(int a, int c){ 
//             base::base(a);  // <========================== base class initiation cannot be deferred instead it should be initiated by "member list initializer"
//             c = C;
//         }
// };