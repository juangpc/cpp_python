#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <iostream>

void callback1() {
  std::cout << "Hello from callback1\n";
}

void callback2() {
  std::cout << "Hello from callback2\n";
}


static PyObject* callback1_py(PyObject* self, PyObject* args) {
  callback1();
  return Py_None;
}

static PyObject* callback2_py(PyObject* self, PyObject* args) {
  callback2();
  return Py_None;
}

static struct PyMethodDef callbacksMethods[] = {
  {"callback1", callback1_py, METH_VARARGS, "Call to callback1"},
  {"callback2", callback2_py, METH_VARARGS, "Call to callback2"},
  {NULL, NULL, 0, NULL}
};

static PyModuleDef CallModule = {
  PyModuleDef_HEAD_INIT, "calls", NULL, -1, callbacksMethods,
  NULL, NULL, NULL, NULL
};

static PyObject* PyInit_calls(void) {
  return PyModule_Create(&CallModule);
}



int main(int argc, char* argv[]) {
  std::cout << "Starting execution\n";

  PyImport_AppendInittab("calls", &PyInit_calls);
  Py_Initialize();
  PyObject* code = Py_CompileString(
      "import time\n"
      "def sayHi():\n"
      "\twith open('test.txt', 'w', encoding='utf-8') as file:\n"
      "\t\tfile.write('Hi!\n')\n"
      "\n"
      "callback = sayHi\n"
      "\n"
      "while True:\n"
      "\tcallback()\n"
      "\ttime.sleep(1)\n",
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
