#define PY_SSIZE_T_CLEAN
#include <Python.h>

int sumTwo(int a, int b) {
  return a + b;
}

static PyObject* sumTwo_PyInt(PyObject* self, PyObject* args) {
  int a, b;
  if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
    return NULL;
  }

  int result = sumTwo(a, b);
  return PyLong_FromLong(result);
}

int multiplyTwo(int a, int b) {
  return a * b;
}

static PyObject* multiplyTwo_PyInt(PyObject* self, PyObject* args) {
  int a, b;
  if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
    return NULL;
  }

  int result = multiplyTwo(a, b);
  return PyLong_FromLong(result);
}

static struct PyMethodDef ArithMethods[] = {
  {"sumTwo", sumTwo_PyInt, METH_VARARGS, "Sum two integers."},
  {"multiplyTwo", multiplyTwo_PyInt, METH_VARARGS, "Multiply two integers."},
  {NULL, NULL, 0, NULL}
};

static PyModuleDef ArithModule = {
  PyModuleDef_HEAD_INIT, "arith", NULL, -1, ArithMethods,
  NULL, NULL, NULL, NULL
};

static PyObject* PyInit_arith(void) {
  return PyModule_Create(&ArithModule);
}


int main(int argc, char* argv[]) {
  PyObject *pName, *pModule, *pFunc;
  PyObject *pArgs, *pValue;
  int i;

  if (argc < 3) {
    fprintf(stderr, "Usage: call pythonfile funcname [args]\n");
    return 1;
  }

  PyImport_AppendInittab("arith", &PyInit_arith);

  Py_Initialize();
  pName = PyUnicode_DecodeFSDefault(argv[1]);
  /* Error checking of pName left out */

  pModule = PyImport_Import(pName);
  Py_DECREF(pName);

  if (pModule != NULL) {
    pFunc = PyObject_GetAttrString(pModule, argv[2]);
    /* pFunc is a new reference */

    if (pFunc && PyCallable_Check(pFunc)) {
      pArgs = PyTuple_New(argc - 3);
      for (i = 0; i < argc - 3; ++i) {
        pValue = PyLong_FromLong(atoi(argv[i + 3]));
        if (!pValue) {
          Py_DECREF(pArgs);
          Py_DECREF(pModule);
          fprintf(stderr, "Cannot convert argument\n");
          return 1;
        }
        /* pValue reference stolen here: */
        PyTuple_SetItem(pArgs, i, pValue);
      }
      pValue = PyObject_CallObject(pFunc, pArgs);
      Py_DECREF(pArgs);
      if (pValue != NULL) {
        printf("Result of call: %ld\n", PyLong_AsLong(pValue));
        Py_DECREF(pValue);
      } else {
        Py_DECREF(pFunc);
        Py_DECREF(pModule);
        PyErr_Print();
        fprintf(stderr, "Call failed\n");
        return 1;
      }
    } else {
    if (PyErr_Occurred())
      PyErr_Print();
    fprintf(stderr, "Cannot find function \"%s\"\n", argv[2]);
  }
    Py_XDECREF(pFunc);
    Py_DECREF(pModule);
  } else {
  PyErr_Print();
  fprintf(stderr, "Failed to load \"%s\"\n", argv[1]);
  return 1;
}
  if (Py_FinalizeEx() < 0) {
    return 120;
  }
  return 0;
}
