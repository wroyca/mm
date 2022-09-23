project(     'mm', 'c', 'cpp',
          version: '4.8.0',
          license: 'LGPLv2.1+',
  default_options: [ 'cpp_std=c++20', 'warning_level=1' ],
    meson_version: '>= 0.63.0', # required for executable(win_subsystem:)
)

mm_version_array = meson.project_version().split('.')
mm_major_version = mm_version_array[0].to_int()
mm_minor_version = mm_version_array[1].to_int()
mm_micro_version = mm_version_array[2].to_int()

c_compiler = meson.get_compiler('c')
cpp_compiler = meson.get_compiler('cpp')

subdir('mm/glib')
subdir('mm/gio')
#subdir('mm-gtk')
