cmake_minimum_required(VERSION 3.20)

project(NetStack LANGUAGES C)
set(CMAKE_BUILD_TYPE "Debug")

add_executable(network 
	main.c
	gluethread/glthread.h)
