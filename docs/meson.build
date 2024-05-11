# new configuration data object
cdata = configuration_data()

# set parameters for cdata object
cdata.set('PROJECT_NAME', meson.project_name())
cdata.set('VERSION', meson.project_version())
cdata.set('SOURCE_DIR', meson.project_source_root()+'/core')
cdata.set('OUTPUT_DIR', join_paths(meson.project_build_root(),'docs'))
cdata.set('README_PATH', join_paths(meson.project_source_root(),'README.md'))

dot = find_program('dot',
  required : get_option('enable_graphs'))

if dot.found()
  message('Configuring Doxygen with Dot')
  cdata.set('HAVE_DOT', 'YES')
  cdata.set('DOT_PATH', dot.full_path())
else
  warning('Dot not found, doxygen wont generate graphs')
  cdata.set('HAVE_DOT', 'NO')
endif

doxyfile = configure_file(
  input: 'Doxyfile.in',
  output: 'Doxyfile',
  configuration: cdata,
  install: false
)

doxygen = find_program('doxygen')

doc_target = run_target('docs', command: [doxygen, doxyfile])
