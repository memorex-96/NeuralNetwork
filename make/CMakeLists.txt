cmake_minimum_required(VERSION 3.0)

project(AIProject)

# set(SOURCES ../libraries/math/MatrixMult.c ../libraries/models/LIF.cpp)
set(SOURCES ../libraries/models/LIF.cpp) 
if (UNIX) 
	add_library(AIProject SHARED ${SOURCES})
	set_target_properties(AIProject PROPERTIES SUFFIX ".so")
endif() 	

