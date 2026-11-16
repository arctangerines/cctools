project(
  'taskvine',
  'c',
  meson_version : '>= 1.12.0',
  default_options : {
  'warning_level' : '3',
  'prefix' : meson.current_build_dir(),
  },
)

# TODO: Targets
# - [] manager?

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

cctools_include_dirs = get_option('cctools_include_dirs_opt')

taskvine_manager_src = [
  'manager/vine_manager.c',
  'manager/vine_manager_get.c',
  'manager/vine_manager_put.c',
  'manager/vine_manager_factory.c',
  'manager/vine_manager_summarize.c',
  'manager/vine_schedule.c',
  'manager/vine_worker_info.c',
  'manager/vine_catalog.c',
  'manager/vine_counters.c',
  'manager/vine_resources.c',
  'manager/vine_task.c',
  'manager/vine_file.c',
  'manager/vine_mount.c',
  'manager/vine_txn_log.c',
  'manager/vine_taskgraph_log.c',
  'manager/vine_cached_name.c',
  'manager/vine_checksum.c',
  'manager/vine_perf_log.c',
  'manager/vine_file_replica.c',
  'manager/vine_factory_info.c',
  'manager/vine_task_info.c',
  'manager/vine_blocklist.c',
  'manager/vine_current_transfers.c',
  'manager/vine_file_replica_table.c',
  'manager/vine_fair.c',
  'manager/vine_runtime_dir.c',
  'manager/vine_task_groups.c',
  'manager/vine_temp.c',
  ]

taskvine_worker_src = [
  'worker/vine_cache.c',
  'worker/vine_cache_file.c',
  'worker/vine_cache_file.h',
  'worker/vine_cache.h',
  'worker/vine_process.c',
  'worker/vine_process.h',
  'worker/vine_sandbox.c',
  'worker/vine_sandbox.h',
  'worker/vine_transfer.c',
  'worker/vine_transfer.h',
  'worker/vine_transfer_server.c',
  'worker/vine_transfer_server.h',
  'worker/vine_watcher.c',
  'worker/vine_watcher.h',
  'worker/vine_worker.c',
  'worker/vine_worker.h',
  'worker/vine_worker_options.c',
  'worker/vine_worker_options.h',
  'worker/vine_workspace.c',
  'worker/vine_workspace.h',
  ]


common_link_args = ['-lssl',
                    '-lcrypto',
                    '-lresolv',
                    '-lrt',
                    '-ldl',
                    '-lz',
                    '-lstdc++',
                    '-lpthread',
                    '-lz',
                    '-lc',
                    '-lm',
                 ]

exe_link_args = common_link_args + ['-Xlinker', 
                 '-Bstatic', 
                 '-Xlinker', '-Bdynamic', 
                 # '-Xlinker', '--as-needed', # Already included
                 '-Wl,--no-warn-search-mismatch']

libtaskvine = static_library('taskvine', sources: taskvine_manager_src, 
  include_directories: cctools_include_dirs,
  install: true, #required to avoid thin archives
  )


dttools_proj = subproject('dttools')
libdttools = dttools_proj.get_variable('libdttools')

executable('vine_worker', sources: taskvine_worker_src,
  include_directories: cctools_include_dirs,
  link_args : exe_link_args,
  link_with : [libtaskvine, libdttools]
  )


# For the swig portion of taskvine we could use meson generators
