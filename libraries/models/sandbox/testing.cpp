/* This is just a sandbox to create a Neuron and test different
 * properties of a modeled Neuron with accordance to my 
 * Neuron documentation.   */

#include "testing.h" 


int main () {
       	
	//int img_size = 9; 	
	// list of smart pointers to allocated heap mem of a neuron to act as layer 	
//	std::vector<std::make_unique<Neuron>> layer_one; 
	
/*	for ( int i = 0; i < img_size; i++ ) { 
		layer_one.push_back(std::make_unique<Neuron>(i));  
			
	}*/  	

	// need to create synaptic connection between neurons in layers 







	// input data test with pixel matrix (each value is a gradient 0-10 to 0:black, 10:white; 
	
	int image[3][3] = {{0,0,0}, {10,10,10},{0,0,0}}; // image representing white line on black background: 3x3 image. 

	return 0; 
} 
