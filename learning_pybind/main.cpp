// Created by kc on 9/9/22.

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <chrono>
#include <thread>
#include <vector>

namespace py = pybind11;

// some function
float adder(float arg1, float arg2) {
    return arg1+arg2;
}

// some templated function ------------------------------------incomplete
//template<typename To, typename From>
//std::vector<To> foo(std::vector<From> nums) {
//    // say converting a vector of ints to vector of floats
//    for(size_t i=0; i<nums.size(); i++)
//        nums
//}

// some class
class SomeClass {
private:
    float m_multiplier;
public:
    SomeClass():m_multiplier(1) {}

    SomeClass(float multiplier):m_multiplier(multiplier) {}

    float scale_up(float input) {
        return m_multiplier*input;
    }

    std::vector<float> transform(std::vector<float> nums) {
        for(size_t i=0; i<nums.size(); i++)
            nums[i] = scale_up(nums[i]);
        return nums;
    }
};

// ADVANCED: controlling GIL from the cpp program
void function_that_takes_a_while() {
    py::gil_scoped_release release;
    std::cout<<"Starting function_that_takes_a_while"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout<<"function_that_takes_a_while has ended"<<std::endl;
    py::gil_scoped_acquire acquire;
}

// Define the module, call the macro | parameters : module_name and handle?
PYBIND11_MODULE(kumar_test, handle) {  //Note: "kumar_test"- the module name must match in both main.cpp and CMakeLists.txt
    handle.doc() = "This string is a proxy for the docs that we can add";

    // function needed to expose a cpp function to python
    handle.def("python_adder_fn", &adder);  //name on the python side

    // function needed to expose the cpp class to python
    py::class_<SomeClass>(handle, "PySomeClass")  // name of class on the python side
            .def(py::init<float>())  // we need to expose the constructor of the class too!
            .def("scale_up", &SomeClass::scale_up)  // we've also clubbed the class method calls here
            .def("transform", &SomeClass::transform);

    // ADVANCED: exposing function_that_takes_a_while
    handle.def("py_function_that_takes_a_while", &function_that_takes_a_while);
}