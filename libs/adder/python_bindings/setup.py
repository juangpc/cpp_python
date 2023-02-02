"""Module wrapper over Adder Library"""

from setuptools import setup, Extension

adder=Extension('adder',
                sources=['adder_python_bindings.cpp'],
                include_dirs=['../..'],
                library_dirs=['.'],
                extra_objects=['libadder.a'],
                extra_link_args=['-static'],
                language='c++')

setup(name='adder',
      ext_modules=[adder])
