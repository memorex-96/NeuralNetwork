import ctypes
import platform 

if platform.system() == "Linux" or "linux2": 
    print("On Linux")
    c_libs = ctypes.CDLL("../build/libAIProject.so") 
elif platform.system() == "Windows": 
    print("On Windows")
    c_libs = ctypes.CDLL("") 


