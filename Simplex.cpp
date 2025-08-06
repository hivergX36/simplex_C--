#include <iostream>
 
int main(){

    int p = 5;
    int *a = &p;
    int *(a + 1) = &(p + 1); 

    std::cout << *a << std::endl; 

}