#include <iostream>

#include "Prog1.h"

namespace Prog1 {
    void Create_Node(struct Node **matrix, double non_zero_element, int row_index, int column_index) {
        struct Node *temp, *rows;
        temp = *matrix;
        
        if (!temp) {
           try {
               temp = new struct Node;
           }
           catch (std::bad_alloc &ba) {
               std::cout << "Error in allocating memory: " << ba.what() << std::endl;
               return;
           }
           temp->value = non_zero_element;
           temp->row_position = row_index;
           temp->column_position = column_index;
           temp->next = nullptr;
           *matrix = temp;
        }
        else {
           while (temp->next) {
              temp = temp->next;
           }
           try {
               rows = new struct Node;
           }
           catch (std::bad_alloc &ba) {
               std::cout << "Error in allocating memory: " << ba.what() << std::endl;
               return;
           }
           rows->value = non_zero_element;
           rows->row_position = row_index;
           rows->column_position = column_index;
           rows->next = nullptr;
           temp->next = rows;
        }
    }
    
    struct Node *Create_Matrix(int &rm, int &rn) {
        const char *pr = "";
        struct Node *matrix = nullptr;
        int m, n;
        double item;
        
        do {
            std::cout << pr;
            std::cout << "Enter the matrix dimensions: ";
            pr = "Invalid input, please try again!\n";
            if (getNum(m) < 0 || getNum(n) < 0) {
               return nullptr;
            }
        } while (m < 1 || n < 1);
        
        for (int i = 0; i < m; i++) {
            std::cout << "Enter the items for matrix row #" << (i + 1) << ": ";
            for (int j = 0; j < n; j++) {
                if (getNum(item) < 0) {
                   Erase_Matrix(matrix);
                   return nullptr;
                }
                else if (!item) {
                   continue;
                }
                else {
                   Create_Node(&matrix, item, i, j);
                }
            }
        }
        
        rm = m;
        rn = n;
        return matrix;
    }
    
    double Retrieve_Coordinates(struct Node *matrix, int row_index, int column_index) {
        struct Node *temp = matrix;
        
        while (temp) {
           if (temp->row_position == row_index && temp->column_position == column_index) {
              return temp->value;
           }
           temp = temp->next;
        }       
        return 0;
    }
    
    void Print_Matrix(const char *msg, struct Node *matrix, int m, int n) {
        std::cout << msg << std::endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << Retrieve_Coordinates(matrix, i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
    
    void Print_Vector(const char *msg, double vector[], int m) {
        std::cout << msg << std::endl;
        for (int i = 0; i < m; i++) {
            std::cout << vector[i] << " ";
        }
        std::cout << std::endl;
    }
    
    struct Node *Erase_Matrix(struct Node *matrix) {
        struct Node *temp, *tmp;
        temp = matrix;
        
        while (temp) {
           tmp = temp;
           temp = temp->next;
           delete tmp;
        }
        return nullptr;
    }
    
    double *Create_Vector(struct Node *matrix, int m, int n) {
        struct Node *temp = matrix;
        double *vector = nullptr;
        double first_element = 0;
        
        try {
            vector = new double[m];
        }
        catch (std::bad_alloc &ba) {
            std::cout << ba.what() << std::endl;
            return nullptr;
        }

        for (int i = 0; i < m; i++) {
            while (temp) {
               if (temp->row_position == i && temp->column_position == 0) {
                  first_element = temp->value;
                  break;
               }
               temp = temp->next;
            }
            if (first_element > 0) {
               vector[i] = avg(matrix, i, n) / max(matrix, i, isgreater);
            }
            else {
               vector[i] = avg(matrix, i, n) / matrix->value;
            }
            first_element = 0;
        }
        return vector;
    }
    
    double avg(struct Node *matrix, int row_index, int n) {
        struct Node *temp = matrix;
        double sum = 0;
        
        while (temp) {
           if (temp->row_position == row_index) {
              sum += temp->value;
           }
           temp = temp->next;
        }
        return sum / n;
    }

    double max(struct Node *matrix, int row_index, int(*f)(double, double)) {
        struct Node *temp = matrix;
        double res = temp->value;
        
        while (temp) {
           if (temp->row_position == row_index) {
              if (f((temp->value), res) > 0) {
                 res = temp->value;
              }
           }
           temp = temp->next;
        }
        return res;
    }
}
