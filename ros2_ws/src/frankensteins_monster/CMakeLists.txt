cmake_minimum_required(VERSION 3.4)
project(frankensteins_monster)

find_package(pybind11 REQUIRED)
pybind11_add_module(frankensteins_monster main.cpp) #this will be the name of the .so module name
# the frankensteins_monster...so file will behave exactly like a python module
