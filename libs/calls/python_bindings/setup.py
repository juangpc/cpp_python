"""Module wrapper over Calls Library"""

from setuptools import setup, Extension

calls_module=Extension('calls',
                sources=['calls_python_bindings.cpp'],
                include_dirs=['../..'],
                library_dirs=['.'],
                extra_objects=['libcalls_release.a'],
                extra_link_args=['-static'],
                language='c++')

setup(name='calls', ext_modules=[calls_module])
