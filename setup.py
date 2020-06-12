from distutils.core import setup, Extension

setup(name = "helloc", version = 1.0,
  ext_modules = [Extension("helloc", ["helloc.c"])]
)

