#pragma once 
#include<iostream> 
#include<string>
#include<thread> 
#include<mutex> 
#include<atomic> 
#include<condition_variable>
#include<chrono> 
#include<vector> 
#include<memory>
#include<random> 

// arbitrary; up to change
#define THRESHHOLD 16.0 
#define LEAK 0.000003
#define RESET 0 

/* Potential >= THRESHHOLD -> fire, 
 * DECAY: 0.005 every 1000 milliseconds. Sets potential of Neuron to zero over time if no firing. 
 * Neurons recieves input, if 0 input, no firing.
 * */



class Neuron { 
	private: 
		int tag_id; 
		bool fired_state;
		int state;

	        //std::atomic<double> potential;
	       	double potential;  	
		// accumulator 
		// decay by leak factor 	
	public: 
		Neuron (int tag_id) {
			this->tag_id = tag_id; 	
		}
					
		bool get_fired_state () { 
			std::cout << "Neuron: " << tag_id << ", Fired State: " << fired_state << std::endl; 
			return fired_state; 
		}

		void accumulator () {				// this is to run once per loop  
			if (this->potential < THRESHHOLD) {  
				double rand_num; 
				std::random_device rd; 
				std::mt19937 gen(rd());
				std::uniform_real_distribution<> distr(0.0, 0.0003); 
				
				rand_num = distr(gen); 
				
				std::cout << "Accumulated: " << rand_num << std::endl;				
				this->potential = potential + rand_num;
				std::cout << "Potential: " << this->potential << std::endl; 
			} else { return; }  
		       		
		} 	


		void activation_value (double syn_weight, int prev_val) {	//first layer is integer input  
			// func: prev_val[0,1] 
			// 	 synapse weight 
			// 	 - leak

			
			if (syn_weight == -1) {			// if synapse DNE (first layer Neurons)  
				this->potential = prev_val;   	
			} else if (syn_weight > -1) { 
				potential = prev_val * syn_weight - LEAK; 	// prev * syn + (pot - leak) 
			} 

			std::cout << "potential: " << potential << std::endl;

			if (potential >= THRESHHOLD) { 
				std::cout << "Fired!" << std::endl; 	
				fired_state = true;
			       	potential = RESET; 	
			} 
		}
	       	
		int set_state () { 
			if (this->fired_state == true) { 
				this->state = 1; 
			} else {this->state = -1;}  
		       	return this->state; 	
		} 	

		int get_tag () { 
			std::cout << tag_id << std::endl;
		       	return this->tag_id; 	
		} 	
}; 

class Synapse { 
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

		// pass input from last neuron 
		int get_prev_input (int input ) { 
			if (input > 0 ) return input; 
		       	else { 
				std::cout << "prev Neuron didn't fire" << std::endl; 
			} 	
		} 

		void adjust_weight () { 
			
		        if (last->get_fired_state() == true && next->get_fired_state() == true) { 
				weight += 0.3; 						// overtime consistent sequential firings build associations
			}
		       	else return; 	
		} 

		double get_synapse_weight () { 
			std::cout << "Weight: " << weight << std::endl; 
			return weight; 
		} 	

		void bridge () {
		       last->get_tag(); 
	       	       next->get_tag(); 	       
		} 	
};


/*  How to model firing from discrete inputs 
 *  	adjust_weight has firing formula: 
 *  
 * 	 V_j(t) = \sum^{n}_{i=1} x_i(t) \cdot \omega_{ij} - leak
 *	 where: 
 *	 	x_i(t) \in [0,1]: spike from presynaptic neuron at time t
 *       	\omega_{ij}: synaptic weight from neuron i to j 
 *              leak: const factor
 *
 *  	The value of V_j at time t will be compared to THRESHOLD: 
 *  		if V_j > THRESHOLD -> j fires = 1 
 *  		if V_j < THRESHOLD -> j = 0 
 *
 *  	If Neuron J fires from Layer "last" and Neuron P fires from Layer "next" with 
 *  	synaptic connection to J, weight between J and P increases	*/ 
