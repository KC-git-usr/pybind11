# pybind11

### Steps
* $`pip install pybind11`
* $`git clone git@github.com:KC-git-usr/pybind11.git`
* $`pip install ./learning_pybind`

Test call
* `import kumar_py_lib as kpl`
* `kpl.python_adder_fn(1,5)`

How to use expose a cpp library to python using pybind11:
  * Create a new blank workspace
  * Place your required cpp files/folders
  * Create a `CMakeLists.txt` file in the root workspace
  * Create a `setup.py` 
  * go to the root folder and call `pip install ./package_name`

Working of the `setup.py` file:
  * Creates a build folder
  * Runs `cmake ..` inside the build folder
  * Runs `make` inside the build folder
  * You will see a `*.so` file created
  * This `*.so` file is effectively your `*.py` file which can be imported in other python modules
  * The `*.so` file is transformed into a `*.whl` file which is installed using `pip`

Notes for the output .so (effectively .py) file:
  * The capability of dir() to list out all the attributes of the parameter passed, is really useful when handling a lot of classes and functions, separately.
  * The dir() function can also list out all the available attributes for a module/list/dictionary. So, it also gives us information on the operations we can perform with the available list or module, which can be very useful when having little to no information about the module. It also helps to know new modules faster. 
  * So use `dir(module_name)` after importing the module_name in your final python script to know the module attributes
* For this example, additional information will be available through these commands:
  * $`cd build`
  * $`ipython3`
> `[In 1] import kumar_py_lib`
> 
> `[In 2] dir(kumar_py_lib)` 
> 
> `[In 3] kumar_py_lib.__doc__`
> 
> `[In 4] kumar_py_lib.python_adder_fn?`