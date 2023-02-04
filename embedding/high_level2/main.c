#define PY_SSIZE_T_CLEAN
#include <Python.h>

int main(int argc, char *argv[]) {
  PyObject *pName = NULL;
  PyObject *pModule = NULL;
  PyObject *pFunc = NULL;
  PyObject *pValue = NULL;

  Py_Initialize();

  PyConfig config;
  PyConfig_InitPythonConfig(&config);
  config.module_search_paths_set = 1;
  PyWideStringList_Append(&config.module_search_paths, L".");
  Py_InitializeFromConfig(&config);

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

  pValue = PyObject_CallNoArgs(pFunc);  // actual call to the fcn

  Py_XDECREF(pValue);
  Py_XDECREF(pFunc);
  Py_XDECREF(pModule);

  Py_Finalize();

  return 0;
}
