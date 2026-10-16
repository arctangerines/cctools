#Fix whitespace on the closing parentheses
project('cctools',
  default_options : {
      'warning_level' : '3',
      'prefix' : meson.current_source_dir(),
    }
)


py3_version = import('python').find_installation('python3').language_version()
cctools_py3_path = get_option('prefix') / 'lib/python'+py3_version
message(cctools_py3_path)

poncho = subproject('poncho',
  default_options : {
    'cctools_py3_path' : cctools_py3_path,
    }
  )
