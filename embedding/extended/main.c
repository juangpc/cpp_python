#define PY_SSIZE_T_CLEAN
#include <Python.h>

static int numargs = 0;

static PyObject* emb_numargs(PyObject* self, PyObject* args) {
  if (!PyArg_ParseTuple(args, ":numargs"))
    return NULL;
  return PyLong_FromLong(numargs);
}

static PyMethodDef EmbMethods[] = {
  {"numargs", emb_numargs, METH_VARARGS,
    "Return the number of arguments received by the process."},
  {NULL, NULL, 0, NULL}
};

static PyModuleDef EmbModule = {
  PyModuleDef_HEAD_INIT, "emb", NULL, -1, EmbMethods,
  NULL, NULL, NULL, NULL
};

static PyObject* PyInit_emb(void) {
  return PyModule_Create(&EmbModule);
}

int main(int argc, char *argv[]) {
  PyObject *pName = NULL;
  PyObject *pModule = NULL;
  PyObject *pFunc = NULL;
  PyObject *pValue = NULL;

  numargs = argc;
  PyImport_AppendInittab("emb", &PyInit_emb);

  Py_Initialize();

  PyConfig config;
  PyConfig_InitPythonConfig(&config);
  config.module_search_paths_set = 1;
  PyWideStringList_Append(&config.module_search_paths, L".");
  Py_InitializeFromConfig(&config);

  FILE* fp = fopen("main.py", "r");
  PyRun_AnyFile(fp, " ");
  fclose(fp);

  if (argc < 3) {
    printf("Usage: %s module_name function_name.\n", argv[0]);
    exit(1);
  }

  pName = PyUnicode_FromString(argv[1]);
  if (pName == NULL) {
    printf("Problem parsing the module name.\n");
    exit(1);
  }
  pModule = PyImport_Import(pName);
  Py_XDECREF(pName);

  if (pModule == NULL) {
    printf("Problem importing the module.\n");
    exit(1);
  }

  pFunc = PyObject_GetAttrString(pModule, argv[2]);
  if (pFunc == NULL) {
    printf("Function %s in module %s could not be found.\n", argv[2], argv[1]);
    exit(1);
  }
  if (!PyCallable_Check(pFunc)) {
    printf("Function %s is not callable.\n", argv[2]);
    Py_XDECREF(pModule);
    Py_XDECREF(pFunc);
    exit(1);
  }

  printf("Function %s is callable\n", argv[2]);
  pValue = PyObject_CallNoArgs(pFunc);  // actual call to the fcn

  Py_XDECREF(pFunc);
  Py_XDECREF(pModule);
  Py_XDECREF(pValue);

  Py_Finalize();

  return 0;
}
