# header only files need INTERFACE
add_library(audio_header INTERFACE)
target_include_directories(audio_header INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/audiocomponent.h)

add_library(csd_lib STATIC)
target_compile_features(csd_lib PUBLIC cxx_std_20)
target_include_directories(csd_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/utils
        ${CMAKE_CURRENT_SOURCE_DIR}/effects
        ${CMAKE_CURRENT_SOURCE_DIR}/oscillators
        ${LIBLO_INCLUDE_DIRS}
)

if(MSVC)
    find_package(liblo CONFIG REQUIRED)
else()
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(LIBLO REQUIRED IMPORTED_TARGET liblo)
endif()

if(MSVC)
    target_link_libraries(${libName}
            PRIVATE
            liblo::liblo
            #liblo::liblo_static
            ws2_32
            iphlpapi
            PUBLIC
            audio_header
            juce::juce_audio_basics
            juce::juce_audio_devices
    )
else()
    target_link_libraries(csd_lib
        PRIVATE
            PkgConfig::LIBLO
        PUBLIC
            audio_header
            juce::juce_audio_basics
            juce::juce_audio_devices
    )
endif()


add_subdirectory(effects)
add_subdirectory(oscillators)
add_subdirectory(utils)
