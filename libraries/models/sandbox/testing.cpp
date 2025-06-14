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

// Need to model link (synaspe) between neurons from one particular layer.
// Might need a Class to model the synapse. 

class Neuron {
       	private:
	       	int tag_id; 	
		double syn_weight;	// value determines neuron activation
		bool fired_state;  	// may change if output info isn't binary. 	
	       	// need to link automatically between layers 	
			
	public:
	       	// in constructor, need list of pointers to Neurons	
		Neuron(int tag_id, double syn_weight) {  	
			this->tag_id = tag_id;  
			this->syn_weight = syn_weight; 
				
		}
		
		void GetSynapseWeight () { 
			std::cout << "Synapse from Neuron " <<  tag_id << " Weight: " << syn_weight << std::endl;  
		} 	
}; 

class Synapse { 
	private:
	//	std::vector<Neuron*> layer;  // each synapse only needs two neurons	
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
		} 
		
		double get_synapse_weight () { 
			std::cout << "Weight: " << weight << std::endl; 
			return weight; 
		} 	
	 
}; 

int main () {
       	Neuron* n = new Neuron(1, 0.05); 
	n->GetSynapseWeight();
		
	// input data test with pixel matrix (each value is a gradient 0-10 to 0:black, 10:white; 
	
	int image[3][3] = {{0,0,0}, {10,10,10},{0,0,0}}; // image representing white line on black background: 3x3 image. 

	return 0; 
} 
