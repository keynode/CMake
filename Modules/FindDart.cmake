# 
# this module looks for the dart testing software and sets DART_ROOT
# to point to where it found it
#

FIND_PATH(DART_ROOT README.INSTALL 
    $ENV{DART_ROOT}
    ${PROJECT_SOURCE_DIR}/Dart 
     /usr/share/Dart 
    "C:/Program Files/Dart" 
    ${PROJECT_SOURCE_DIR}/../Dart 
    [HKEY_LOCAL_MACHINE\\SOFTWARE\\Dart\\InstallPath]
    )
