#include<vector> 
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>  
#include <algorithm>
#include "Dictionnary.hpp"

   struct Simplexe{
    float * x;
    float * b;
    float **A;
    float *Z;
    Dictionnary *dict_form;  
    float zobj; 
    int number_objectives; 
    int number_constraints;
    int number_variables;
    



   


      Simplexe(std::string name) 
      {

   
            std::ifstream fichier(name);
                if(fichier){
                    
                    fichier >> number_objectives; 
                    fichier >> number_variables;
                    fichier >> number_constraints;
                    dict_form = new Dictionnary(number_objectives,number_constraints);
                     zobj = 0;
                     x = new float[number_variables];
                     b = new float[number_constraints]; 
                     Z  = new float[number_variables];
                    A = new float*[number_constraints];
                    for(int i = 0; i < number_constraints; i++){
                        A[i] = new float[number_variables + 1]; 
                    }
                    for(int i = 0; i < number_variables; i++){
                     fichier >> Z[i];
                    }

                    for(int i = 0; i < number_constraints; i++){
                        for(int j = 0; j < number_variables; j++){
                            fichier >> A[i][j];

                        }
                    }
                    
                    
                    for(int i = 0; i < number_constraints; i++){
                        fichier >> b[i];
                    }
                }


                



            }

        void fill_dictionnary(){
                 for(int i = 0; i < number_constraints; i++){
                    dict_form->constraint_matrix[i][number_variables + number_constraints + 1] = b[i];
                    dict_form->constraint_matrix[i][number_variables + i] = 1;
                    for(int j = 0; j < number_variables; j++){
                            dict_form->constraint_matrix[i][j] =  A[i][j];

                        }

                    }
                    for(int i = 0; i < number_variables; i++){
                        dict_form->Cj_Zj[i] = 0;
                    }
                    for(int i = 0; i < number_constraints; i++){
                        dict_form->Cj_Zj[number_constraints + i] = 1; 

                    }
                    dict_form->Cj_Zj[number_variables + number_constraints] = 0; 


            
        }


        void resolve_simplexe(){
            int iteration_number = 0;
            bool stop = false; 
            while (stop == false){
                std::cout << "iteration number is: " << iteration_number << std::endl; 
                for(int i = 0; i < number_variables; i ++){
                    if(dict_form->Cj_Zj[i] > 0 && iteration_number < number_variables){
                        iteration_number += 1;
                        dict_form->choose_input_index();
                        dict_form->choose_pivot_line();
                        dict_form->pivot_dictionnary(); 
                        break; 
                    }
                }
                stop = true;


            }

        }

};


