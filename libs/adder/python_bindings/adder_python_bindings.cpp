#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "adder/adder.hpp"

extern "C" {
int adder_add2(int a) {
  return adder::add2(a);
}

int adder_add3(int a) {
  return adder::add3(a);
}

int adder_add4(int a) {
  return adder::add4(a);
}
}

static PyObject* adder_add2_pyCallback(PyObject* self, PyObject* args) {
  int valueIn, valueOut;
  if (!PyArg_ParseTuple(args, "i", &valueIn))
    return NULL;
  valueOut = adder_add2(valueIn);
  return PyLong_FromLong(valueOut);
}

static PyObject* adder_add3_pyCallback(PyObject* self, PyObject* args) {
  int valueIn, valueOut;
  if (!PyArg_ParseTuple(args, "i", &valueIn))
    return NULL;
  valueOut = adder_add3(valueIn);
  return PyLong_FromLong(valueOut);
}

static PyObject* adder_add4_pyCallback(PyObject* self, PyObject* args) {
  int valueIn, valueOut;
  if (!PyArg_ParseTuple(args, "i", &valueIn))
    return NULL;
  valueOut = adder_add4(valueIn);
  return PyLong_FromLong(valueOut);
}

static PyMethodDef callbackMethods[] = {
  {"add2", adder_add2_pyCallback, METH_VARARGS, "add 2 to the input"},
  {"add3", adder_add3_pyCallback, METH_VARARGS, "add 3 to the input"},
  {"add4", adder_add4_pyCallback, METH_VARARGS, "add 4 to the input"},
  {NULL, NULL, 0, NULL}
};

#if PY_MAJOR_VERSION >= 3
/* module initialization */
/* Python version 3*/
static struct PyModuleDef cModPyDem = {
    PyModuleDef_HEAD_INIT,
    "adder", "Adder Library",
    -1,
    callbackMethods
};

PyMODINIT_FUNC PyInit_callback_module(void) {
  return PyModule_Create(&cModPyDem);
}
#else
/* module initialization */ /* Python version 2 */
PyMODINIT_FUNC initcallback_module(void) {
  (void) Py_InitModule("adder", callbackMethods);
}
#endif

