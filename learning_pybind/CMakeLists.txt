cmake_minimum_required(VERSION 3.4)
project(pybind_test)

find_package(pybind11 CONFIG REQUIRED)
pybind11_add_module(kumar_test main.cpp) #this will be the name of the .so module name
# the kumar_test...so file will behave exactly like a python module
