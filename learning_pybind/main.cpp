// Created by kc on 9/9/22.

#include "pybind11/pybind11.h"

namespace py = pybind11;

float adder(float arg1, float arg2) {
    return arg1+arg2;
}

//Define the module, call the macro | parameters : module_name and handle?
PYBIND11_MODULE(kumar_test, handle) {  //Note: "kumar_test"- the module name must match in both main.cpp and CMakeLists.txt
    handle.doc() = "The adder function adds two input arguments and returns the sum";
    handle.def("python_adder_fn", &adder);  //name on the python side
}