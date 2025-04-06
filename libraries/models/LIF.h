#pragma once
#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
#include<condition_variable>
#include<chrono> 

/* When any set of neurons (A and B) lack consistent sequential firing, 
 * they will decrease their synapse level. 
 *
 * If any set of neurons (A and B) have a strong synapse, the signification 
 * is that their action potetial threshold is lowered for a particular neuron signal.
 * This means that each signal must require a tag.
 *
 * Need function to create network map. Each Neuron is an object allocated to the heap sizeof(Neuron).  
 */
extern "C" { 
	typedef struct Signal { 
		// needs const input value 
		// needs id tag 
	} Signal; 


	class Neuron {
      	
		public:
			Neuron(); 
			void test_SO(); 
			void threshhold_checker();
			void accumulator(); 
			void weight_updater(); 
			void decay();
		       		

		private:
			std::mutex mtx; 
			std::condition_variable cv; 
			std::atomic<double> potential = 0.0; 
			const double THRESHHOLD = 16.0; 
			bool neuron_fired = false;
			// list of pointers to neuron connections
			// each neuron connection needs to be a tag to control weight	
			double synapse = 0.0;
			// weight_updater takes specific tag, and strengthens synapse by some degree.
		        // need to create signification of synaptic strength 	
	};
};
