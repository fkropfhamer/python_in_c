#define PY_SSIZE_T_CLEAN
#include <Python.h>

int sum(int a, int b) {
  return a + b;
}

static PyObject *helloc_printHello(PyObject *self, PyObject *args)
{
  if (!PyArg_ParseTuple(args, "")) {
    return NULL;
  }
  printf("Hello World from C!\n");
  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject *helloc_sum(PyObject* self, PyObject* args) {
  int a;
  int b;

  if (!PyArg_ParseTuple(args, "ii", &a, &b))
    return NULL;
  return Py_BuildValue("i", sum(a,b));
}

static PyMethodDef hellocMethods[] = {
  { "printHello", helloc_printHello, METH_VARARGS, "Prints Hello World" }, {"sum", helloc_sum, METH_VARARGS, "sums two ints"}, {NULL, NULL, 0, NULL},
};

//void inithelloc(void)
//{
//  Py_InitModule("helloc", hellocMethods);
//}

static struct PyModuleDef helloc = {
  PyModuleDef_HEAD_INIT,
  "helloc",
  "",
  -1,
  hellocMethods
};

PyMODINIT_FUNC PyInit_helloc(void)
{
  return PyModule_Create(&helloc);
}


