"""Module wrapper over Randomy Library"""

from setuptools import setup, Extension

randomy_module=Extension('randomy',
                sources=['randomy_python_bindings.cpp'],
                include_dirs=['../..'],
                library_dirs=['.'],
                extra_objects=['librandomy_release.a'],
                extra_link_args=['-static'],
                language='c++')

setup(name='randomy', ext_modules=[randomy_module])
