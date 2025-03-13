import ctypes
import platform 

if platform.system() == "Linux" or "linux2": 
    print("On Linux") 
elif platform.system() == "Windows": 
    print("On Windows") 
