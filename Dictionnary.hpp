#include<vector> 
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>  
#include <algorithm>


class Dictionnary{
    
    int input_index; 
    float objective_function;
    int number_contraints;
    int number_variables;
    int number_spread_variables;
    float* cost_variables; 
    float ** constraint_matrix;


    Dictionnary(int nb_obj, int nb_bound){
        objective_function = 0;
        number_contraints = nb_bound;
        number_variables = nb_obj + nb_bound;
        cost_variables = new float[number_variables];
        constraint_matrix = new float*[number_contraints];
        for(int i = 0; i < number_contraints; i++){
            constraint_matrix[i] = new float[number_variables + 1]; 
        }
     
    

    }


     void choose_input_index(){
        float max = 0.0;
        input_index = 0;
        for(int i = 0; i < number_variables; i++){
            if(cost_variables[i] > max){
                max = cost_variables[i];
            }



        }

    }






    














    ~Dictionnary(){

    }


};
