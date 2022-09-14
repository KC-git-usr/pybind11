cmake_minimum_required(VERSION 3.4)
project(pybind_test)

find_package(pybind11 REQUIRED)
pybind11_add_module(kumar_py_lib main.cpp) #this will be the name of the .so module name
# the kumar_py_lib...so file will behave exactly like a python module
