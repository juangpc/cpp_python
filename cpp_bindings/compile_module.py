"""Module providing the capacity to build a wrapper over Calls C++ library.

By default, python will want dynamic libraries. but we can have
static linking to a code with "extra objects" and "extra link args" arguments.

python compile_module_pycall.py build
python compile_module_pycall.py install

-------
The module can be compiled with an independent compiler, but you need to know
which flags are needed during compilation and which during linking in order
to work properly.

pythonX.Y-config --cflags will give you the recommended flags when compiling
pythonX.Y-config --ldflags --embed for linking

This is where we can get information from when deciding on the flags.
Once we get these flags going, we'll be able to compile with any compiler.

"""

from setuptools import setup, Extension

pycalls = Extension('pycalls',
                    sources=['pycals.cpp'],
                    libaries=['libcalls.a'],
                    include_dirs=['../../out/lib/calls/include',
                                  '/opt/anaconda3/include/python3.9'],
                    library_dirs=['../../out/lib/calls'],
                    extra_objects=['libcalls.a'],
                    extra_link_args=['-static'],
                    language='c++'
                    )

setup(name='pycalls',
      ext_modules=[pycalls])
