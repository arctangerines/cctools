project(
  'poncho',
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : {
    'warning_level' : '3',
    'prefix' : meson.current_source_dir(),
    },
)

cctools_py3_path = get_option('cctools_py3_path')

# Install directory
configure_file(
  install : true,
  install_dir : get_option('bindir'),
  input : 'poncho_package_analyze',
  output : 'poncho_package_analyze',
  copy : true,
)

configure_file(
  install : true,
  install_dir : get_option('bindir'),
  input : 'poncho_package_create',
  output : 'poncho_package_create',
  copy : true,
)

configure_file(
  install : true,
  install_dir : get_option('bindir'),
  input : 'poncho_package_run',
  output : 'poncho_package_run',
  copy : true,
)

configure_file(
  install : true,
  install_dir : get_option('bindir'),
  input : 'poncho_package_serverize',
  output : 'poncho_package_serverize',
  copy : true,
)

# Install to python3 path
configure_file(
  install : true,
  install_dir : cctools_py3_path / 'ndcctools/poncho',
  input : 'poncho_package_analyze',
  output : 'poncho_package_analyze',
  copy : true,
)

configure_file(
  install : true,
  install_dir : cctools_py3_path / 'ndcctools/poncho',
  input : 'poncho_package_create',
  output : 'poncho_package_create',
  copy : true,
)

configure_file(
  install : true,
  install_dir : cctools_py3_path / 'ndcctools/poncho',
  input : 'poncho_package_run',
  output : 'poncho_package_run',
  copy : true,
)

configure_file(
  install : true,
  install_dir : cctools_py3_path / 'ndcctools/poncho',
  input : 'poncho_package_serverize',
  output : 'poncho_package_serverize',
  copy : true,
)
