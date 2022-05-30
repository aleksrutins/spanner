project('spanner', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])

exe = executable('spanner', 'spanner.cpp',
  dependencies : [ dependency('lua-5.4') ],
  install : true)

test('basic', exe)
