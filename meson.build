project('cctools',
  'c', 'cpp',
  meson_version : '1.12.1',
  version : '8.0.0',
  default_options : {
    'warning_level' : '3',
    'prefix' : meson.current_build_dir(),
    'c_std' : 'c99,c11,c23', # We can set fallback versions
    }
  )

# Used for -DCCTOOLS_SOURCE 
cctools_release = 'DEVELOPMENT'
cctools_version_major = '8'
cctools_version_minor = '0'
cctools_version_micro = '0'
cctools_version = '.'.join(cctools_version_major,cctools_version_minor,cctools_version_micro) + ' ' + cctools_release
message(cctools_version)
message(get_option('c_std'))

#TODO: Set c99

cctools_prefix = get_option('prefix')

py3_version = import('python').find_installation('python3').language_version()
cctools_py3_path = get_option('prefix') / 'lib/python'+py3_version
message(cctools_py3_path)

# We do not need to add $CFLAGS as meson already uses it

cctools_internal_ccflags = [
  #### Set by an option
  '-DCCTOOLS_WITH_CHIRP',
  ]
# Originally there was a c only flag
# NOTE: In the subprojects it is currently using "add_project_arguments()",
#       perhaps this can be moved over to the main meson (here) and use
#       add_global_arguments() instead
cctools_base_ccflags = [ 
  #### Hardcoded
  '-D__EXTENSIONS__',
  '-D_LARGEFILE64_SOURCE',
  '-D__LARGE64_FILES',
  '-Wall',
  '-Wextra',
  '-Wno-unused-result',
  '-fPIC',
  #### Obtained by using 'check_compiler_flag' (in helper shell script)
  '-Wno-unused-parameter',
  '-Wno-unknown-pragmas',
  '-Wno-deprecated-declarations',
  '-Wno-unused-const-variable',
  #### The following definitions are obtained by using library search 
  ####(optinal_function in configure.tools.sh)
  #### We can perform the searching with compiler.has_header_symbol()
  '-DHAS_LIBREADLINE',
  # Obtained by using 'optional_function' found in the helper configure sh script
  '-DHAS_TLS_method', # searches for TL_method
  '-DHAS_OPENSSL', # searches for openssl/ssl.h
  '-DHAS_OPENSSL_PKEYUTL', # uses the openssl command line, defaults to RSAUTL if not found
  '-DHAS_PPOLL', # searches for ppoll and poll.h
  '-DHAVE_GMTIME_R', # searches for gmtime_r on header time.h    
  '-DHAVE_FDATASYNC', # searches for fdatasync on header unistd.h  
  # searches for isnan on header math.h    
  '-DHAS_ISNAN',
  '-DHAVE_ISNAN',
  '-DSQLITE_HAVE_ISNAN',
  '-DHAVE_LOCALTIME_R', # searches for localtime_r on header time.h    
  '-DHAVE_LOCALTIME_S', # searches for localtime_s on header time.h    
  '-DHAS_OPENAT', # searches for openat on header fcntl.h   
  # searches for pread on header unistd.h  
  '-DHAS_PREAD',
  '-DUSE_PREAD',

  '-DUSE_PREAD64', # searches for pread64 on header unistd.h  
  '-DHAS_PWRITE',
  '-DUSE_PWRITE', # searches for pwrite on header unistd.h  
  '-DUSE_PWRITE64', # searches for pwrite64 on header unistd.h  
  '-DHAS_STATX', # searches for statx on header sys/stat.h
  '-DHAVE_STRCHRNUL', # searches for strchrnul on header string.h  
  '-DHAS_STRSIGNAL', # searches for strsignal on header string.h  

  # searches for usleep on header unistd.h  
  '-DHAS_USLEEP',
  '-DHAVE_USLEEP',
  # searches for utime on header utime.h   
  '-DHAS_UTIME',
  '-DHAVE_UTIME',

  '-DHAS_UTIMENSAT', # searches for utimensat on header sys/stat.h


#### These ones search for header only
  #### Can be substituted by compiler.has_header()
  '-DHAS_ATTR_XATTR_H', # searches for header attr/xattr.h 
  '-DHAS_SYS_XATTR_H', # searches for header sys/xattr.h  
  '-DHAS_IFADDRS', # searches for header ifaddrs.h    

  # searches for header inttypes.h   
  '-DHAS_INTTYPES_H',
  '-DHAVE_INTTYPES_H',
  # searches for header stdint.h     
  '-DHAS_STDINT_H',
  '-DHAVE_STDINT_H',

  '-DHAS_SYS_STATFS_H', # searches for header sys/statfs.h 
  '-DHAS_SYS_STATVFS_H', # searches for header sys/statvfs.h
  '-DHAS_SYS_VFS_H', # searches for header sys/vfs.h    

  #### These ones are hardcoded and related to the build
    ### This one we need to create a conditional of sorts

  # Currently undefined 
  # FIXME: The ways to get these are currently undefined
  # NOTE: The formatting on these quotes is different from the makefile implementation
  #       On there the command ran would be, for example,
  #           gcc -DCCTOOLS_COMMIT='"ABC"',
  #       but the way we are writing it the command would be
  #           gcc '-DCCTOOLS_COMMIT="ABC"',
  #       it seems this meson version works fine
  #       Not only that but if we define this on here like this:
  #           '-DCCTOOLS_COMMIT='"ABC"'
  #       it will be replaced with the following when executing the command
  #           '-DCCTOOLS_COMMIT='"'"'"ABC"'"'"''
  '-DCCTOOLS_COMMIT=""',
  '-DCCTOOLS_CONFIGURE_ARGUMENTS=""', # Requires some escaping the output of makefile
  # FIXME: Pending options in configure script/meson_options
  '-DCCTOOLS_CVMFS_BUILD_FLAGS=""',

     '-D_GNU_SOURCE',
     '-D_REENTRANT',
  ]
# Debugging flag should be set directly by meson

getdate_cmd = run_command('date', '+%Y-%m-%d %H:%M:%S %z', check: true)
getdate_out = getdate_cmd.stdout().strip()
getdate_def = '-DBUILD_DATE=' + '"' + getdate_out + '"'
cctools_base_ccflags += getdate_def
## Perhaps will need some changing
getreldate_def = '-DCCTOOLS_RELEASE_DATE=' + '"' + getdate_out + '"'
cctools_base_ccflags += getreldate_def 

gethost_cmd = run_command('uname', '-n', check: true)
gethost_out = gethost_cmd.stdout().strip()
gethost_def = '-DBUILD_HOST='+ '"' + gethost_out + '"'
cctools_base_ccflags += gethost_def

#'-DBUILD_USER=', # BUILD_USER="$USER"
# AFAIK meson doesnt have a way to get environment variables
getuser_cmd = run_command('sh', '-c', 'echo $USER', check: true)
getuser_out = getuser_cmd.stdout().strip() 
getuser_def = '-DBUILD_USER=' + '"' + getuser_out + '"'
cctools_base_ccflags += getuser_def

getopsys_cmd = run_command('sh', '-c', 'uname -s | tr \[a-z\] \[A-Z\] | awk -F_ \'{print $1}\'', check: true)
getopsys_out = getopsys_cmd.stdout().strip()
getopsys_def = '-DCCTOOLS_OPSYS_' + getopsys_out
cctools_base_ccflags += getopsys_def
#'-DCCTOOLS_OPSYS_${BUILD_SYS}', # BUILD_SYS="$()"

getcpu_cmd = run_command('sh', '-c', 'uname -m | tr \[a-z\] \[A-Z\]')
getcpu_out = getcpu_cmd.stdout().strip()
getcpu_def = '-DCCTOOLS_CPU_' + getcpu_out
cctools_base_ccflags += getcpu_def

# NOTE: Having this on a hardcoded flag seems excessive
getsysinfo_cmd = run_command('sh', '-c', 'uname -a | sed s/#/\\#/ | sed s/\$/$$/', check: true)
getsysinfo_out = getsysinfo_cmd.stdout().strip()
getsysinfo_def = '-DCCTOOLS_SYSTEM_INFORMATION=' + '"' + getsysinfo_out + '"'
cctools_base_ccflags += getsysinfo_def

cctools_base_ccflags += '-DCCTOOLS_SOURCE=' + '"' + cctools_release + '"'


cctools_base_ccflags += '-DCCTOOLS_VERSION=' + '"' + cctools_version + '"'
cctools_base_ccflags += '-DCCTOOLS_VERSION_MAJOR=' + cctools_version_major
cctools_base_ccflags += '-DCCTOOLS_VERSION_MINOR=' + cctools_version_minor
cctools_base_ccflags += '-DCCTOOLS_VERSION_MICRO=' + cctools_version_micro
cctools_base_ccflags += '-DINSTALL_PATH=' + '"' + cctools_prefix + '"'

message(cctools_base_ccflags)


cctools_project_dirs = [
  #### Hardcoded
  '../../dttools/src',
  '../../batch_job/src',
  '../../taskvine/src',
  '../../grow/src',
  '../../makeflow/src',
  '../../work_queue/src',
  '../../ftp_lite/src',
  '../../parrot/src',
  '../../resource_monitor/src',
  '../../chirp/src',
  '../../deltadb/src',
  '../../poncho/src',
  ]


batch_job = subproject('batch_job')
chirp = subproject('chirp')
deltadb = subproject('deltadb')

dttools = subproject('dttools',
  default_options : {
    'prefix' : cctools_prefix,
    'cctools_base_ccflags_opt' : cctools_base_ccflags,
    'cctools_internal_ccflags_opt' : cctools_internal_ccflags,
    }
  )

ftp_lite = subproject('ftp_lite')
grow = subproject('grow')
makeflow = subproject('makeflow')
parrot = subproject('parrot')

poncho = subproject('poncho',
  default_options : {
    'cctools_py3_path' : cctools_py3_path,
    'prefix' : cctools_prefix,
    }
  )

resource_monitor = subproject('resource_monitor')
taskvine = subproject('taskvine')
work_queue = subproject('work_queue')



