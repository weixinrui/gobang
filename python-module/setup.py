from distutils.core import setup, Extension
pycpp_module = Extension('_gobang',
                           sources=['Gobang.cpp', 'Gobang_wrap.cxx',],
                           )
setup (name = 'gobang',
       version = '0.1',
       author      = "Xinrui Wei",
       description = """Simple swig C\+\+/Python example.""",
       ext_modules = [pycpp_module],
       py_modules = ["gobang"],
       )