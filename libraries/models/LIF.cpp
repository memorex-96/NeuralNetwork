#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
#include<condition_variable>
#include<chrono> 

extern "C" {
	std::mutex mtx; 
	std::condition_variable cv; 
	std::atomic<double> potential = 0.0; 
	const double THRESHOLD = 16.0; 
	bool neuron_fired = false;


	void test_SO () {
		std::cout << "Message From LIF.cpp" << std::endl; 
	} 

	void threshold_checker() { 
		std::unique_lock<std::mutex> lock(mtx);   // create thread lock  
		while (true) { 
			cv.wait(lock, [] {return potential >= THRESHOLD;} ); //wait until the threshold is reached
			neuron_fired = true; 
	       		std::cout << "Neuron fired! Resetting potential.\n"; 
			potential = 0.0; 
			cv.notify_all(); //notify weight updater thread	
		} 
	} 

	void accumulator() { 
		while(true) { 
			std::this_thread::sleep_for(std::chrono::milliseconds(100)); //input delay, refractory
			potential = potential + 3.30; //accumulation 
			std::cout << "Potential: " << potential << std::endl; 

			if (potential >= THRESHOLD) { 
				std::lock_guard<std::mutex> lock(mtx); 
				cv.notify_one(); //notify threshold checker
			} 
		}
	} 

	void weight_updater() { 
		while(true) { 
			std::unique_lock<std::mutex> lock(mtx); 
			cv.wait(lock, [] {return neuron_fired; }); // wait until a neuron fires
			std::cout << "Updating weights...\n"; 
			neuron_fired = false; 
		}	 	
	} 

	void decay() { 
		while (true) { 
			std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Decay rate
		
			if (potential > 0) { 
				potential = potential - 0.5; // small decay over time 
				std::cout << "Leakeage: Potential now " << potential << std::endl; 
			} 
		} 
	}
/*
void test_acc () { 
	while (potential  < THRESHOLD) { 
		potential = potential + 3.30; 
		std::cout << "Test_ACC Potential " << potential << std::endl; 	
	} 
}*/  


	int main() {
	
       		std::thread t1(accumulator); 
		std::thread t2(decay); 
		std::thread t3(weight_updater); 
		std::thread t4(threshold_checker); 

		t1.join(); 
		t2.join(); 
		t3.join(); 
		t4.join(); 
	
	/*
	std::cout << "Potential Before test acc " << potential << std::endl; 	
	test_acc(); 
	std::cout << "Potential After test_Acc " << potential << std::endl; */ 	
		return 0; 
	}
}
