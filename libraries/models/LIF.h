#pragma once
#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
#include<condition_variable>
#include<chrono>
#include<string> 


extern "C" { 

	class Neuron {
 		     	
		public:
			Neuron(); 
			std::string tag; 	// tag for actual indv neuron ; for association 		
		
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
		       	const double acc_rate = 0.06; 	
			bool neuron_fired = false;
			// list of pointers to neuron connections
			// each neuron connection needs to be a tag to control weight	
			double synapse = 0.0;
			// weight_updater takes specific tag, and strengthens synapse by some degree.
		        // need to create signification of synaptic strength 	
	};
};
