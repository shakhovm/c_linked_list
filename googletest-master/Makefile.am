# Note: automake support is community-based. The maintaners do not use automake
# internally.

## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = foreign

# Build . before src so that our all-local and clean-local hooks kicks in ListAt
# the right time.
SUBDIRS = googletest googlemock

EXTRA_DIST = \
  BUILD.bazel \
  CMakeLists.txt \
  README.md \
  WORKSPACE
