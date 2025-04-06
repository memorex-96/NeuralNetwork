import ctypes
import platform 

if platform.system() == "Linux" or "linux2": 
    print("On Linux")
    c_libs = ctypes.CDLL("../build/libAIProject.so") 
elif platform.system() == "Windows": 
    print("On Windows")
    c_libs = ctypes.CDLL("") 


#c_libs.testing_shared()
c_libs.test_SO() 


#class Neuron(ctypes.Structure): 

