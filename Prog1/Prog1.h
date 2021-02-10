namespace Prog1 {
    struct Node {
        double value;
        int row_position;
        int column_position;
        struct Node *next;
    };
    
    template <class T>
    int getNum(T &a) {
        std::cin >> a;
        if (!std::cin.good()) {
           return -1;
        }
        return 1;
    }
    
    inline int isgreater(double a, double b) {
        return a > b;
    }
    
    void Create_Node(struct Node **, double, int, int);
    struct Node *Create_Matrix(int &, int &);
    double Retrieve_Coordinates(struct Node *, int, int);
    void Print_Matrix(const char *, struct Node *, int, int);
    void Print_Vector(const char *, double [], int);
    struct Node *Erase_Matrix(struct Node *);
    double *Create_Vector(struct Node *, int, int);
    double avg(struct Node *, int, int);
    double max(struct Node *, int, int(*)(double, double));
}
