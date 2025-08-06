#include<vector> 
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>  
#include <algorithm>


class Dictionnary{
    
    
    public:


    int input_index;
    int output_index;
    int number_constraints;
    int number_variables;
    float* Cj_Zj;
    float ** constraint_matrix;




    Dictionnary(int nb_obj, int nb_bound){
        number_constraints = nb_bound;
        number_variables = nb_obj + nb_bound;
        Cj_Zj = new float[number_variables + 1];
        constraint_matrix = new float*[number_constraints];
        for(int i = 0; i < number_constraints; i++){
            constraint_matrix[i] = new float[number_variables + 1]; 
        }
     
    

    }

    void make_dictionnary(float * x, float * b, float **A, float *Z, int nbcontraints,int nbvar){
                Cj_Zj = new float[number_variables + 1];
                constraint_matrix = new float*[number_constraints];
        


    }


    void choose_input_index(){
        float max = 0.0;
        input_index = 0;
        for(int i = 0; i < number_variables; i++){
            if(Cj_Zj[i] > max){
                max = Cj_Zj[i];
                input_index = i;  
            }
        }
    }

    void choose_pivot_line(){
        float test_min = 0;
        float min = constraint_matrix[0][number_variables]/constraint_matrix[0][input_index];
        output_index = 0; 
        for(int i = 0; i < number_constraints; i++ ){
            test_min = constraint_matrix[i][number_variables + 1]/constraint_matrix[i][input_index];
            if(test_min > min){
                min = test_min;
                output_index = i;

            }

        }
    }


      void pivot_dictionnary(){
        float factor = 0.0;
        for (int i = 0; i < number_variables + 1; i++){
             constraint_matrix[output_index][i++] = constraint_matrix[output_index][i++]/ constraint_matrix[output_index][input_index];
            };
        for (int i = 0; i < number_constraints; i++){
            if(i >= output_index and i <= output_index){
                continue;
            }else{
                factor = constraint_matrix[i][input_index];
                for(int j = 0; j < number_variables + 1; j++){
                    constraint_matrix[i][j] = constraint_matrix[i][j] - factor * constraint_matrix[output_index][j] ;
                }
            }
        }
        factor = Cj_Zj[input_index];
        for (int j = 0; j < number_variables + 1; j++){
            Cj_Zj[j] = Cj_Zj[j] -  factor * constraint_matrix[output_index][j]; 
            
        }


        
    }

    void display_dictionnary(){

    }
    
    
    
    ~Dictionnary(){

    }


};
