#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "calls/calls.hpp"

#ifdef __cplusplus
extern "C" {
#endif

void calls_callback1(int a) {
  calls::callback1(a);
}

void calls_callback2(int a) {
  calls::callback2(a);
}

void calls_callback3(int a) {
  calls::callback3(a);
}

#ifdef __cplusplus
}
#endif

static PyObject* calls_callback1_pyCallback(PyObject* self, PyObject* args) {
  int valueIn;
  if (!PyArg_ParseTuple(args, "i", &valueIn))
    return NULL;
  calls_callback1(valueIn);
  Py_RETURN_NONE;
}

static PyObject* calls_callback2_pyCallback(PyObject* self, PyObject* args) {
  int valueIn;
  if (!PyArg_ParseTuple(args, "i", &valueIn))
    return NULL;
  calls_callback2(valueIn);
  Py_RETURN_NONE;
}

static PyObject* calls_callback3_pyCallback(PyObject* self, PyObject* args) {
  int valueIn;
  if (!PyArg_ParseTuple(args, "i", &valueIn))
    return NULL;
  calls_callback3(valueIn);
  Py_RETURN_NONE;
}

static PyMethodDef callbackMethods[] = {
  {"callback1", calls_callback1_pyCallback,
    METH_VARARGS, "Callback1 from Calls Library"},
  {"callback2", calls_callback2_pyCallback,
    METH_VARARGS, "Callback2 from Calls Library"},
  {"callback3", calls_callback3_pyCallback,
    METH_VARARGS, "Callback3 from Calls Library"},
  {NULL, NULL, 0, NULL}
};

#if PY_MAJOR_VERSION >= 3
/* module initialization */
/* Python version 3*/
static struct PyModuleDef cModPyDem = {
    PyModuleDef_HEAD_INIT,
  "calls", "Calls Library",
    -1,
    callbackMethods
};

PyMODINIT_FUNC PyInit_calls(void) {
  return PyModule_Create(&cModPyDem);
}
#else
/* module initialization */ /* Python version 2 */
PyMODINIT_FUNC initcallback_module(void) {
  (void) Py_InitModule("calls", callbackMethods);
}
#endif

