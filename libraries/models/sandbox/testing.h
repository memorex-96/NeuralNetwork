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


#define THRESHOLD 16.0 

class Neuron { 
	private: 
		int tag_id; 
		bool fired_state; 
	public: 
		Neuron (int tag_id) {
			this->tag_id = tag_id; 	
		}

		bool get_fired_state () { 
			std::cout << "Neuron: " << tag_id << ", Fired State: " << fired_state << std::endl; 
			return fired_state; 
		} 	
}; 

class Synapse { 
	private: 
		Neuron* last; 
		Neuron* next; 
		double weight; 
	private: 
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
			// 	\omega_{ij}: synaptic weight from  neuron i to j 
			// 	leak: const factor
		} 

		double get_synapse_weight () { 
			std::cout << "Weight: " << weight << std::endl; 
			return weight; 
		} 		
};


/*  How to model firing from discrete inputs 
 *  	adjust_weight has firing formula: 
 *  
 * 	 V_j(t) = \sum^{n}_{i=1} x_i(t) \cdot \omega_{ij} - leak
 *
 *  	The value of V_j at time t will be compared to THRESHOLD: 
 *  		if V_j > THRESHOLD -> j fires = 1 
 *  		if V_j < THRESHOLD -> j = 0 
 *
 *  	If Neuron J fires from Layer "last" and Neuron P fires from Layer "next" with 
 *  	synaptic connection to J, weight between J and P increases	*/ 
