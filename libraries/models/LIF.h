#pragma once
#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
#include<condition_variable>
#include<chrono> 


extern "C" { 
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
	};
};
