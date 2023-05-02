#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "funcs.h"

static PyObject* callback1_py(PyObject* self, PyObject* args);

static PyObject* callback2_py(PyObject* self, PyObject* args); 

static struct PyMethodDef callbacksMethods[] = {
  {"callback1", callback1_py, METH_VARARGS, "Call to callback1"},
  {"callback2", callback2_py, METH_VARARGS, "Call to callback2"},
  {NULL, NULL, 0, NULL}
};

static PyModuleDef CallModule = {
  PyModuleDef_HEAD_INIT, "calls", NULL, -1, callbacksMethods,
  NULL, NULL, NULL, NULL
};

static PyObject* PyInit_calls(void);





// Import the callback_module Python module
PyObject* pModule = PyImport_ImportModule("callback_module");
if (pModule == NULL) {
  PyErr_Print();
  return 1;
}

// Get a reference to the start function
PyObject* pStartFunc = PyObject_GetAttrString(pModule, "start");
if (pStartFunc == NULL) {
  PyErr_Print();
  Py_DECREF(pModule);
  return 1;
}

// Call the start function
PyObject* pResult = PyObject_CallObject(pStartFunc, NULL);
if (pResult == NULL) {
  PyErr_Print();
  Py_DECREF(pModule);
  Py_DECREF(pStartFunc);
  return 1;
}

// Cleanup
Py_DECREF(pModule);
Py_DECREF(pStartFunc);
Py_DECREF(pResult);




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
