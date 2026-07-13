project(
  'projet-commun',
  'c',
  default_options: [
    'c_std=c99',
    'warning_level=3',
  ]
)

includes = [
  include_directories('include')
]

common_sources = files(
  'net/socket_posix.c',
  'net/socket_win32.c'
)

arguments = [
  '-D_POSIX_C_SOURCE=200809L',
  '-DNAME=' + meson.project_name()
]

add_project_arguments(
  arguments,
  language: 'c'
)

if get_option('buildtype') == 'debug'
  add_project_arguments('-DDEBUG', language: 'c')
endif

subdir('server')
subdir('client')
