if( NOT TARGET CoC-Gui )
    get_filename_component( COC-GUI_SOURCE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../src" ABSOLUTE )

    FILE(GLOB COC-GUI_SOURCES ${COC-GUI_SOURCE_PATH}/*.cpp)

    add_library( CoC-Gui ${COC-GUI_SOURCES} )
    target_include_directories( CoC-Gui PUBLIC "${COC-GUI_SOURCE_PATH}" )

    # If Cinder included from this block:

    target_include_directories( CoC-Gui SYSTEM BEFORE PUBLIC "${CINDER_PATH}/include" )

    if( NOT TARGET cinder )
        include( "${CINDER_PATH}/proj/cmake/configure.cmake" )
        find_package( cinder REQUIRED PATHS
                "${CINDER_PATH}/${CINDER_LIB_DIRECTORY}"
                "$ENV{CINDER_PATH}/${CINDER_LIB_DIRECTORY}" )
    endif()

    # Add CoC-Utils block as a dependency
    get_filename_component( COC-UTILS_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../CoC-Utils/proj/cmake" ABSOLUTE )
    find_package( CoC-Utils REQUIRED PATHS "${COC-UTILS_MODULE_PATH}" )
    if (CoC-Utils_FOUND)
        add_dependencies( CoC-Gui CoC-Utils )
        target_link_libraries( CoC-Gui PUBLIC CoC-Utils)
    endif()

    # Add Cinder-ImGui block as a dependency
    get_filename_component( CINDER-IMGUI_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../ImGui/proj/cmake" ABSOLUTE )
    find_package( Cinder-ImGui REQUIRED PATHS "${CINDER-IMGUI_MODULE_PATH}" )
    if (Cinder-ImGui_FOUND)
        add_dependencies( CoC-Gui Cinder-ImGui )
        target_link_libraries( CoC-Gui PUBLIC Cinder-ImGui)
    endif()

    target_link_libraries( CoC-Gui PRIVATE cinder )

endif()