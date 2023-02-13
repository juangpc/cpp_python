#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <fstream>
#include <iostream>

void dictParser() {
  std::cout << "Hello from dictParser\n";
}

static PyObject* dict_parser_py(PyObject* self, PyObject* args) {
//parse input args


  dictParser();
  return Py_None;
}

static struct PyMethodDef callbacksMethods[] = {
  {"dict_parser", dict_parser_py, METH_VARARGS, "Parse dictionary"},
  {NULL, NULL, 0, NULL}
};

static PyModuleDef CallModule = {
  PyModuleDef_HEAD_INIT, "parsing", NULL, -1, callbacksMethods,
  NULL, NULL, NULL, NULL
};

static PyObject* PyInit_parsing(void) {
  return PyModule_Create(&CallModule);
}



int main(int argc, char* argv[]) {
  std::cout << "Starting execution\n";

  PyImport_AppendInittab("parsing", &PyInit_parsing);
  Py_Initialize();
  // PyConfig config;
  // PyConfig_InitPythonConfig(&config);
  // config.module_search_paths_set = 1;
  // PyWideStringList_Append(&config.module_search_paths, L".");
  // Py_InitializeFromConfig(&config);

  FILE* py_file;
  if (argc != 2) {
    std::cout << "Usage: ./" << argv[0] << ": main.py\n";
    exit(1);
  }
  py_file = fopen(argv[1], "r");
  PyObject* global_dict = PyDict_New();
  PyObject* local_dict = PyDict_New();
  PyObject* result = PyRun_File(py_file, argv[1], Py_file_input, global_dict, local_dict);
  Py_DECREF(global_dict);
  Py_DECREF(local_dict);
  // Py_DECREF(result);
  fclose(py_file);
  
  Py_Finalize();

  return 0;
}
