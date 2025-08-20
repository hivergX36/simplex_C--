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
    int nbcol;
    int dictionnary_number_variables;
    float* Cj_Zj;
    float ** constraint_matrix;




    Dictionnary(int nb_var, int nb_bound){
        number_constraints = nb_bound;
        dictionnary_number_variables = nb_var + nb_bound;
        nbcol = dictionnary_number_variables + 1; 
        Cj_Zj = new float[dictionnary_number_variables + 1];
        constraint_matrix = new float*[number_constraints];
        for(int i = 0; i < number_constraints; i++){
            constraint_matrix[i] = new float[dictionnary_number_variables + 1]; 
        }
     
    

    }

    void make_dictionnary(float * x, float * b, float **A, float *Z, int nbcontraints,int nbvar){
                Cj_Zj = new float[dictionnary_number_variables + 1];
                constraint_matrix = new float*[number_constraints];
        


    }


    void choose_input_index(){
        float max = 0.0;
        input_index = 0;
        for(int i = 0; i < dictionnary_number_variables ; i++){
            if(Cj_Zj[i] > max && Cj_Zj[i] > 0){
                max = Cj_Zj[i];
                input_index = i;
            }
        }
            std::cout << "input Index: " << input_index << std::endl; 

    }

    void choose_pivot_line(){
        float test_min = 0;
        std::cout << "Input_Index " << input_index << std::endl;
        std::cout << "constraint_matrix[0][input_index]: " << constraint_matrix[0][input_index] << std::endl;
        std::cout << "constraint_matrix[0][dictionnary_number_variables ]: " << constraint_matrix[0][nbcol] << std::endl;

        float min = constraint_matrix[0][dictionnary_number_variables + 1]/constraint_matrix[0][input_index];
        std::cout << " " << "min: " << min << std::endl;
        output_index = 0; 
        for(int i = 1; i < number_constraints; i++ ){
            std::cout << "constraint_matrix[i][input_index]: " << constraint_matrix[i][input_index] << std::endl;
            std::cout << "constraint_matrix[i][dictionnary_number_variables ]: " << constraint_matrix[1][dictionnary_number_variables] << std::endl;
            test_min = constraint_matrix[i][dictionnary_number_variables + 1]/constraint_matrix[i][input_index];
            std::cout << "test_min: " << test_min << std::endl;
            if(test_min < min){
                min = test_min;
                output_index = i;
            }
        }
        std::cout << " pivot chosen: " << output_index;
    }


      void pivot_dictionnary(){
        float factor = 0.0;
        float div_factor = constraint_matrix[output_index][input_index];
        std::cout << "div_factor: " << div_factor << std::endl;
        for (int i = 0; i < dictionnary_number_variables + 2; i++){
            constraint_matrix[output_index][i] = constraint_matrix[output_index][i] / div_factor;
            std::cout << "  constraint_matrix[output_index][i]: " << constraint_matrix[output_index][i] << std::endl;

        };
        for (int i = 0; i < number_constraints; i++){
            if(i >= output_index and i <= output_index){
                continue;
            }else{
                factor = constraint_matrix[i][input_index];
                for(int j = 0; j < dictionnary_number_variables + 1; j++){
                    constraint_matrix[i][j] = constraint_matrix[i][j] - factor * constraint_matrix[output_index][j] ;
                }
            }
        }
        factor = Cj_Zj[input_index];
        for (int j = 0; j < dictionnary_number_variables  + 1; j++){
            Cj_Zj[j] = Cj_Zj[j] -  factor * constraint_matrix[output_index][j];
        }
    }
    
    ~Dictionnary(){

    }


};
