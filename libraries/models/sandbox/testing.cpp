/* This is just a sandbox to create a Neuron and test different
 * properties of a modeled Neuron with accordance to my 
 * Neuron documentation.   */


#include<iostream>  
#include<string> 
// includes for threading: 
#include<thread> 
#include<mutex> 
#include<atomic> 
#include<condition_variable> 
#include<chrono>
//vector to sim layers 
#include<vector>
#include<memory> 

// Need to model link (synaspe) between neurons from one particular layer.
// Might need a Class to model the synapse.
 

double threshold = 16.0;	 

class Neuron {
       	private:
	       	int tag_id; 	
		bool fired_state;  	// may change if output info isn't binary. 	
	       	// need to link automatically between layers 	
			
	public:
	       	// in constructor, need list of pointers to Neurons	
		Neuron(int tag_id) {  	
			this->tag_id = tag_id;  
				
		}
		
		bool get_fired_state () {
		       	std::cout << "Neuron: " << tag_id << ", Fired State: " << fired_state << std::endl; 	
			return fired_state; 
		} 	
}; 

class Synapse {
       // input pass through synapse causes firing 	
	private:
		Neuron* last; 
		Neuron* next;
	       	double weight; 	
	public: 
		Synapse (Neuron* last, Neuron* next, double weight) { 
			this->last = last; 
			this->next = next;
		       	this->weight = weight; 	
		} 	
		
		void adjust_weight () { 
			// update weight, get formula
			// V_j(t) = \sum^{n}_{i=1} x_i(t) \cdot \omega_{ij} - leak 
			// where: 
			// 	x_i(t) \in [0,1]: spike from presynaptic neuron at time t
			// 	\omega_{ij}: synaptic weight from neuron i to j 
			// 	leak: is the const factor 
			
	
		} 
		
		double get_synapse_weight () { 
			std::cout << "Weight: " << weight << std::endl; 
			return weight; 
		} 	
	 
}; 

int main () {
       	
	int img_size = 9; 	
	// list of smart pointers to allocated heap mem of a neuron to act as layer 	
	std::vector<std::make_unique<Neuron>> layer_one; 
	
	for ( int i = 0; i < img_size; i++ ) { 
		layer_one.push_back(std::make_unique<Neuron>(i));  
			
	} 	

	// need to create synaptic connection between neurons in layers 







	// input data test with pixel matrix (each value is a gradient 0-10 to 0:black, 10:white; 
	
	int image[3][3] = {{0,0,0}, {10,10,10},{0,0,0}}; // image representing white line on black background: 3x3 image. 

	return 0; 
} 
