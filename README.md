# pybind11

### Steps
* `pip install pybind11`
* `sudo apt -y install python3-dev`
* How to use pybind11:
  * Create a new blank workspace
  * Place your required cpp files/folders
  * Create a CMakeLists.txt file in the root workspace
  * Create a build folder
  * Run `cmake ..` inside the build folder
  * Run `make` inside the build folder
  * You will see a `*.so` file created
  * This `*.so` file is effectively your `*.py` file which can be imported in other python modules
* Notes for the output .so (effectively .py) file:
  * The capability of dir() to list out all the attributes of the parameter passed, is really useful when handling a lot of classes and functions, separately.
  * The dir() function can also list out all the available attributes for a module/list/dictionary. So, it also gives us information on the operations we can perform with the available list or module, which can be very useful when having little to no information about the module. It also helps to know new modules faster. 
  * So use `dir(module_name)` after importing the module_name in your final python script to know the module attributes
* 