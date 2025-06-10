#include "LIF.h"
extern "C" {
	
	Neuron::Neuron() {
	} 


	void Neuron::threshhold_checker() { 
		std::unique_lock<std::mutex> lock(mtx);   // create thread lock  
		while (true) { 
			cv.wait(lock, [this] {return potential >= THRESHHOLD;} ); //wait until the threshold is reached
			neuron_fired = true; 
	       		std::cout << "Neuron fired! Resetting potential.\n"; 
			potential = 0.0; 
			cv.notify_all(); //notify weight updater thread	
		} 
	} 

	void Neuron::accumulator() { 
		while(true) { 
			std::this_thread::sleep_for(std::chrono::milliseconds(100)); //input delay, refractory
			potential = potential + acc_rate ; //increase by acc_rate 
			std::cout << "Potential: " << potential << std::endl; 

			if (potential >= THRESHHOLD) { 
				std::lock_guard<std::mutex> lock(mtx); 
				cv.notify_one(); //notify threshold checker
			} 
		}
	} 

	void Neuron::weight_updater() { 
		while(true) { 
			std::unique_lock<std::mutex> lock(mtx); 
			cv.wait(lock, [this] {return neuron_fired; }); // wait until a neuron fires
			std::cout << "Updating weights...\n";
		       	synapse = synapse + 3;				// need to check tags of what inputs caused this neuron to fire. 
			std::cout << "Synapse now: " << synapse << std::endl; 	
			neuron_fired = false; 
		}	 	
	} 

	void Neuron::decay() { 
		while (true) { 
			std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Decay rate
		
			if (potential > 0) { 
				potential = potential - 0.5; // small decay over time 
				std::cout << "Leakeage: Potential now " << potential << std::endl; 

			} 
		} 
	}


	int main() {
		Neuron n;  	
       		std::thread t1(&Neuron::accumulator, &n); 
		std::thread t2(&Neuron::decay, &n); 
		std::thread t3(&Neuron::weight_updater, &n); 
		std::thread t4(&Neuron::threshhold_checker, &n); 

		t1.join(); 
		t2.join(); 
		t3.join(); 
		t4.join(); 
	
		return 0; 
	}
} 
