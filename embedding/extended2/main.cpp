#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <iostream>
#include <string>
#include "App.hpp"

static PyObject* callback1(PyObject* self, PyObject* args) {
}

int main(int argc, char* argv[]) {
  App app;
  return app.getReturnValue();
}
