#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "Starting execution\n";
  Py_Initialize();
  PyObject* code = Py_CompileString(
      "import random\nprint('random number: ' + str(random.randint(1, 100)))",
      "string", Py_file_input);
  if (code == NULL)
    std::cout << "code wrong\n";
  PyObject* global_dict = PyDict_New();
  PyObject* local_dict = PyDict_New();
  PyObject* result = PyEval_EvalCode(code, global_dict, local_dict);
  Py_DECREF(code);
  Py_DECREF(global_dict);
  Py_DECREF(local_dict);
  Py_DECREF(result);
  Py_Finalize();

  return 0;
}
