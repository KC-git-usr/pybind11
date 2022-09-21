import frankensteins_monster as fm
from concurrent.futures import ThreadPoolExecutor
import time

# calling our cpp function in python
print("Result of sum = ", fm.python_adder_fn(1.5, 2.5))

# calling our templated cpp function in python
print("Output of templated cpp function is = ", fm.py_foo_float_to_int([1, 2, 3]))

# creating a python object of the exposed cpp class and constructor
my_obj = fm.PySomeClass(5)
# calling the class member function
print("Result of scaling up = ", my_obj.scale_up(3))
# calling a different class member function
# although input on the cpp function call is a cpp vector of floats, we are passing a python list of floats
print("Result of transformation = ", my_obj.transform([1.0, 2.0, 3.0]))

# ADVANCED: controlling the GIL
start_time = time.time()

with ThreadPoolExecutor(4) as ex:
    ex.map(lambda x: fm.py_function_that_takes_a_while(), [None] * 4)

print(f"Threaded fun took {time.time() - start_time} seconds")
