/* This is just a sandbox to create a Neuron and test different
 * properties of a modeled Neuron with accordance to my 
 * Neuron documentation.   */

#include "testing.h" 
#include<random> 


double randomize_weights () { 
	double rand_num;

	std::random_device rd; 
	std::mt19937 gen(rd()); 
	std::uniform_real_distribution<> distr(0.0, 0.5); // up to change 	
	
	rand_num = distr(gen);

	std::cout << "Random Number: " << rand_num << std::endl; 		
	return rand_num; 	
} 


int main () {
       	
	//int img_size = 9; 	
	// list of smart pointers to allocated heap mem of a neuron to act as layer 	
//	std::vector<std::make_unique<Neuron>> layer_one; 
	
/*	for ( int i = 0; i < img_size; i++ ) { 
		layer_one.push_back(std::make_unique<Neuron>(i));  
			
	}*/  	

	// need to create synaptic connection between neurons in layers 


	Neuron* n1 = new Neuron(1); 
	Neuron* n2 = new Neuron(2); 
	

	double rand_weight = randomize_weights();

	Synapse* s = new Synapse(n1, n2, rand_weight); 
	
	n1->activation_value(1, 10);
      	s->adjust_weight(); 
	n2->activation_value(s->get_synapse_weight(), n1->set_state());  	

       //	s->bridge(); 

	



	// input data test with pixel matrix (each value is a gradient 0-10 to 0:black, 10:white; 
	
	int image[3][3] = {{0,0,0}, {10,10,10},{0,0,0}}; // image representing white line on black background: 3x3 image. 

	return 0; 
} 
