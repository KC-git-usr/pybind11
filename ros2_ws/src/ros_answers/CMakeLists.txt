cmake_minimum_required(VERSION 3.8)
project(ros_answers)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(pybind11 REQUIRED)
find_package(Python3 COMPONENTS Interpreter Development)

pybind11_add_module(kumar_py_lib src/main.cpp)

ament_python_install_package(${PROJECT_NAME})

install(
  TARGETS kumar_py_lib
  DESTINATION "${PYTHON_INSTALL_DIR}/${PROJECT_NAME}"
)

ament_export_dependencies(pybind11)

ament_package()
