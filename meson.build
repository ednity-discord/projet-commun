project(
  'projet-commun',
  'c',
  default_options: [
    'c_std=c99',
    'warning_level=3',
  ]
)

dependencies = [
  dependency('threads')
]

includes = [
  include_directories('include')
]

sources = files(
  'source/main.c'
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

executable(
  meson.project_name(),
  sources,
  dependencies: dependencies,
  include_directories: includes
)
