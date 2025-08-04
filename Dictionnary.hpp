#include<vector> 
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>  
#include <algorithm>


class Dictionnary{
    
    float objective_function;
    int number_contraints;
    int number_variables;
    int number_spread_variables;
    float* decision_variables; 


    Dictionnary(){
        solution = new std::vector<int>;
        SumConstraint = new std::vector<float>;
        FitnessValue1 = 0;
        FitnessValue2 = 0; 
         valid = true;
         fitnessCalculated = false; 
         rank = 0;
         checkrank = false;
         crowdingdistance = 0;
    

    }




    
    void displayIndividual(int NbVariable, int NbConstraints){

        std::cout << "La solution créée est: "; 
        for(int i = 0; i < NbVariable; i ++){

            std::cout << " " << solution[0][i];

        }

        std::cout << std::endl; 

        std::cout << "Les contraintes sont: "; 
        for (int j = 0; j < NbConstraints; j++){

            std::cout << " " << SumConstraint[0][j]; 

        }
        std::cout << std::endl;
    }


    














    ~Solution(){

    }


};
