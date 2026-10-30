project('libdttools',
        'c',
        default_options: {
          'warning_level' : '3',
          'prefix' : meson.current_source_dir(),
          },
        )

dttools_srcs = [
    'address.c',
    'auth.c',
    'auth_address.c',
    'auth_all.c',
    'auth_globus.c',
    'auth_hostname.c',
    'auth_kerberos.c',
    'auth_ticket.c',
    'auth_unix.c',
    'b64.c',
    'bucketing.c',
    'bucketing_exhaust.c',
    'bucketing_greedy.c',
    'bucketing_quantized.c',
    'bucketing_det_exhaust.c',
    'bucketing_det_greedy.c',
    'bucketing_exhaust_common.c',
    'bucketing_greedy_common.c',
    'bucketing_manager.c',
    'buffer.c',
    'catalog_query.c',
    'category.c',
    'cctools.c',
    'cctools_endian.c',
    'change_process_title.c',
    'chunk.c',
    'clean_dir.c',
    'compat-at.c',
    'console_login.c',
    'copy_stream.c',
    'copy_tree.c',
    'create_dir.c',
    'daemon.c',
    'datagram.c',
    'debug.c',
    'debug_file.c',
    'debug_journal.c',
    'debug_stream.c',
    'debug_syslog.c',
    'disk_alloc.c',
    'domain_name.c',
    'domain_name_cache.c',
    'dpopen.c',
    'elfheader.c',
    'envtools.c',
    'fast_popen.c',
    'fd.c',
    'file_cache.c',
    'file_link_recursive.c',
    'full_io.c',
    'get_canonical_path.c',
    'get_line.c',
    'getopt_aux.c',
    'gpu_info.c',
    'hash_cache.c',
    'hash_table.c',
    'hdfs_library.c',
    'histogram.c',
    'hmac.c',
    'host_disk_info.c',
    'host_memory_info.c',
    'http_query.c',
    'interfaces_address.c',
    'itable.c',
    'jx.c',
    'jx_binary.c',
    'jx_getopt.c',
    'jx_match.c',
    'jx_parse.c',
    'jx_print.c',
    'jx_pretty_print.c',
    'jx_canonicalize.c',
    'jx_table.c',
    'jx_eval.c',
    'jx_sub.c',
    'jx_function.c',
    'link.c',
    'link_auth.c',
    'list.c',
    'load_average.c',
    'md5.c',
    'memfdexe.c',
    'mkdir_recursive.c',
    'twister.c',
    'nvpair.c',
    'nvpair_jx.c',
    'password_cache.c',
    'path.c',
    'path_disk_size_info.c',
    'pattern.c',
    'ppoll_compat.c',
    'preadwrite.c',
    'priority_queue.c',
    'priority_queue_test.c',
    'process.c',
    'progress_bar.c',
    'progress_bar_test.c',
    'random.c',
    'rmonitor.c',
    'rmonitor_poll.c',
    'rmsummary.c',
    'set.c',
    'semaphore.c',
    'sha1.c',
    'shell.c',
    'sh_popen.c',
    'sigdef.c',
    'skip_list.c',
    'sleeptools.c',
    'sort_dir.c',
    'stats.c',
    'string_array.c',
    'stringtools.c',
    'string_set.c',
    'text_array.c',
    'text_list.c',
    'timer.c',
    'timestamp.c',
    'tlq_config.c',
    'trash.c',
    'unlink_recursive.c',
    'uptime.c',
    'url_encode.c',
    'username.c',
    'uuid.c',
    'xpu_tracker.c',
    'xxmalloc.c']

cctools_base_ccflags = get_option('cctools_base_ccflags_opt')
if cctools_base_ccflags.length() > 1 
  message('Found CCTools Base CC Flags')
  add_project_arguments(cctools_base_ccflags, language: 'c')
endif

cctools_internal_ccflags = get_option('cctools_internal_ccflags_opt')
if cctools_internal_ccflags.length() > 1
  message('Found CCTools Internal CC Flags')
  add_project_arguments(cctools_internal_ccflags, language: 'c')
endif

# Instead of doing manual includes through include_directories()
# we use subprojects

batch_job_proj = subproject('batch_job')
batch_job_dep = batch_job_proj.get_variable('batch_job_dep')

taskvine_proj = subproject('taskvine')
taskvine_dep = taskvine_proj.get_variable('taskvine_dep')

grow_proj = subproject('grow')
grow_dep = grow_proj.get_variable('grow_dep')

makeflow_proj = subproject('makeflow')
makeflow_dep = makeflow_proj.get_variable('makeflow_dep')

work_queue_proj = subproject('work_queue')
work_queue_dep = work_queue_proj.get_variable('work_queue_dep')

ftp_lite_proj = subproject('ftp_lite')
ftp_lite_dep = ftp_lite_proj.get_variable('ftp_lite_dep')

parrot_proj = subproject('parrot')
parrot_dep = parrot_proj.get_variable('parrot_dep')

resource_monitor_proj = subproject('resource_monitor')
resource_monitor_dep = resource_monitor_proj.get_variable('resource_monitor_dep')

chirp_proj = subproject('chirp')
chirp_dep = chirp_proj.get_variable('chirp_dep')

deltadb_proj = subproject('deltadb')
deltadb_dep = deltadb_proj.get_variable('deltadb_dep')

poncho_proj = subproject('poncho')
poncho_dep = poncho_proj.get_variable('poncho_dep')

# cctools_project_dirs = get_option('cctools_project_dirs_opt')
# include_directories(cctools_project_dirs)

static_library('dttools', sources: dttools_srcs, dependencies: [
  deltadb_dep,
  batch_job_dep,
  chirp_dep,
  ftp_lite_dep,
  grow_dep,
  makeflow_dep,
  parrot_dep,
  poncho_dep,
  resource_monitor_dep,
  taskvine_dep,
  work_queue_dep,
  ])
