#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "randomy/randomy.hpp"

#ifdef __cplusplus
extern "C" {
#endif

int randomy_getRandom() {
  return randomy::getRandom();
}

void randomy_printRandom() {
  randomy::printRandom();
}

#ifdef __cplusplus
}
#endif

static PyObject* randomy_getRandom_pyCallback(PyObject* self, PyObject* args) {
  int valueOut;
  valueOut = randomy_getRandom();
  return PyLong_FromLong(valueOut);
}

static PyObject* randomy_printRandom_pyCallback(PyObject* self,
                                                PyObject* args) {
  randomy_printRandom();
  Py_RETURN_NONE;
}

static PyMethodDef callbackMethods[] = {
  {"getRandom", randomy_getRandom_pyCallback,
    METH_VARARGS, "getRandom from randomy Library"},
  {"printRandom", randomy_printRandom_pyCallback,
    METH_VARARGS, "printRandom from randomy Library"},
  {NULL, NULL, 0, NULL}
};

#if PY_MAJOR_VERSION >= 3
/* module initialization */
/* Python version 3*/
static struct PyModuleDef cModPyDem = {
    PyModuleDef_HEAD_INIT,
  "randomy", "Randomy Library",
    -1,
    callbackMethods
};

PyMODINIT_FUNC PyInit_randomy(void) {
  return PyModule_Create(&cModPyDem);
}
#else
/* module initialization */ /* Python version 2 */
PyMODINIT_FUNC initcallback_module(void) {
  (void) Py_InitModule("randomy", callbackMethods);
}
#endif

