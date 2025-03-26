cmake_minimum_required(VERSION 3.0)

project(AIProject)

set(SOURCES ../libraries/math/MatrixMult.c)

if (UNIX) 
	add_library(AIProject SHARED ${SOURCES})
	set_target_properties(AIProject PROPERTIES SUFFIX ".so")
endif() 	

